/*
   This is an example shown by Dr. Iral Pohl.
*/

#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

enum class suit: short{SPADE, HEART, DIAMOND, CLUB};
ostream& operator<<(ostream&out, const suit& s){
            switch (s){
                case suit::SPADE: out<<"SPADE"; break;
                case suit::HEART: out<<"HEART"; break;
                case suit::DIAMOND: out<<"DIAMOND"; break;
                case suit::CLUB: out<<"CLUB"; break;
            }
            return out;
        }

// a king=13, Queen=12, etc
class pips{
public:
	pips(int val): v(val){assert (v > 0 && v < 14);}
	friend ostream& operator<<(ostream& out, const pips& p);
	int get_pips(){return v;}
private:
	int v;
};
ostream& operator<<(ostream&out,const pips&p){
    out<<p.v;
    return out;
}


// card
class card
{
public:
  card(): s(suit::SPADE), v(1){} // constructor for class card
  card(suit s, pips v):s(s),v(v){}
  
  friend ostream& operator<<(ostream& out, const card& c);

  suit get_suit(){return s;}
  pips get_pips(){return v;}

private:
	suit s;
	pips v;
};

// Friend function
ostream& operator<<(ostream& out, const card& c)
{
   cout << c.v << c.s; //presumes << overloaded for pips and suit
   return out;
}

// Do a vector of cards
void init_deck(vector<card> &d)
{
	for (int i=1; i<14; ++i){
		card c(suit::SPADE, i);
		d[i-1] = c;
	}
   
   for (int i=1; i<14; ++i){
		card c(suit::HEART, i);
		d[i+12] = c;
	}

	for (int i=1; i<14; ++i){
		card c(suit::DIAMOND, i);
		d[i+25] = c;
	}

	for (int i=1; i<14; ++i){
		card c(suit::CLUB, i);
		d[i+38] = c;
	}
}

// C++11 auto feature
void print(vector <card> & deck)
{
	for(auto p = deck.begin(); p!=deck.end(); ++p)
		cout << *p;
	cout << endl;
}

// Flush
bool is_flush(vector <card> &hand)
{
	suit s = hand[0].get_suit();
	for(auto p = hand.begin()+1; p!=hand.end(); ++p)
		if (s != p->get_suit())
			return false;
	return true;
}

// Straight
bool is_straight(vector <card> &hand)
{
	int pips_v[5], i = 0;

	for(auto p = hand.begin(); p!=hand.end(); ++p)
		pips_v[i++] = (p->get_pips()).get_pips();

   sort(pips_v, pips_v + 5); // STL iterator range

	if (pips_v[0] != 1) // non-aces
		return (pips_v[0] == pips_v[1]-1 && pips_v[1] == pips_v[2]-1 
			     && pips_v[2] == pips_v[3]-1 && pips_v[3] == pips_v[4]-1);
	else // aces have a special logic
	   return ((pips_v[0] == pips_v[1]-1 && pips_v[1] == pips_v[2]-1 && 
	   	      pips_v[2] == pips_v[3]-1 && pips_v[3] == pips_v[4]-1)
	           || (pips_v[1] == 10 && pips_v[2] == 11 && 
	   	      pips_v[3] == 12 && pips_v[4] == 13));

}

// Straight flush
bool is_straight_flush(vector <card> &hand)
{
	return is_flush(hand) && is_straight(hand);
}

// Exercise - implement is_4of_akind
bool is_4of_akind(vector<card>& hand) {
	return hand[0].get_pips().get_pips() == hand[1].get_pips().get_pips()
		&& hand[1].get_pips().get_pips() == hand[2].get_pips().get_pips()
		&& hand[2].get_pips().get_pips() == hand[3].get_pips().get_pips()
		&& hand[3].get_pips().get_pips() == hand[4].get_pips().get_pips();
}


int main()
{   
	vector<card> deck(52); 
   
   srand(time(0));
   init_deck(deck);
   int how_many;
   int flush_count = 0;
   int str_count = 0;
   int str_flush_count = 0;


	cout << "How many shuffles?";
	cin >> how_many;

	for (int loop=0; loop<how_many; ++loop){

		random_shuffle(deck.begin(), deck.end()); // STL algorithm
		vector <card> hand(5);
		int i = 0;

		for(auto p=deck.begin(); i<5; ++p)
			hand[i++] = *p;

	   if (is_flush(hand))
	   	flush_count++;

	   if (is_straight(hand))
		   str_count++;

	   if (is_straight_flush(hand))
		   str_flush_count++;
	}

   cout << "Flush" << flush_count << "out of" << how_many << endl;
   cout << "Straight" << str_count << "out of" << how_many << endl;
   cout << "Straight Flush" << str_flush_count << "out of" << how_many << endl;

}



























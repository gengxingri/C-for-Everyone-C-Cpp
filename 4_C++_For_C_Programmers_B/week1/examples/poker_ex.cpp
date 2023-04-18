#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

enum class suit:short{SPADE,HEART,DIAMOND,CLUB};
ostream& operator<<(ostream&out, const suit& s){
            switch (s){
                case suit::SPADE: out<<"SPADE"; break;
                case suit::HEART: out<<"HEART"; break;
                case suit::DIAMOND: out<<"DIAMOND"; break;
                case suit::CLUB: out<<"CLUB"; break;
            }
            return out;
        }
class pips{
    public:
      pips(int val):v(val){assert(v>0&&v<14);}
      friend ostream& operator<<(ostream&out,const pips&p);
      int get_pips(){return v;}
    private:
      int v;
};
ostream& operator<<(ostream&out,const pips&p){
    out<<p.v;
    return out;
}
class card{
    public:
        card():s(suit::SPADE),v(1){}
        card(suit s, pips v):s(s),v(v){}
        friend ostream& operator<<(ostream&out, const card& c){
            out<<c.v<<" ";
            out<<c.s;
            return out;
        }
        suit get_suit(){return s;}
        pips get_pips(){return v;}
    private:
        suit s;
        pips v;
};
void init_deck(vector<card>&d){
    for(int i=1;i<14;i++){
        card c(suit::SPADE,i);
        d[i-1]=c;
        d[i+12]=card(suit::HEART,i);
        d[i+25]=card(suit::DIAMOND,i);
        d[i+38]=card(suit::CLUB,i);
    }
}
void print(vector<card> deck){
    for (auto cardval:deck)
        cout <<cardval<<" ";
    cout<<endl;
}
bool is_flush(vector <card> & hand){
    suit s = hand.begin()->get_suit();
    for (auto p=hand.begin()+1; p!=hand.end();++p)
      if (s != p->get_suit())
        return false;
    return true;
}

bool is_straight(vector <card> & hand){
    int pips_v[5],i=0;
    for (auto card:hand)
        pips_v[i++]=card.get_pips().get_pips();
    sort(pips_v,pips_v+5);
    if (((pips_v[0]==pips_v[1]-1)
        &&(pips_v[1]==pips_v[2]-1)
        &&(pips_v[2]==pips_v[3]-1)
        &&(pips_v[3]==pips_v[4]-1))
        ||(pips_v[0]==1
           &&((pips_v[1]==10)
           &&(pips_v[2]==11)
           &&(pips_v[3]==12)
           &&(pips_v[4]==13))))
        return true;
    else
        return false;
}
bool is_straight_flush(vector <card> hand){
    return is_flush(hand) && is_straight(hand);
}
bool is_four(vector <card> & hand){//test for four of a kind
    int pips_v[5],i=0;
    for (auto card:hand)
        pips_v[i++]=card.get_pips().get_pips();
    sort(pips_v,pips_v+5);
    //after sorting, 1st card would be same as 4th or 2nd same as 5th
    return ((pips_v[0]==pips_v[3])||(pips_v[1]==pips_v[4]));
}

int main() {
  vector<card> deck(52);
  cout<<"Hello World from the pokermaster!\n";
  srand(time(0));
  init_deck(deck);
  int how_many,flush_count=0, str_count=0,str_flush_count=0,four_count=0;
  cout<<" How many shuffles? ";
  cin>>how_many;
  for (int loop=0;loop<how_many;loop++){
  random_shuffle(deck.begin(),deck.end());
  vector <card> hand(5);
  int i=0;
  for (auto p=deck.begin();i<5;++p)
    hand[i++]=*p;
  if (is_flush(hand)||is_straight(hand)||is_straight_flush(hand)||is_four(hand))
    print(hand);
  if (is_flush(hand))
    flush_count++;
  if (is_straight(hand))
    str_count++;
  if (is_straight_flush(hand))
    str_flush_count++;
  if (is_four(hand))
    four_count++;
      
  }
  cout<<"Flushes "<<flush_count<<" out of "<<how_many<<endl;
  cout<<"Straights "<<str_count<<" out of "<<how_many<<endl;
  cout<<"Straight Flushes "<<str_flush_count<<" out of "<<how_many<<endl;
  cout<<"Four of a kind "<<four_count<<" out of "<<how_many<<endl;
}
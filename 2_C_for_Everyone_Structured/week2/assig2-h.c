/* This is a program that shuffles a deck of cards.
   Then deal out 7 card hands to evaluate the probability of 
   no pair, one pair, two pair, three of a kind, full house and 4 of a kind.
   Use at least 1 million randomly generated hands.
   
   By Bruce
   Feb 18 2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define PIPS 13
#define DECK_SIZE (SUITS * PIPS)

#define DECKS_NUMBER 1000000
#define HAND_SIZE 7

// Cards suits
typedef enum suit{ hearts, diamonds, spades, clubs} suit;

// Cards struct
typedef struct playing_card{
    suit suit;
    short pip; // 1-13
} card;

//Bit fields, Cards statistics
struct hand_stats{
    unsigned long four_of_kind;
    unsigned long full_house;
    unsigned long three_of_kind;
    unsigned long two_pair;
    unsigned long one_pair;
    unsigned long no_pair;
    unsigned long total;
};


//Shuffle cards
void shuffle_deck(card *deck, int length)
{
    for (int i = 1;  i < length;  ++i) {
        int j = rand() % (i+1);
        // swap cards i and j
        card tmp = deck[i];
        deck[i] = deck[j];
        deck[j] = tmp;
    }
}


// Evaluate 7 cards hand
void evaluate_hand(card *hand, int length, struct hand_stats *stats)
{
    unsigned value_count[PIPS] = { 0 }; // no. of cards of each pip value 
    for (int i = 0;  i < length;  ++i) {
        ++value_count[hand[i].pip];
    }

    unsigned count[SUITS+1] = { 0 }; // no. of singletons, pairs etc
    for (int i = 0;  i < PIPS;  ++i) {
        ++count[value_count[i]];
    }

    if (count[4]) {++stats->four_of_kind;} 
    else if (count[3] && count[2]) {++stats->full_house;} 
    else if (count[3]) {++stats->three_of_kind;} 
    else if (count[2] >= 2) {++stats->two_pair;} 
    else if (count[2]) {++stats->one_pair;} 
    else {++stats->no_pair;}
    ++stats->total;
}


// Main function
int main(void)
{
    srand((unsigned)time(0));

    card deck[DECK_SIZE]; // 13*4

    //Produce 52 cards
    int i = 0;
    for (short j = 1;  j <= PIPS;  ++j) {
        for (short k = 1;  k <= SUITS;  ++k) {
            deck[i].suit = k;
            deck[i].pip = j;
            ++i;
        }
    }

    struct hand_stats stats = { 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0;  i < DECKS_NUMBER;  ++i) {
        shuffle_deck(deck, DECK_SIZE);
        for (int j = 0;  j + HAND_SIZE < DECK_SIZE;  j += HAND_SIZE) {
            evaluate_hand(deck+j, HAND_SIZE, &stats);
        }
    }

    // print the results
    const long double total = stats.total;
    printf("No pair probablity =  %Lf\n",        stats.no_pair       / total);
    printf("One pair probability = %Lf\n",       stats.one_pair      / total);
    printf("Two pair probability = %Lf\n",       stats.two_pair      / total);
    printf("Three of a kind probablity = %Lf\n", stats.three_of_kind / total);
    printf("Four of a kind probability = %Lf\n", stats.four_of_kind  / total);
    printf("Full house probability = %Lf\n",     stats.full_house    / total);
}
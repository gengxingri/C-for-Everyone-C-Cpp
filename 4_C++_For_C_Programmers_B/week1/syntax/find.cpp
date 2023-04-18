/*
   Syntax
   Find position of "hop"
*/


#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() 
{
    string words[5] = {"my", "hop", "mop", "hope", "cope"};
    string* where;

    where = find(words, words+5, "hop");
    cout << *++where << endl; //mop
    sort(words, words+5);
    where = find(words, words+5, "hop");
    cout << *++where << endl; //hope
}
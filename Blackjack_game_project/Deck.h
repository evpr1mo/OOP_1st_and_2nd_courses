#pragma once
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <conio.h>
using namespace std;
#include <iostream>

#include "Card.h"

class Deck
{
public:
    Card* card_deck[51];
    Deck() //default (basic) 52-card deck constructor
    {
        const char* hearts = "\x03";
        const char* diamonds = "\x04";
        const char* clubs = "\x05";
        const char* spades = "\x06";
        char name0[20] = "Ace";
        char name2[20] = "2";
        char name3[20] = "3";
        char name4[20] = "4";
        char name5[20] = "5";
        char name6[20] = "6";
        char name7[20] = "7";
        char name8[20] = "8";
        char name9[20] = "9";
        char name10[20] = "10";
        char name_jack[20] = "Jack";
        char name_queen[20] = "Queen";
        char name_king[20] = "King";

        /*Aces ->  (default value = 1, can be changed to 11 if total score <21)*/
        card_deck[0] = new Card(diamonds, name0, 1, 0);
        card_deck[1] = new Card(hearts, name0, 1, 1);
        card_deck[2] = new Card(clubs, name0, 1, 2);
        card_deck[3] = new Card(spades, name0, 1, 3);

        /*Number cards:

        /* 2 -> */
        card_deck[4] = new Card(diamonds, name2, 2, 4);
        card_deck[5] = new Card(hearts, name2, 2, 5);
        card_deck[6] = new Card(clubs, name2, 2, 6);
        card_deck[7] = new Card(spades, name2, 2, 7);
        /* 3 -> */
        card_deck[8] = new Card(diamonds, name3, 3, 8);
        card_deck[9] = new Card(hearts, name3, 3, 9);
        card_deck[10] = new Card(clubs, name3, 3, 10);
        card_deck[11] = new Card(spades, name3, 3, 11);
        /*4 -> */
        card_deck[12] = new Card(diamonds, name4, 4, 12);
        card_deck[13] = new Card(hearts, name4, 4, 13);
        card_deck[14] = new Card(clubs, name4, 4, 14);
        card_deck[15] = new Card(spades, name4, 4, 15);
        /*5 ->  */
        card_deck[16] = new Card(diamonds, name5, 5, 16);
        card_deck[17] = new Card(hearts, name5, 5, 17);
        card_deck[18] = new Card(clubs, name5, 5, 18);
        card_deck[19] = new Card(spades, name5, 5, 19);
        /*6 ->  */
        card_deck[20] = new Card(diamonds, name6, 6, 20);
        card_deck[21] = new Card(hearts, name6, 6, 21);
        card_deck[22] = new Card(clubs, name6, 6, 22);
        card_deck[23] = new Card(spades, name6, 6, 23);
        /*7 ->  */
        card_deck[24] = new Card(diamonds, name7, 7, 24);
        card_deck[25] = new Card(hearts, name7, 7, 25);
        card_deck[26] = new Card(clubs, name7, 7, 26);
        card_deck[27] = new Card(spades, name7, 7, 27);
        /*8 ->  */
        card_deck[28] = new Card(diamonds, name8, 8, 28);
        card_deck[29] = new Card(hearts, name8, 8, 29);
        card_deck[30] = new Card(clubs, name8, 8, 30);
        card_deck[31] = new Card(spades, name8, 8, 31);
        /*9 ->  */
        card_deck[32] = new Card(diamonds, name9, 9, 32);
        card_deck[33] = new Card(hearts, name9, 9, 33);
        card_deck[34] = new Card(clubs, name9, 9, 34);
        card_deck[35] = new Card(spades, name9, 9, 35);
        /*10 ->  */
        card_deck[36] = new Card(diamonds, name10, 10, 36);
        card_deck[37] = new Card(hearts, name10, 10, 37);
        card_deck[38] = new Card(clubs, name10, 10, 38);
        card_deck[39] = new Card(spades, name10, 10, 39);

        /*cards with images */

        /*Jacks -> */
        card_deck[40] = new Card(diamonds, name_jack, 10, 40);
        card_deck[41] = new Card(hearts, name_jack, 10, 41);
        card_deck[42] = new Card(clubs, name_jack, 10, 42);
        card_deck[43] = new Card(spades, name_jack, 10, 43);

        /*Queens -> */
        card_deck[44] = new Card(diamonds, name_queen, 10, 44);
        card_deck[45] = new Card(hearts, name_queen, 10, 45);
        card_deck[46] = new Card(clubs, name_queen, 10, 46);
        card_deck[47] = new Card(spades, name_queen, 10, 47);
        /*Kings -> */
        card_deck[48] = new Card(diamonds, name_king, 10, 48);
        card_deck[49] = new Card(hearts, name_king, 10, 49);
        card_deck[50] = new Card(clubs, name_king, 10, 50);
        card_deck[51] = new Card(spades, name_king, 10, 51);

        cout << "\nNew card_deck created\n\n";
    }
    Deck(Deck& my_deck) //deck copy constructor
    {
        for (int i = 0;i < 52;i++)
        {card_deck[i] = my_deck.card_deck[i];}
    }
    ~Deck() //deck destructor

    {cout << "\nDeck destructor worked\n";}

    void Create_Card_Deck()
    {Deck A;}
};
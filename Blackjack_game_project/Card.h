#pragma once 
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <conio.h>
using namespace std;
#include <iostream>

class Card
{
    const char* card_suit;
    char* card_name;
    int card_value;
public:
    int number_in_deck;

    friend bool operator >(const Card& a, const Card& b) //logical binary comparison operator >
    {
        if (a.card_value > b.card_value) return true;
        return false;
    }

    friend bool operator <(const Card& a, const Card& b) //logical binary comparison operator <
    {
        if (a.card_value < b.card_value) return true;
        return false;
    }
    friend bool operator !=(const Card& a, const Card& b) //logical binary object comparison-check operator !=
    {
        if ((a.card_value != b.card_value)||(a.card_suit!=b.card_suit)||(a.card_name!=b.card_name)||(a.number_in_deck!=b.number_in_deck)) return true;
        return false;
    }

    friend bool operator ==(const Card& a, const Card& b) //logical binary object comparison-check operator ==
    {
        if ((a.card_value == b.card_value)||(a.card_suit==b.card_suit)||(a.card_name==b.card_name)||(a.number_in_deck==b.number_in_deck)) return true;
        return false;
    }

    Card& operator = (const Card&); //initialization of an assignment binary operator = for Card_objects

    Card()// default constructor
    {
        card_suit = "0";
        card_name = new char[20];
        strcpy_s(card_name, 20, "card_name");
        card_value = 0;
        number_in_deck = 0;
    }
    Card(const char* suit, char* name, int value, int n) //parameter constructor
    {
        int v2 = (strlen(name) + 1);
        card_suit = suit;
        card_name = new char[v2];
        strcpy_s(card_name, v2, name);
        card_value = value;
        number_in_deck = n;
        //cout << "\nobject card created (parameter constructor)";
    }
    Card(Card& newcard) //copy constructor
    {
        card_suit = newcard.card_suit;
        card_name = new char[20];
        strcpy_s(card_name, 20, newcard.card_name);
        card_value = newcard.card_value;
        number_in_deck = newcard.number_in_deck;
    }
    ~Card() //destructor
    {
        if (card_suit)
            delete[]card_suit;
        if (card_name)
            delete[]card_name;
        cout << "\nCard destructor worked\n";
    }

    void Create_Card(const char* s, char* n, int v, int dn)
    {
        Card A(s, n, v, dn);
        cout << "\nCard created\n";
    }
    void Print_Card()
    {
        /*Pseudographic symbols ->*/
        unsigned char c = 442; // side |
        unsigned char l = 457; // top left corner ã 
        unsigned char r = 456; // lower left corner L
        unsigned char s = 443; // top right corner ]
        unsigned char k = 444; // lower right corner _| 

        const char* m;
        char* _name;
        int val;

        m = card_suit;
        _name = card_name;
        val = card_value;

        /*Symbol arrays of gaps for different card_names */
        char n1[5]=" "; 
        char n2[5] = "  ";
        char n3[5] = "   ";
        char n4[5] = "    ";
        char n5[6] = "     ";

        /*card design -> */

        int var = strlen(_name);
      switch (var) //drawing cards
      {
            case 1:
        {
            cout << "\n\n";
            cout << l << "=======" << s << endl;
            cout << c << "   " << m << "   " << c << endl;
            cout << c << " " << _name << n5 << c << endl;
            cout << c << "       " << c << endl;
            cout << r << "=======" << k << endl;
            cout << "    " << val << "   " << endl;
        }break;
        case 2:
        {
            cout << "\n\n";
            cout << l << "=======" << s << endl;
            cout << c << "   " << m << "   " << c << endl;
            cout << c << " " << _name << n4 << c << endl;
            cout << c << "       " << c << endl;
            cout << r << "=======" << k << endl;
            cout << "    " << val << "   " << endl;
        }break;
        case 3:
        {
            cout << "\n\n";
            cout << l << "=======" << s << endl;
            cout << c << "   " << m << "   " << c << endl;
            cout << c << " " << _name << n3 << c << endl;
            cout << c << "       " << c << endl;
            cout << r << "=======" << k << endl;
            cout << "    " << val << "   " << endl;
        }break;
        case 4: 
        {
            cout << "\n\n";
            cout << l << "=======" << s << endl;
            cout << c << "   " << m << "   " << c << endl;
            cout << c << " " << _name << n2 << c << endl;
            cout << c << "       " << c << endl;
            cout << r << "=======" << k << endl;
            cout << "    " << val << "   " << endl;
        }break;
        case 5: 
        {
            cout << "\n\n";
            cout << l << "=======" << s << endl;
            cout << c << "   " << m << "   " << c << endl;
            cout << c << " " << _name << n1 << c << endl;
            cout << c << "       " << c << endl;
            cout << r << "=======" << k << endl;
            cout << "    " << val << "   " << endl;
        }break;
      }

    }
    void Flipped_Card_Draw()
    {
        /*Pseudographic symbols ->*/
        unsigned char c = 442; // side |
        unsigned char l = 457; // top left corner ã 
        unsigned char r = 456; // lower left corner L
        unsigned char s = 443; // top right corner ]
        unsigned char k = 444; // lower right corner _| 

         /* flipped card design -> */
        cout << "\n\n";
        cout << l << "=======" << s << endl;
        cout << c << "///////" << c << endl;
        cout << c << "///////" << c << endl;
        cout << c << "///////" << c << endl;
        cout << r << "=======" << k << endl;

    }

    const char* Get_Card_Suit()
    {return card_suit;}

    char* Get_Card_Name()
    {return card_name;}

    int Get_Card_Value()
    {return card_value;}

    int Get_Deck_Number()
    {return number_in_deck;}

    void Set_Card_Value(int a)
    {card_value = a;}

    void Set_Deck_Number(int m)
    {number_in_deck = m;}
};

Card& Card::operator =(const Card& newcard)  //Assignment binary operator = for card_objects  
{
    if (this != &newcard) //protection from self-assignment 
    {
        int v = strlen(newcard.card_name);  //measuring new card name
        card_value = newcard.card_value;
        number_in_deck = newcard.number_in_deck;
        card_suit = newcard.card_suit;
        delete[] card_name;
        if (v != 0) //check for empty card_name 
        {
            card_name = new char[v + 1];
            strcpy_s(card_name, (v + 1), newcard.card_name);
        }
        else card_name = nullptr;
    }
    return *this;
}
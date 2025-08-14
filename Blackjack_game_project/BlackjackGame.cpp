
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <conio.h>
using namespace std;

#include <iostream>

#include "String.h"
#include "Card.h"
#include "Deck.h"
#include "Person.h"
#include "Croupier.h"
#include "Player.h"
#include "Table.h"
#include "Bet.h"
#include "Date.h"
#include <list>
using namespace std;
#include <set>

typedef multiset< int > IntSet;
int Date::Dates_count = 0; //initializing start value for static member of class Date

void print(list<int>& li)//function to print element from the list while iterating it 
{
    auto it = li.begin();

    if (it == li.end()) 
    {
        cout << "List is Empty" << endl;
    }

    for (; it != li.end(); it++)
    {
        cout << *it << " ";
    }
    
    cout << endl;
}

void erase_in_range(list<int>& li, int key1, int key2)
{

    list<int>::iterator it1;
    list<int>::iterator it2;

    // Before Deletion
    cout << "Before Deletion: " << "\n";

    cout << "Size of List: " << li.size() << "\n";

    print(li);

    // Finding key elements from the list and assigning iterators
    it1 = find(li.begin(), li.end(), key1);
    it2 = find(li.begin(), li.end(), key2);

    it2++;

    // Deleting the range from the list using key iterators
    li.erase(it1, it2);

    // After Deletion
    cout << "\nAfter Deletion: " << endl;
    cout << "Size of List: " << li.size() << endl;

    print(li);
}

/*void Pick_Card()
{

}*/
void Game_Start()
{
    /*char new_name_player[40];
    char croupier1[20] = "Gambler";
    Card player_hand[5];
    Card croupier_hand[5];

    cout << "\nNew game started! Enter your name: ";


    cin >> new_name_player;
    cout << "\nYour starting balance is 1000$";
    Player P1(new_name_player, 1000);
    Croupier C1(croupier1, 1);
    P1.joined_the_game();
    C1.joined_the_game();
    Deck D1;*/
}
void PrintMenu()
{
    unsigned char c = 442;
    unsigned char l = 457;
    unsigned char r = 456;
    unsigned char s = 443;
    unsigned char k = 444;

    cout << "\n\n\n";
    cout << "                                 " << "             " << "MENU\n";
    cout << "                                 " << l << "================================" << s << endl;
    cout << "                                 " << c << "       0) Lab demonstrations    " << c << endl;
    cout << "                                 " << c << "                                " << c << endl;
    cout << "                                 " << c << "       1)Start new game         " << c << endl;
    cout << "                                 " << c << "                                " << c << endl;
    cout << "                                 " << c << "       2)Continue game          " << c << endl;
    cout << "                                 " << c << "                                " << c << endl;
    cout << "                                 " << c << "       3)About authors          " << c << endl;
    cout << "                                 " << c << "                                " << c << endl;
    cout << "                                 " << c << "       4)Instructions           " << c << endl;
    cout << "                                 " << c << "                                " << c << endl;
    cout << "                                 " << c << "       5)Exit                   " << c << endl;
    cout << "                                 " << c << "                                " << c << endl;
    cout << "                                 " << r << "================================" << k << endl;
    cout << "\n\n\n";

}
void PrintInfoAuthor()
{
    unsigned char c = 442;
    unsigned char l = 457;
    unsigned char r = 456;
    unsigned char s = 443;
    unsigned char k = 444;

    cout << "\n\n\n";
    cout << "                                 " << "         " << "ABOUT AUTHORS\n";
    cout << "                                 " << l << "================================" << s << endl;
    cout << "                                 " << c << "     This game was developed,   " << c << endl;
    cout << "                                 " << c << "  designed, tested and released " << c << endl;
    cout << "                                 " << c << "  by the students of KPI, IASA  " << c << endl;
    cout << "                                 " << c << "           team 33              " << c << endl;
    cout << "                                 " << c << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << c << endl;
    cout << "                                 " << c << "   Any unauthorized use or      " << c << endl;
    cout << "                                 " << c << "   non-licensed reproduction    " << c << endl;
    cout << "                                 " << c << "   of this work is strictly     " << c << endl;
    cout << "                                 " << c << "   prohibited, and will be a    " << c << endl;
    cout << "                                 " << c << "   copyright violation          " << c << endl;
    cout << "                                 " << c << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << c << endl;
    cout << "                                 " << c << "         Kyiv, year 2023        " << c << endl;
    cout << "                                 " << r << "================================" << k << endl;
    cout << "\n\n\n";
}

void PrintGoodbye()
{
    unsigned char c = 442;
    unsigned char l = 457;
    unsigned char r = 456;
    unsigned char s = 443;
    unsigned char k = 444;
    cout << "\n\n";
    cout << l << "=============================================" << s << endl;
    cout << c << "          Thanks for using our program!       " << c << endl;
    cout << c << "               Have a nice day :)            " << c << endl;
    cout << r << "=============================================" << k << endl;
    cout << "\n\n";
}

void PrintInstructons()
{
    unsigned char c = 442;
    unsigned char l = 457;
    unsigned char r = 456;
    unsigned char s = 443;
    unsigned char k = 444;

    cout << "\n\n\n";
    cout << "                    " << "                     " << "INSTRUCTIONS\n";
    cout << "                    " << l << "======================================================" << s << endl;
    cout << "                    " << c << " 1)How to use MENU: Press 0-for lab demonstration     " << c << endl;
    cout << "                    " << c << "           Press 1-for starting a new game;           " << c << endl;
    cout << "                    " << c << "           Press 2-for continuing the previous game;  " << c << endl;
    cout << "                    " << c << "           Press 3-for printing info about authors;   " << c << endl;
    cout << "                    " << c << "           Press 4-for printing instructions          " << c << endl;
    cout << "                    " << c << "           Press 5-for exiting the program            " << c << endl;
    cout << "                    " << c << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << c << endl;
    cout << "                    " << c << " 2)If you want the program to run successfuly without " << c << endl;
    cout << "                    " << c << " warnings, always follow the directions when entering " << c << endl;
    cout << "                    " << c << " numbers or letters; program always tells you in what " << c << endl;
    cout << "                    " << c << " format it expects you to enter symbol, do exactly as " << c << endl;
    cout << "                    " << c << " it says.If you have entered a wrong number/letter,or " << c << endl;
    cout << "                    " << c << " used inappropriate format, you will have to reenter  " << c << endl;
    cout << "                    " << c << " it after getting a warning.                          " << c << endl;
    cout << "                    " << c << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << c << endl;
    cout << "                    " << c << "                   HAVE A NICE GAME!                  " << c << endl;
    cout << "                    " << r << "======================================================" << k << endl;
    cout << "\n\n\n";

}

    int main()
    {   
        int XM = 0;
        int Option = 30;
        int Iteration = 0;
        
        cout << "\n------------------------------ Nice to see you in our program! Lets get started ------------------------------\n\n";
        while (XM != 1)
        {
            PrintMenu();

            cin >> Option;

            switch (Option)
            {
            case 0:
            {
                system("cls");
                cout << "\n------------------------------ Starting lab2 demonstration ------------------------------\n\n";
                double player_balance=1000;
                double table_maxbet = 12000;
                double player_bet;

                char name_croupier[20] = "Hesh";
                char name_player[20] = "Tester1";
                int number_croupier = 1;
                /*Static fields and methods display ->*/
                cout << "\nDemonstration of static fields and methods for class Date ->\n\n";
                cout << "Initial count of Date objects: " << Date::Get_Count_Dates() << "\n";
                Date date1(16, 4, 2005);
                Date date2(5, 12, 2008);
                cout << "\nFinal count of Date objects: " << Date::Get_Count_Dates() << "\n";


                Player player1(name_player, player_balance);
                player1.joined_the_game();  //polymorphism (realization) example, dynamic binding
                Croupier croupier1(name_croupier, 1);
                croupier1.joined_the_game();

                Table table1(table_maxbet); //creating object Table
                player_bet = player1.Make_Bet(table_maxbet); //making bet
                Bet bet1(player_bet);

                /*cards and deck creation+display->*/

                Deck A;
                cout << "\nCard examples:\n";
                A.card_deck[0]->Flipped_Card_Draw();
                A.card_deck[0]->Print_Card();

                cout << "\nCard Deck (52) example:\n";
                for (int i = 0;i < 52;i++)
                {
                    A.card_deck[i]->Print_Card();  //all 52 cards from deck displayed
                }

                cout << "\n--------------------------Demonstrating Lab3------------------------------\n\n";
                Date date3;
                cout << "Enter new date: ";
                cin >> date3;  //input operator demonstration 
                cout << date3; //output operator demonstration

                cout << "\nBefore: " << date3 << "\n";
                ++date3;  //prefix increment demonstration (returns link to date3)
                cout << "After: " << date3 << "\n";

                cout << "\nBefore: " << date3 << "\n";
                --date3;//prefix decrement demonstration
                cout << "After: " << date3 << "\n";

                cout << "\nBefore: " << date1 << "\n";
                date1++;  //postfix increment demonstration (returns value of date1) 
                cout << "After: " << date1 << "\n";

                cout << "\nBefore: " << date2 << "\n";
                date2--;  //postfix decrement demonstration
                cout << "After: " << date2 << "\n";

                bet1 = -bet1;  //arythmetic unary operator - demonstration
                cout << "\n" << bet1 << "\n";

                Bet bet2(19), bet3(100);
                bet2 = (bet2 + bet3); //arythmetic binary operator + demonstration
                cout << "\n" << bet2 << "\n";

                bet3 = (bet3 - bet2); //arythmetic binary operator - demonstration
                cout << "\n" << bet3 << "\n";

                Card a, b;
                int j, k;
                cout << "\n\nLets compare cards a and b ->\nChoose number of card a from deck (0-52): ";
                cin >> j;
                cout << "\nChoose number of card b from deck: ";
                cin >> k;
                cout << "\n\nYour cards: ";
                a = *A.card_deck[j]; //Assignment binary operator = for cards demonstration 
                b = *A.card_deck[k];
                a.Print_Card();
                b.Print_Card();

                if ((a > b) == true) //logical binary comparison operator > demonstration
                {
                    cout << "\n This card has more value:";
                    a.Print_Card();
                }
                else if ((a < b) == true)//logical binary comparison operator < demonstration
                {
                    cout << "\n This card has less value:";
                    a.Print_Card();
                }
                else if ((a == b) == true) //logical binary object comparison-check operator == demonstration
                {
                    a.Print_Card();
                    b.Print_Card();
                    cout << "\n Cards are equal";
                }
                else
                {
                    a.Print_Card();
                    b.Print_Card();
                    cout << "\n Cards' values are equal";
                }

                cout << "\n--------------------------Demonstrating Lab4------------------------------\n\n";
                int v;
                char name_M[20] = "Player Max";
                char* m = name_M;
                char name_J[20] = "Player Julian";
                char* J = name_J;
                char name_A[20] = "Player Amy";
                char* Amy = name_A;

                char not_found[20] = "Player not found";
                char* NF = not_found;

                Results<int> intResults;
                Results<char> charResults(5);
                Results<int> IntResults(5);
                cout << "\n  Instantiating your Results <int>, enter 5 numbers: ";
                for (int a = 0;a < 5;a++)
                {
                    cin >> v;
                    IntResults[a] = v;
                }
                cout << "\n\nYour Results<int>: ";
                for (int a = 0;a < 5;a++)
                {
                    cout << IntResults[a] << " ";
                }

                char B;
                cout << "\n  Instantiating your Results <char>, enter 5 characters: ";
                for (int a = 0;a < 5;a++)
                {
                    cin >> B;
                    charResults[a] = B;
                }
                cout << "\n\n  Your Results<char>: ";
                for (int a = 0;a < 5;a++)
                {
                    cout << charResults[a] << " ";
                }


                Results<int> res2(IntResults);
                Results<int> res3(2);
                res3 = res2;
                ;
                Results<char*> sv1(12);
                cout << "\n\n  Instantiating specialization for Results<char*>:\n ";
                for (int i = 0;i < 12;i++)
                {
                    sv1.insert(NF, i);
                }

                for (int i = 0;i < 12;i++)
                {
                    sv1.display(i);
                }

                cout << "\n\n";

                sv1.insert(m, 0);
                sv1.insert(J, 1);
                sv1.insert(Amy, 2);

                for (int i = 0;i < 12;i++)
                {
                    sv1.display(i);
                }

                Results<char*> sv2(sv1);
                Results<char*> sv3(2);
                sv3 = sv1;
                cout << "\n\n-------------------------- STL Containers and methods demonstration ------------------------------- \n";

                // List created
                list<int> li = { 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14 };

                int key1 = 4, key2 = 10;
                erase_in_range(li, key1, key2);

                const int SIZE = 11;
                int iArray[SIZE] = { 3, 2, 3, 4, 5,6 ,7,8,9,10, 14 };
                IntSet my_int_mset(iArray, iArray + SIZE);
                IntSet::iterator it = my_int_mset.begin();
                cout << "\n\nMultiset numbers: ";
                for (int i = 0; i < SIZE; ++i)
                    cout << *it++ << ", ";
                multiset<int> container;
                for (int i = 0;i < SIZE;i++)
                {
                    container.insert(iArray[i]);
                }


                cout << "\nMultiset size: " << container.size();
                for (int i = 0; i < SIZE; ++i)
                {
                    cout << "\ncount of [" << iArray[i] << "]: " << container.count(iArray[i]) << "\n";
                }
                cout << "\n\nContainer elements:\n";
                for (const auto& elem : container)
                {
                    cout << elem << "\n";
                }
                
            }break;
            case 1:
            {
                //here program has to start a new game (wasn't finished)
                /*Game_Start();*/
                Iteration = 1;
                system("cls");
                

            }break;
            case 2:
            {
                if (Iteration == 1)
                {
                    //continuing previous game (wasn't finished)
                }
                else
                {
                    system("cls");
                    cout << "\nYou have no previous games! Create a new one to start\n";
                }
            }break;
            case 3:
            {
                system("cls");
                PrintInfoAuthor();
            }break;
            case 4:
            {
                system("cls");
                PrintInstructons();
            }break;
            case 5:
            {
                system("cls");
                PrintGoodbye();
                XM = 1;
                system("pause");
            }break;
            default:
            {
                system("cls");
                cout << "\nCommand not found! Use numbers 1-5 for selecting commands\n";
            }
            }
        }  
    }



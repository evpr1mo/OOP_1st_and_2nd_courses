#pragma once
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <conio.h>
using namespace std;
#include <iostream>

#include "Croupier.h"
#include "Player.h"

class Table
{
    double max_bet;

public:
    Table() //def constructor
    {
        double max_bet = 0;
    }

    Table(double maxbet) //parameter constructor
    {
        max_bet = maxbet;
        cout << "\n\nNew table created (parameter constructor)";
    }

    Table(Table& newtable) //copy constructor
    {
        newtable.max_bet = max_bet;
    }

    ~Table()//destructor
    {
        cout << "\nTable destructor worked";
    }

    double Get_Max_bet()
    {
        return max_bet;
    }

    void Set_Max_bet(double c)
    {
        max_bet = c;
    }

    void Print_Info_Table(Croupier D)
    {
        int number;
        char* croupier_name;
        number = D.Get_Number();
        croupier_name = D.Get_Name();
        cout << "\nTable ¹" << number << "   Croupier:" << croupier_name << "\n\n";
    }
};
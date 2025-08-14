#pragma once
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <conio.h>
using namespace std;
#include <iostream>

class Bet
{
    double total;
public:
    /*class metod-associated operator ->*/

    Bet operator - ()const; //arythmetic unary operator - initialization

    /*friendly-function operators ->*/

    friend Bet operator - (Bet a,Bet b) //arythmetic binary operator -
    {
        a.total = a.total - b.total;
        return a.total;
    }

    friend Bet operator + (Bet a, Bet b) //arythmetic binary operator +
    {
        a.total = a.total + b.total;
        return a.total;
    }
    
    friend bool operator >(const Bet&a, const Bet&b) //arythmetic binary comparison operator >
    {
        if (a.total > b.total) return true;
        return false;
    }

    friend bool operator <(const Bet& a, const Bet& b) //arythmetic binary comparison operator <
    {
        if (a.total < b.total) return true;
        return false;
    }

    friend ostream& operator <<(ostream& os, const Bet& bet) //stream output operator <<
    {
         os << "Bet: " << bet.total << "$";
         return os;
    }

    friend istream& operator >>(istream& is, Bet& bet) //stream input operator >>
    {
        is >> bet.total;
        return is;
    }

    Bet() //default constructor
    {total = 0;}

    Bet(double amount) //parameter constructor
    {
        total = amount;
    
    }

    Bet(Bet& newbet)  //copy constructor
    {total = newbet.total;} 

    ~Bet() //destructor
    {}

    double Get_Bet()
    {
        return total;
    }
    void Set_Bet(double t)
    {total = t;}
};
 

   Bet Bet::operator-()const //arythmetic unary operator - realization
   {
    Bet temp;
    temp.total = -total;
    return temp;
   }
   

   


#pragma once
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <conio.h>
using namespace std;
#include <iostream>

class Date
{
    int day;
    int month;
    int year;

public:
    static int Dates_count;
    /*Class member functions-associated operators -> */

    Date &operator++(); //prefix operator ++obj_date initialization
    Date operator ++(int); //postfix operator obj_date++ initialization
    Date& operator--(); //prefix operator --obj_date initialization
    Date operator --(int); //postfix operator obj_date-- initialization

    /*friend functions-associated operators -> */

    friend istream& operator >>(istream& is, Date& date) //stream input operator >>
    {
        int check = 0;
        char p;
        while (check != 1)
        {
            is >> date.day >>p>> date.month>>p>> date.year;
            if (p == '.')  //checking the input date format 
            {
                return is;
                check = 1;
            }
            else
            {cout << "\nCouldn't recognize the date, use (day.month.year) format only!\n";}
        }
    }

    friend ostream& operator <<(ostream& os, const Date& date); //stream output operator <<
    

    Date() //default constructor
    {
        day = 11;
        month = 11;
        year = 2022;
        Dates_count++;
    }

    Date(int p_day, int p_month, int p_year) //parameter constructor
    {
        day = p_day;
        month = p_month;
        year = p_year;

        Dates_count++;
        cout << "\nNew Date created (parameter constructor)\n";
    }
    Date(Date& newdate) //copy constructor
    {
        day = newdate.day;
        month = newdate.month;
        year = newdate.year;
        Dates_count++;
    }
    ~Date() //destructor
    {}

    static int Get_Count_Dates()
    {return Dates_count;}

    void Print_Info_Date()
    {cout << "\n" << day << "." << month << "." << year << "\n";}
};



    Date& Date::operator++() //prefix operator ++obj_date realization
    {
        day++;
        return *this; //returns link to the object
    }
    
    Date Date::operator ++(int) //postfix operator obj_date++ realization 
    {
        Date temp = *this; //saving current object status
        day++;             //incrementing object
        return temp;       //returning temporary parameter with new day value 
    }

    Date& Date::operator--() //prefix operator --obj_date realization
    {
        day--;
        return *this;
    }

    Date Date::operator --(int) //postfix operator obj_date-- realization 
    {
        Date temp = *this; 
        day--;
        return temp;        
    }

    ostream& operator <<(ostream& os, const Date& date) 
    {
        os << "Date: " << date.day << "." << date.month << "." << date.year;
        return os;
    }
#pragma once
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <conio.h>
using namespace std;
#include <iostream>

#include "Person.h"
#include "Croupier.h"
#include "Card.h"
#include "Deck.h"

 template <typename T> //template class 
 class Results 
{
    int size;
    T* ptr;
public: 
    //initializing 1 parametric constructor, 1 copy constructor, size-getter fuction, operators [] and =  

    Results<T>(int = 10);
    Results<T>(const Results<T>&);
    ~Results<T>();
    int getSize() const;
    const Results<T>& operator = (const Results<T>&);
    T& operator [] (int);
};

template <typename T>

Results<T>::Results<T>(int s) //template class parameter constructor
{
    size = s;
    if (size != 0) ptr = new T[size];
    else ptr = nullptr;
}

template <typename T>
Results<T>::Results<T>(const Results<T>& prototype) //template class copy constructor
{
    size = prototype.getSize();
    if (size != 0)
    {
        ptr = new T[size];
        for (int i = 0; i < size; i++)
        {
            ptr[i] = prototype.ptr[i];
        }
    }
    else ptr = nullptr;
}


template <typename T>  //template class destructor realization
Results<T>::~Results<T>()
{delete[] ptr;}

template <typename T> //template class selector-function realization
int Results<T>::getSize() const
{return size;}

template <typename T> 
const Results<T>& Results<T>::operator =(const Results<T>& parameter)  //overloading operator = for template class 
{
    if (this != &parameter) 
    {
        delete[] ptr;
        size = parameter.size;
        if (size != 0) 
        {
            ptr = new T[size];
            for (int i = 0; i < size; i++)
                ptr[i] = parameter.ptr[i];
        }
        else ptr = nullptr;
    }
    return *this;
}

template <typename T>
T& Results<T>::operator [] (int index) //indexation operator []
{
    if (index < 0 || index >= size)
    {
        cout << "\nError: index out of range\n";
        exit(1);
    }
    return ptr[index];
}

 template<>
class Results<char*>  //initializing specialization for template class
{
    int size;
    char** ptr;
public:
    Results(int=10);               //parameter constructor
    Results(const Results<char*>&);//copy constructor
    virtual ~Results();            //destructor
    int getSize() const;           //size-getter function
    const Results<char*>& operator =(const Results<char*>&); //assignment operator
    char*& operator [] (int);      //indexation operator
    void insert(char*, int);       //inserts name on given position
    void display(int);             //displays element on given position
};


Results<char*>::Results(int s) //parameter constructor for specialization 
    {
        size = s;
        if (size != 0)
        {
            ptr = new char* [size];
            for (int i = 0; i < size; i++)
                ptr[i] = nullptr;
        }
        else ptr = nullptr;
    }




Results<char*>::Results(const Results<char*>& prototype)  //copy constructor for specialization
{
    size = prototype.getSize();
    if (size == 0) 
    {
        ptr = nullptr;
        return;
    }
    ptr = new char* [size];
    for (int i = 0; i < size; i++)
        if (prototype.ptr[i] != nullptr)
        {
            int v = strlen(prototype.ptr[i]);
            ptr[i] =new char[v+ 1];
            strcpy_s(ptr[i],v+1, prototype.ptr[i]);
        }
        else ptr[i] = nullptr;
}


Results<char*>::~Results()  //specialization destructor
{
    for (int i = 0; i < size; i++)
        delete[] ptr[i];
    delete[] ptr;
}


int Results<char*>::getSize() const   //getter function for specialization
{return size;}


const Results<char*>& Results<char*>::operator =(const Results<char*>& parameter) //assignment operator for specialization
{
    if (this == &parameter) 
        return *this;

    for (int i = 0; i < size; i++)
    {
        delete[] ptr[i];
    }
    delete[] ptr;
    size = parameter.size;

    if (size == 0)
    {
        ptr = nullptr;
        return *this;
    }
    ptr = new char* [size];
    for (int i = 0; i < size; i++)
    {
        if (parameter.ptr[i] != nullptr)
        {
            int m = strlen(parameter.ptr[i]);
            ptr[i] = new char[m + 1];
            strcpy_s(ptr[i], m+1, parameter.ptr[i]);
        }
        else ptr[i] = nullptr;
    }
    return *this;
}


  char*& Results<char*>::operator[] (int index) //indexation operator for specialization 
{
    if (index < 0 || index >= size) 
    {
        cout << "Error: index out of range\n";
        exit(1);
    }
    return ptr[index];
}


 void Results<char*>::insert(char* str, int i) // insert function for specialization
 {
     delete[] ptr[i];
     if (str != nullptr) 
     {
         int c = strlen(str);
         ptr[i] = new char[ c+ 1];
         strcpy_s(ptr[i],c+1,str);
     }
     else ptr[i] = nullptr;
 }

 void Results<char*>::display(int i) //display function for specialization
 {
         cout << "Stats["<< i<<"]: "<<ptr[i] << "\n";
         if (ptr[i] == nullptr)
         {
             cout << "Player not found\n";
         }
 }







class Player : public Person //derivative class from Person
{
    double balance;
public:
    Player() :Person()//def constructor
    {balance = 0;}

    Player(char* Name, double bal) :Person(Name)//parameter constructor
    {
        balance = bal;
        cout << "\nobject Player created (parameter constructor)";
    }

    Player(const Player& my_player) :Person( my_player)//copy constructor
    {balance = my_player.balance;}

     ~Player() //destructor
    {cout << "\ndestructor Player worked";}

    void joined_the_game() //realization of behaviour for player
    {
        char* name = Get_Name();
        cout << "\nPlayer " << name << " has joined our game!";
    }

    double Get_Balance()
    {return balance;}

    void Check_if_Player_Allowed(Player P)
    {
        double bal_p;
        bal_p = P.Get_Balance();
        if (bal_p == 0)
        {
            cout << "\nYou cant place your bet if you're out of cash! Go earn something first to squander here!\n\n";
        }
    }

    double Make_Bet(double mx_bet_Table) 
    {
        double my_bet;int ind = 0;

        while (ind == 0)
        {
            cout << "\nWhat amount of money do you want to bet? Enter sum considering bet limits (<max_bet) for your table:";
            cin >> my_bet;
            if ((my_bet > mx_bet_Table) || (my_bet < 0)) //bet is checked here
            {
                cout << "\nEnter your bet correctly, not more than " << mx_bet_Table;
            }
            else
            {
                cout << "\nBet successful\n";
                return my_bet;
                ind = 1;
            }
        }
    }
};

#pragma once
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <conio.h>
using namespace std;
#include <iostream>

#include "Person.h"
#include "Card.h"
#include "Deck.h"

class Croupier : public Person //derivative class from Person
{
    int number;
public:
    Croupier() :Person() //default constructor
    {number = 0;}

    Croupier(char* Name, int N) : Person(Name) //parameter constructor
    {
        number = N;
    }

    Croupier(const Croupier& croupier) : Person(croupier) //copy constructor
    {number = croupier.number;}

     ~Croupier()  //destructor
    {cout << "\ndestructor Croupier worked";}

    void joined_the_game() //realization of behaviour for croupier
    {
        char* name = Get_Name();
        cout << "\nCroupier " << name << " has joined our game!";
    }
    int Get_Number()
    {return number;}

    void Set_Number(int a)
    {
        number = a;
    }

};
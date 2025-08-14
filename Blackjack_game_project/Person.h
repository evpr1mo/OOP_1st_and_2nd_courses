#pragma once 
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <conio.h>
using namespace std;
#include <iostream>


class Person //parent class
{
protected:
    char* Name;

    Person() //default constructor
    {
        Name = new char[20];
        strcpy_s(Name, 20, "somename");
    }

    Person(char* name) //parameter constructor
    {
        int v = (strlen(name) + 1);
        Name = new char[v];
        strcpy_s(Name, v, name);
    }
    Person(const Person& person) //copy constructor
    {
        int v1 = (strlen(person.Name) + 1);
        Name = new char[v1];
        strcpy_s(Name, v1, person.Name);
    }
    virtual ~Person() //destructor
    {
        if (Name)
            delete[]Name;
        cout << "\ndestructor Person worked";
    }

public:
    char* Get_Name()
    {
        return Name;
    }
    virtual void joined_the_game() = 0; //pure virtual function (for realization example in derivative classes)
};

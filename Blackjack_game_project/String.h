#pragma once
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <cassert>
using namespace std;

#include <iostream>


class String 
{
	int size;
    char* BufPtr;

public:

    operator int();
    operator char* ();
    char& operator [] (int);

    String() //default constructor
    {
        size = 20;
        BufPtr = new char[20];
        strcpy_s(BufPtr, 20, "default string");
    }

    String(char* bptr) //parameter constructor
    {

        size = (strlen(bptr) + 1);
        BufPtr= new char[size+1];
        strcpy_s(BufPtr, size+1, bptr);
    }
    String(const String& newstring) //copy constructor
    {
        size = (strlen(newstring.BufPtr) + 1);
        BufPtr = new char[size+1];
        strcpy_s(BufPtr, (size+1), newstring.BufPtr);
    }

	String(int);// constructor using 1 parameter for type conversion
	char* getStringPointer() const;
};

String::String(int a) 
{
    cout << "String(int) constructor worked: ";
    char array[11];
    _itoa_s(a, array, 10);
    size = strlen(array);
    BufPtr = new char[size + 1];
    strcpy_s(BufPtr, (size+1), array);
}

char* String::getStringPointer() const 
{return BufPtr;}

String::operator int() 
{
    if (size > 0) return atoi(BufPtr); //String -> int operator 
    return -1;
}
String::operator char* () //String -> char* operator
{return BufPtr;}

char& String::operator [] (int pos)
{
    assert(pos > 0 && pos <= size);
    return BufPtr[pos - 1];
}



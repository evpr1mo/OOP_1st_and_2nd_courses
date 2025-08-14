#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <time.h>
using namespace std;
#include <iostream>


class Coordinates
{
private:
    int CoordinateX;
    int CoordinateY;

public: 

    Coordinates() //default constructor
    {
        CoordinateX = 0;
        CoordinateY = 1;
        cout << "Constr coordinates()";
    }
    Coordinates(int x, int y) //constructor using parameters
    {
        CoordinateX = x;
        CoordinateY = y;
    }
    Coordinates(const Coordinates& coord) //copy constructor
    {
        CoordinateX = coord.CoordinateX;
        CoordinateY = coord.CoordinateY;
    };

    ~Coordinates() //destructor
    {}; 
    
    Coordinates& FunctionMod_SetCoodinateX(int m)
    {
        CoordinateX = m;
        return *this;
    }
    Coordinates& FunctionMod_SetCoodinateY(int g)
    {
        CoordinateY = g;
        return *this;
    }

    void SetCoordinateX(int X)
    {CoordinateX = X;}

    void SetCoordinateY(int Y)
    {CoordinateY = Y;}

    int GetCoordinateX()
    {return CoordinateX;} 
    
    int GetCoordinateY()
    {return CoordinateY;}

    void PrintFunction1()
    {
        int Cord_x, Cord_y;
        Cord_x=GetCoordinateX();
        Cord_y = GetCoordinateY();
        cout << Cord_x << " " << Cord_y;
    }
    void PrintFunction2()
    {
        int Cord_x = GetCoordinateX();
        int Cord_y = GetCoordinateY();
        cout << "\nCoordinates X:" << Cord_x<<" Y:"<<Cord_y<<"\n";
    }
};
class Creature
{
private:
    char* name;
    int Age;
    Coordinates A;
public:
    
    char* GetName()
    {return name;}

    int GetAge()
    {return Age;}
    
    Coordinates GetCoordinates()
    {return A;}


    Creature() //default (basic) constructor
    {
        name = new char[10];
        strcpy_s(name,10, "somename");
        Age = 0;
        //A = *new Coordinates();
    }
    Creature(char* name2, int age, Coordinates k) //constructor with parameters
    {
        name = new char[strlen(name2) + 1];
        strcpy_s(name, strlen(name2) + 1,name2);
        Age = age;
        A = k;
    }
    Creature(Creature& my_creature) //copy constructor
    {
        name = new char[strlen(my_creature.name) + 1];
        strcpy_s(name, strlen(my_creature.name)+1, my_creature.name);
        Age = my_creature.Age;
        A = my_creature.A;
    }

    ~Creature() //destructor
    {
        if (name)
          delete[] name;
    };

    void PrintPositionInfo()
    {
        A.PrintFunction1();
    }
    void PrintName()
    {
        cout << name;
    }
    void PrintInfoFull()
    {
        std::cout << "Creature Name:" << name << " Age:" << Age << " Coordinates:";
        A.PrintFunction1();
        cout << "\n";
    }
    void IncreaseCoordinates_Move() //function to increase coordinates
    {
        int x = A.GetCoordinateX();
        int y = A.GetCoordinateY();
        x=x+1;
        y=y+1;
        A.SetCoordinateX(x);
        A.SetCoordinateY(y);
    }

    Creature& FunctionMod_Name(char* N)
    {
        delete[] name;
        name = new char[strlen(N) + 1];
        strcpy_s(name, strlen(N) + 1, N);
        return *this;
    }
    Creature& FunctionMod_Age(int a)
    {
        Age = a;
        return *this;
    }
    Creature& FunctionMod_Coordinates(Coordinates P)
    {
        A = P;
        return *this;
    }

};

int main()
{
    int x, y, x1, y1, Age,V;
    char Name[10];
    char *Name1[10];
    Coordinates location1;
    cout << "location1 was created using default constructor\n";
    cout << "Lets create your location2 using constructor with parameters\n";
    cout << "Enter x:";
    cin >> x;
    cout << "\nEnter y:";
    cin >> y;
    Coordinates location2(x, y);
    Coordinates location3 = location2;
    cout << "\nlocation3 was created using copy constructor\n";
    cout << "\nThis is location1, location2, location3 \n\n";
    location1.PrintFunction2();
    location2.PrintFunction2();
    location3.PrintFunction2();

    cout << "\nEnter your creature's name:";
    cin >> Name;
    cout << "\nAge:";
    cin >> Age;
    cout << "\nLocation:";
    cin >> x1 >> y1;
    Coordinates location4(x1, y1);

    Creature creature1;
    Creature creature2(Name,Age,location4);
    Creature creature3 = creature2;
    cout << "\nThis is creature1, creature2, creature3:\n\n ";
    creature1.PrintInfoFull();
    creature2.PrintInfoFull();
    creature3.PrintInfoFull();
    
    

    while (1)
    {   
        cout << "\n\nWhich of them would you like to move?(Press 1/2/3): ";
        cin >> V;
        switch (V)
        {
        case 1:
        {
            creature1.IncreaseCoordinates_Move();
            cout << "\nNow your new position for ";
            creature1.PrintName();
            cout << " is:";
            creature1.PrintPositionInfo();
        }break;
        case 2:
        {
            creature2.IncreaseCoordinates_Move();
            cout << "\nNow your new position for ";
            creature2.PrintName();
            cout << " is:";
            creature2.PrintPositionInfo();
        }break;
        case 3:
        {
            creature3.IncreaseCoordinates_Move();
            cout << "\nNow your new position for ";
            creature3.PrintName();
            cout << " is:";
            creature3.PrintPositionInfo();
        }break;
        }
    }
    return 0;
}

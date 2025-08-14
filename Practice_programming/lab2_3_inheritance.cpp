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
        cout << "Default_constr.Coordinates worked here\n";
    }
    Coordinates(int x, int y) //constructor using parameters
    {
        CoordinateX = x;
        CoordinateY = y;
        cout << "Parameter_constructor.Coordinates worked here\n";
    }
    Coordinates(const Coordinates& coord) //copy constructor
    {
        CoordinateX = coord.CoordinateX;
        CoordinateY = coord.CoordinateY;
        cout << "Copy_constructor.Coordinates worked here\n";
    };

    ~Coordinates() //destructor
    {
        cout << "Destructor.Coordinates worked here\n";
    };

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
        int Coord_x, Coord_y;
        Coord_x = GetCoordinateX();
        Coord_y = GetCoordinateY();
        cout << Coord_x << " " << Coord_y;
    }
    void PrintFunction2()
    {
        int Cord_x = GetCoordinateX();
        int Cord_y = GetCoordinateY();
        cout << "\nCoordinates X:" << Cord_x << " Y:" << Cord_y << "\n";
    }
};

class Form_of_Life //basic class
{ 
protected:
    Coordinates A;
public:
   

    Form_of_Life()
    {
        cout << "Default_constr.Form_of_Life worked here\n";
    };
    Form_of_Life(int x, int y): A(x,y)
    {
        cout << "Parameter_constructor.Form_of_Life worked here\n";
    };
    Form_of_Life(Form_of_Life& form):A(form.A)
    {
        cout << "Copy_constructor.Form_of_Life worked here\n";
    };

    ~Form_of_Life()
    {cout << "destructor.Form_of_life worked here\n";}

    void move()
    { 
        A.PrintFunction1();       
    }
};

class Creature:public Form_of_Life
{
protected:
    char* name;
    int Age;
    int living;
public:

    char* GetName()
    { return name; }

    int GetAge()
    { return Age;}

    void SetAge(int a)
    {
        Age = a;
    }

    Coordinates GetCoordinates()
    { return A;}

    int GetLiving()
    {return living;}

    Creature() //default (basic) constructor
    {
        name = new char[10];
        strcpy_s(name, 10, "somename");
        Age = 0;
        living = 0;
        cout << "Default_constructor.Creature worked here\n";
    }
    Creature(char* name2, int age, int x, int y):Form_of_Life(x,y) //constructor with parameters
    {
        name = new char[strlen(name2) + 1];
        strcpy_s(name, strlen(name2) + 1, name2);
        Age = age;
        living = 1;
        cout << "Parameter_constructor.Creature worked here\n";
    }
    Creature(Creature& my_creature):Form_of_Life(my_creature) //copy constructor
    {
        name = new char[strlen(my_creature.name) + 1];
        strcpy_s(name, strlen(my_creature.name) + 1, my_creature.name);
        Age = my_creature.Age;
        living = my_creature.living;
        cout << "Copy_constructor.Creature worked here\n";
    }

    ~Creature() //destructor
    {
        if (name)
            delete[] name;
        cout << "Destructor.Creature worked here\n";
    };

    void PrintPositionInfo()
    {
        A.PrintFunction1();
    }
    void PrintName()
    {
        cout << name;
    }

    void PrintInfoCreatureFull()
    {
        std::cout << "\n\nCreature Name:" << name << " Age:" << Age << " Coordinates:";
        A.PrintFunction1();
        cout << " Living: "<<living<<"\n\n";
    }
    void Increase_Age_and_Coordinates_Move(int max_age) //function to increase coordinates and age 
    {
        int x = A.GetCoordinateX();
        int y = A.GetCoordinateY();
        x = x + 1;
        y = y + 1;
        A.SetCoordinateX(x);
        A.SetCoordinateY(y);
        cout << "\nCoordinates were increased and set\n";
        int m=GetAge();
        m++;
        if (m > max_age)
        {
            cout<<"\nCreature's life is over, living is 0";
            living = 0;
        }
        else
        {
            SetAge(m);
            cout << "\nNew age was set";
        }

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

class Predator :public Creature
{
    int max_age;
public:
    Predator() :Creature()
    {
        max_age = 10;
        cout << "+Default_constructor.Predator worked here\n";
    }
    Predator(int max_age_predator, char* name, int age, int x, int y) :Creature(name, age, x, y)
    {
        max_age = max_age_predator;
        cout << "+Parameter_constructor.Predator worked here\n";
    }
    Predator(Predator& my_predator) :Creature(my_predator)
    {
        max_age = my_predator.max_age;
        cout << "+Copy_constructor.Predator worked here\n";
    }
    ~Predator()
    {
        cout << "Destructor.Predator worked here\n";
    }
    int GetMaxAge_Predator()
    {return max_age;}
    void PrintInfoPredator()
    {
        std::cout << "\n\nMax age of predator(life limit):" << max_age << " Predator Name:" << name << " Age:" << Age << " Coordinates: ";
        A.PrintFunction1();
        cout << " Living: " << living << "\n\n";
    }
};

class Prey:public Creature
{
protected:
    int max_age;
public:
    Prey():Creature()
    {
        max_age = 12;
        cout << "+Default_constructor.Prey worked here\n";
    }
    Prey(int max_age_prey, char* name, int age, int x, int y) :Creature(name, age, x, y)
    {
        max_age = max_age_prey;
        cout << "+Parameter_constructor.Prey worked here\n";
    }
    Prey(Prey& my_prey):Creature(my_prey)
    {
        max_age = my_prey.max_age;
        cout << "+Copy_constructor.Prey worked here\n";
    }
    ~Prey()
    {
        cout << "Destructor.Prey worked here\n";
    }
    int GetMaxAge_Prey()
    {return max_age;}

    void PrintInfoPrey()
    {
        std::cout << "\n\nMax age of prey(life limit):"<<max_age<<" Prey Name: " << name << " Age: " << Age << " Coordinates: ";
        A.PrintFunction1();
        cout << " Living: " << living << "\n\n";
    }
};

class Plant:public Form_of_Life //derivative class
{
protected:
    char* plant_name; 
public:
   
    Plant()
    {
        plant_name = new char[20];
        strcpy_s(plant_name, 20, "plant_somename");
        cout << "+Default_constr.Plant worked here\n";
    }
    Plant(char* PN, int x, int y):Form_of_Life(x, y)
    {
        plant_name = new char[strlen(PN) + 1];
        strcpy_s(plant_name, strlen(PN) + 1, PN);
        cout << "+Parameter_constructor.Plant worked here\n";
    }
    Plant(Plant& my_plant):Form_of_Life(my_plant)
    {
        plant_name = new char[200];
        strcpy_s(plant_name, 200, my_plant.plant_name);
        cout << "+Copy_constructor.Plant worked here\n";
    }
    ~Plant()
    {
        if (plant_name)
            delete[]plant_name;
        cout << "+Destructor.Plant worked here\n";
    }
    void PrintInfoPlant()
    {
        std::cout << "\n\nPlant name:" << plant_name << " Position:";
        A.PrintFunction1();
        cout << "\n";
    }
};

class Static_Object:public Form_of_Life
{
protected:
    char* obj_name;
public:
    Static_Object():Form_of_Life()
    {
        obj_name = new char[200];
        strcpy_s(obj_name, 200, "some object");
        cout << "+Default_constr.Static_Object worked here\n";
    }
    Static_Object(char* ON, int x, int y):Form_of_Life(x, y)
    {
        obj_name = new char[strlen(ON) + 1];
        strcpy_s(obj_name, strlen(ON) + 1, ON);
        cout << "+Parameter_constructor.Static_Object worked here\n";
    }
    Static_Object(Static_Object& my_object):Form_of_Life(my_object)
    {
        obj_name = new char[200];
        strcpy_s(obj_name, 200, my_object.obj_name);
        cout << "+Copy_constructor.Static_Object worked here\n";
    }
    ~Static_Object()
    {
        if (obj_name)
            delete[]obj_name;
        cout << "Destructor.Static_Object worked here\n";
    }
    void PrintInfoStaticObject()
    {
        std::cout << "\n\nObject's name:" << obj_name << " Position:";
        A.PrintFunction1();
        cout << "\n";
    }
};



int main()
{
    char name_c[20];
    char name_pl[20];
    char name_obj[20];
    char name_pred[20];
    char name_prey[20];
    int age, age1, age2, max_age_pred,max_age_prey,x, y,x1,y1,x2,y2,x3,y3,x4,y4;
    int V,XM;
    XM = 3;
    cout << "Creating 3 creatures(Default,parametric and copied)\n\n";
    Creature a;
    cout << "\n|------------------------------------------------------------------------------|\n";
    cout << "\nEnter parameter_creature's name: ";
    cin >> name_c;
    cout << "\nAge:";
    cin >> age;
    cout << "Position (x,y):";
    cin >> x;
    cin >> y;
    cout << "\n|------------------------------------------------------------------------------|\n";
    Creature b(name_c, age, x, y);
    Creature c(a);

    

    cout << "\n\nCreating 3 plants (Default,parametric and copied) and 3 static_objects(Default,parametric and copied):\n\n";
    Plant someplant;
    cout << "\n|------------------------------------------------------------------------------|\n";
    cout << "\nEnter parameter_plant's name:";
    cin >> name_pl;
    cout << "Position (x,y):";
    cin >> x1;
    cin >> y1;
    cout << "\n|------------------------------------------------------------------------------|\n";
    Plant p1(name_pl, x1, y1);
    Plant p2(p1);
    
    Static_Object someobject;
    cout << "\n|------------------------------------------------------------------------------|\n";
    cout << "\n\nEnter parameter_object's name:";
    cin >> name_obj;
    cout << "Position (x,y):";
    cin >> x2;
    cin >> y2;
    cout << "\n|------------------------------------------------------------------------------|\n";
    Static_Object M1(name_obj, x2, y2);
    Static_Object M2(M1);

    cout << "\n\nCreating 3 Predators and 3 Preys (derivative classes from Creature):\n\n";
    Predator default_predator;
    cout << "\n|------------------------------------------------------------------------------|\n";
    cout << "\nMax age of predator (life limit):";
    cin >> max_age_pred;
    cout << "\n\nEnter parameter_predator's name:";
    cin >> name_pred;
    cout << "\nAge:";
    cin >> age1;
    cout << "Position (x,y):";
    cin >> x3;
    cin >> y3;
    cout << "\n|------------------------------------------------------------------------------|\n";
    Predator T1(max_age_pred,name_pred, age1, x3, y3);
    Predator T2(T1);

    Prey default_prey;
    cout << "\n |------------------------------------------------------------------------------ |\n";
    cout << "\nMax age of prey (life limit):";
    cin >> max_age_prey;
    cout << "\n\nEnter parameter_prey's name:";
    cin >> name_prey;
    cout << "\nAge:";
    cin >> age2;
    cout << "Position (x,y):";
    cin >> x4;
    cin >> y4;
    cout << "\n|------------------------------------------------------------------------------|\n";
    Prey D1(max_age_prey, name_prey, age2, x4, x4);
    Prey D2(D1);

    cout << "\n\n\n|------------------------------------------------------------------------------|\nThe general info about your creatures and objects will be displayed below:\n";
    
    a.PrintInfoCreatureFull();
    b.PrintInfoCreatureFull();
    c.PrintInfoCreatureFull();

    someplant.PrintInfoPlant();
    p1.PrintInfoPlant();
    p2.PrintInfoPlant();

    someobject.PrintInfoStaticObject();
    M1.PrintInfoStaticObject();
    M2.PrintInfoStaticObject();

    default_predator.PrintInfoPredator();
    T1.PrintInfoPredator();
    T2.PrintInfoPredator();

    default_prey.PrintInfoPrey();
    D1.PrintInfoPrey();
    D2.PrintInfoPrey();

    cout << "\n\n|------------------------------------------------------------------------------|\n";

    while (XM!=0)
    {
        cout << "\n\nWhat would you like to do?\n";
        cout << "1-move predator\n2-move prey\n3-print info(predator)\n4-print info(prey)\n0-Exit program\n\n";
        cin >> V;
        switch (V)
        {
        case 1:
            {
            int max_age_P=T1.GetMaxAge_Predator();
            T1.Increase_Age_and_Coordinates_Move(max_age_P);
            }break;

        case 2:
            {
            int max_age_Pr = D1.GetMaxAge_Prey();
            D1.Increase_Age_and_Coordinates_Move(max_age_Pr);
            }break;

        case 3:
            {
            cout << "\nThere is info about your predator:";
            T1.PrintInfoPredator();
            }break;

        case 4:
            {
            cout << "\nThere is info about your prey:";
            D1.PrintInfoPrey();
            }break;
        case 0: 

           {
            XM = 0;
           }

        }
    }
    cout << "\nEnd of program\n\n";
}

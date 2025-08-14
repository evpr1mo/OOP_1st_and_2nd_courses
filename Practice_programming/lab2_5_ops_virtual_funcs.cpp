#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <time.h>
using namespace std;
#include <iostream>

class Coordinates
{
protected:


public:
    int CoordinateX;
    int CoordinateY;

    Coordinates() //default constructor
    {
        CoordinateX = 0;
        CoordinateY = 1;
        //cout << "Default_constr.Coordinates worked here\n";
    }
    Coordinates(int x, int y) //constructor using parameters
    {
        CoordinateX = x;
        CoordinateY = y;
        //cout << "Parameter_constructor.Coordinates worked here\n";
    }
    Coordinates(const Coordinates& coord) //copy constructor
    {
        CoordinateX = coord.CoordinateX;
        CoordinateY = coord.CoordinateY;
        //cout << "Copy_constructor.Coordinates worked here\n";
    };

    ~Coordinates() //destructor
    {
        //cout << "Destructor.Coordinates worked here\n";
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
    {
        CoordinateX = X;
    }

    void SetCoordinateY(int Y)
    {
        CoordinateY = Y;
    }

    int GetCoordinateX()
    {
        return CoordinateX;
    }

    int GetCoordinateY()
    {
        return CoordinateY;
    }

    void PrintFunction1()
    {
        int Coord_x, Coord_y;
        Coord_x = GetCoordinateX();
        Coord_y = GetCoordinateY();
        cout  <<"x:" << Coord_x << " " <<"y:" << Coord_y<<endl;
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
        //cout << "Default_constr.Form_of_Life worked here\n";
    };
    Form_of_Life(int x, int y) : A(x, y)
    {
        //cout << "Parameter_constructor.Form_of_Life worked here\n";
    };
    Form_of_Life(Form_of_Life& form) :A(form.A)
    {
        //cout << "Copy_constructor.Form_of_Life worked here\n";
    };
    friend istream& operator >> (istream& in, Form_of_Life& form)
    {
        int  CrdX, CrdY;
        in >> CrdX >> CrdY;  
        form.A.SetCoordinateX(CrdX);
        form.A.SetCoordinateY(CrdY);
        return in;
    }
    friend ostream& operator << (ostream& g, Form_of_Life c)
    {      
        return g << "Coordinates:"<<c.A.CoordinateX<<" "<< c.A.CoordinateY<<endl;
        
    }
    virtual ~Form_of_Life()
    {
        //cout << "destructor.Form_of_life worked here\n";
    }

   virtual void move_print()
    {
       cout << "Here is your Form_of_Life position:\n";
        A.PrintFunction1();
    }
};
class Field 
{
protected:
    int number;
    int S;
    Form_of_Life* p;
public:
    Field()
    {
        number = 0;
        S = 0;
    }
    Field(int numb, int s)
    { 
        S = s;
        p = new Form_of_Life[S];
        number = numb;
        
    }
  void input_and_print_info_Field()
  { 
      cout << "\nEnter new Forms_of_life coordinates:";
      for (int i = 0;i < S;i++)
      {
          cin >> p[i];
      }
      cout << "Object of class Field created:\n";
      cout << "\nYour mass" << number<<"["<<S<<"]:\n";
      for (int i = 0;i < S;i++)
      {
          cout<< p[i];
      }
          
  }
    ~Field()
    {
            if (p);
            delete[]p;   
    }
    Form_of_Life& operator [](int i)
    {
        return p[i];
    };
    
    
};
class Creature :public Form_of_Life
{
protected:
    char* name;
    int Age;

public:
    int living;
    char* GetName()
    {
        return name;
    }

    int GetAge()
    {
        return Age;
    }

    void SetAge(int a)
    {
        Age = a;
    }

    Coordinates GetCoordinates()
    {
        return A;
    }

    int GetLiving()
    {
        return living;
    }

    Creature() //default (basic) constructor
    {
        name = new char[10];
        strcpy_s(name, 10, "somename");
        Age = 0;
        living = 0;
        //cout << "Default_constructor.Creature worked here\n";
    }
    Creature(char* name2, int age, int x, int y) :Form_of_Life(x, y) //constructor with parameters
    {
        name = new char[strlen(name2) + 1];
        strcpy_s(name, strlen(name2) + 1, name2);
        Age = age;
        living = 1;
        //cout << "Parameter_constructor.Creature worked here\n";
    }
    Creature(Creature& my_creature) :Form_of_Life(my_creature) //copy constructor
    {
        name = new char[strlen(my_creature.name) + 1];
        strcpy_s(name, strlen(my_creature.name) + 1, my_creature.name);
        Age = my_creature.Age;
        living = my_creature.living;
        //cout << "Copy_constructor.Creature worked here\n";
    }

     ~Creature() //destructor
    {
        if (name)
            delete[] name;
        //cout << "Destructor.Creature worked here\n";
    };

    void move_print()
    {
        cout << "Here is your creature's info:\n";
    Form_of_Life::move_print();
        cout << "My name is:" << name << "  Age:" << Age<<endl;
    }
    void PrintName()
    {
        cout << name;
    }

    void PrintInfoCreatureFull()
    {
        std::cout << "\n\nCreature Name:" << name << " Age:" << Age << " Coordinates:";
        
        cout << " Living: " << living << "\n\n";
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
        int m = GetAge();
        m++;
        if (m > max_age)
        {
            cout << "\nCreature's life is over, living is 0";
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
    friend class Prey;
    Predator() :Creature()
    {
        max_age = 10;
        //cout << "+Default_constructor.Predator worked here\n";
    }
    Predator(int max_age_predator, char* name, int age, int x, int y) :Creature(name, age, x, y)
    {
        max_age = max_age_predator;
        //cout << "+Parameter_constructor.Predator worked here\n";
    }
    friend Predator& operator++ (Predator c)
    {
        c.Age++;
        return c;
    }
    friend ostream& operator<< (ostream& o, Predator p)
    {
        return o << "Predator display: " <<
            "Max age of predator(life limit): " << p.max_age <<
            " Age: " << p.Age << "  Coordinates(x y): " << p.A.CoordinateX << " " << p.A.CoordinateY << "  living:" << p.living << "\n";
    }
    friend istream& operator >> (istream& in, Predator& g)
    {
        int max_age, Age, CrdX, CrdY;
        in >> max_age >> Age >> CrdX >> CrdY;
        g.SetMaxAge_Predator(max_age);
        g.SetAge(Age);
        g.A.SetCoordinateX(CrdX);
        g.A.SetCoordinateY(CrdY);
        return in;
    }
    Predator(Predator& my_predator) :Creature(my_predator)
    {
        max_age = my_predator.max_age;
        //cout << "+Copy_constructor.Predator worked here\n";
    }
    ~Predator()
    {
        //cout << "Destructor.Predator worked here\n";
    }

    void move_print()
    {
        cout << "Here is your predator info:\n";
        Creature::move_print();
        cout << "My max_age is:" << max_age << endl;
    }

    int GetMaxAge_Predator()
    {
        return max_age;
    }
    void SetMaxAge_Predator(int m)
    {
        max_age = m;
    }
    void PrintInfoPredator()
    {
        std::cout << "\n\nMax age of predator(life limit):" << max_age << " Predator Name:" << name << " Age:" << Age << " Coordinates: ";
        A.PrintFunction1();
        cout << " Living: " << living << "\n\n";
    }
};

class Prey :public Creature
{
protected:
    int max_age;
public:
    friend class Predator;
    Prey() :Creature()
    {
        max_age = 12;
        //cout << "+Default_constructor.Prey worked here\n";
    }
    Prey(int max_age_prey, char* name, int age, int x, int y) :Creature(name, age, x, y)
    {
        max_age = max_age_prey;
        //cout << "+Parameter_constructor.Prey worked here\n";
    }
    friend Prey& operator++ (Prey& d)
    {
        d.Age++;
        return d;
    }
    friend Prey operator-(Prey b, Predator c)
    {
        b.living = b.living - c.living;
        return b;
    }
    friend ostream& operator << (ostream& j, Prey x)
    {
        return j << "Prey display: " << "Max age of prey(life limit): " << x.max_age << " Age: " << x.Age << "  Coordinates(x y): " << x.A.GetCoordinateX() << " " << x.A.GetCoordinateY() << "  living:" << x.living << "\n";
    }
    friend istream& operator >> (istream& in, Prey& w)
    {
        int  Max_age, Age, CoordX, CoordY;
        in >> Max_age >> Age >> CoordX >> CoordY;
        w.SetMax_Age_Prey(Max_age);
        w.SetAge(Age);
        w.A.SetCoordinateX(CoordX);
        w.A.SetCoordinateY(CoordY);
        return in;
    }
    Prey(Prey& my_prey) :Creature(my_prey)
    {
        max_age = my_prey.max_age;
        //cout << "+Copy_constructor.Prey worked here\n";
    }
    ~Prey()
    {
       //cout << "Destructor.Prey worked here\n";
    }
    void move_print()
    {
        cout << "Here is your prey info:\n";
        Creature::move_print();
        cout << "My max_age is:" << max_age << endl;
    }
    int GetMaxAge_Prey()
    {
        return max_age;
    }
    void SetMax_Age_Prey(int m)
    {
        max_age = m;
    }
    void PrintInfoPrey()
    {
        std::cout << "\n\nMax age of prey(life limit):" << max_age << " Prey Name: " << name << " Age: " << Age << " Coordinates: ";
        A.PrintFunction1();
        cout << " Living: " << living << "\n\n";
    }
};

class Plant :public Form_of_Life //derivative class
{
protected:
    char* plant_name;
public:

    Plant()
    {
        plant_name = new char[20];
        strcpy_s(plant_name, 20, "plant_somename");
        //cout << "+Default_constr.Plant worked here\n";
    }

    Plant(char* PN, int x, int y) :Form_of_Life(x, y)
    {
        plant_name = new char[strlen(PN) + 1];
        strcpy_s(plant_name, strlen(PN) + 1, PN);
        //cout << "+Parameter_constructor.Plant worked here\n";
    }
    Plant(Plant& my_plant) :Form_of_Life(my_plant)
    {
        plant_name = new char[200];
        strcpy_s(plant_name, 200, my_plant.plant_name);
        //cout << "+Copy_constructor.Plant worked here\n";
    }
    ~Plant()
    {
        if (plant_name)
            delete[]plant_name;
        //cout << "+Destructor.Plant worked here\n";
    }
    void PrintInfoPlant()
    {
        std::cout << "\n\nPlant name:" << plant_name << " Position:";
        A.PrintFunction1();
        cout << "\n";
    }
};

class Static_Object :public Form_of_Life
{
protected:
    char* obj_name;
public:
    Static_Object() :Form_of_Life()
    {
        obj_name = new char[200];
        strcpy_s(obj_name, 200, "some object");
        //cout << "+Default_constr.Static_Object worked here\n";
    }
    Static_Object(char* ON, int x, int y) :Form_of_Life(x, y)
    {
        obj_name = new char[strlen(ON) + 1];
        strcpy_s(obj_name, strlen(ON) + 1, ON);
        //cout << "+Parameter_constructor.Static_Object worked here\n";
    }
    bool operator== (Static_Object& n)
    {
        return (n.A.CoordinateX == A.CoordinateX) && (n.A.CoordinateY == A.CoordinateY);
    }
    Static_Object(Static_Object& my_object) :Form_of_Life(my_object)
    {
        obj_name = new char[200];
        strcpy_s(obj_name, 200, my_object.obj_name);
        //cout << "+Copy_constructor.Static_Object worked here\n";
    }
    ~Static_Object()
    {
        if (obj_name)
            delete[]obj_name;
        //cout << "Destructor.Static_Object worked here\n";
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
    char name_pr[20],name_prey[20];
    Form_of_Life* arr[10];
    Field*arrS[10];
    arr[0] = new Form_of_Life(22, 1);
    cout << "========================================= Lets demonstrate the work of a virtual function ================================\n\n\n ";
    cout << "Enter your creature's name:";
    cin >> name_c;
    cout << "\n";
    arr[1] = new Creature(name_c, 12, 1, 1);
    cout << "Enter your predator's name:";
    cin >> name_pr;
    cout << "\n";
    arr[2] = new Predator(15, name_pr, 7, 4, 4);
    cout << "Enter your prey's name:";
    cin >> name_prey;
    cout << "\n";
    arr[3] = new Prey(16, name_prey,9, 5,5 );


    for (int i = 0;i < 4;i++)
    {
        arr[i]->move_print();
        cout << "--------------------------------------------\n";
    }
    cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~Creating your new object of class Field~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    cout << "Your new class Field:\n";
    int m = 0;
    int S = 4;
    Form_of_Life p[5];
 
    Field M1(m, S);
  
        M1.input_and_print_info_Field()
    return 0;
}

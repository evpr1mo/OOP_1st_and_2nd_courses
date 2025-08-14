#include <cstdlib>
#include <time.h>
using namespace std;
#include <iostream>
#include <vector>

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
    bool operator >(int i)
    {
        return this->CoordinateX * this->CoordinateY > i;
    }
    friend ostream& operator << (ostream& m, Coordinates c)
    {
        return m << "Coordinate:" << c.CoordinateX << " " << c.CoordinateY << endl;

    }

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
        cout << "x:" << Coord_x << " " << "y:" << Coord_y << endl;
    }
    void PrintFunction2()
    {
        int Cord_x = GetCoordinateX();
        int Cord_y = GetCoordinateY();
        cout << "\nCoordinates X:" << Cord_x << " Y:" << Cord_y << "\n";
    }
};
template <class T>

int print_vector(vector<T> a)
{
    int m = 0;
    cout << "\nYour elements of the array:\n";
    for (int i = 0;i < a.size();i++)
    {
        cout << a[i] << " ";
    }
    return m;
}
template <class T>
int count(vector<T> a, int val)
{
    int counter = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > val) { counter++; }
    }
    return counter;
}


int main()
{
    int val;
    cout << "Enter your value:";
    cin >> val;
    vector<int> num_int = { 3, 4, 7, 1, 2, 5, 9, 2, 3, 21 };
    vector<double> num_double = { 2.1, 6.4, 8.7, 1.7, 5.7 };
    vector<Coordinates> num_coordinates = { Coordinates(1,6), Coordinates(2,3), Coordinates(-2,9), Coordinates(3,8), Coordinates(20,6) };
    cout << "\nThese are your containers:\n\n";
    cout << "\nContainer num_int: ";
    print_vector(num_int);
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\nContainer num_double: ";
    print_vector(num_double);
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\nContainer num_coordinates: ";
    print_vector(num_coordinates);
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << endl << "Number of elements matching the requirement (>" << val << "):" << endl;
    cout << "container int: " << count(num_int, val) << endl;
    cout << "container double: " << count(num_double, val) << endl;
    cout << "container Coord: " << count(num_coordinates, val) << endl;
    return 0;
}

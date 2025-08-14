#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;

struct Coordinates
{
    char PointName;
    int coordinateX;
    int coordinateY;
    int coordinateZ;
};


void PrintArray(int a, Coordinates p[])
{
    int i = 0;
    cout << "Here are your points:\n";
    for (i = 0;i < a;i++)
    {
        cout << p[i].PointName;
        cout << "(";
        cout << p[i].coordinateX << ";" << p[i].coordinateY << ";" << p[i].coordinateZ;
        cout << ")";
        cout << "\n";
    }
}

void CreateArray(int a, Coordinates p[])
{
    int i = 0;
     do
     {   
        cout<< "Enter your point's name and coordinates as NAME X Y Z:\n";
        cin >> p[i].PointName>>p[i].coordinateX>>p[i].coordinateY>>p[i].coordinateZ;
        i++;

     } while (i < a);
}
int Count_Distanced_Points(double k, Coordinates p[], int a)
{
    int i,m = 0;
    double q;
    for (i = 0;i < a;i++)
    {
        q = sqrt(((p[i].coordinateX)*(p[i].coordinateX)) + ((p[i].coordinateY)*(p[i].coordinateY)) + ((p[i].coordinateZ)*(p[i].coordinateZ)));
        if (q > k)
        m++;
    }
    return m;
}

void PointsAlligned(Coordinates p[], int a)
{
    int i, m = 0; int j;
    double q,z,temp;
    double D[20],A[20];
    cout << "Unsorted array of distances:\n";
    for (i = 0;i < a;i++)
    {
        q = sqrt(((p[i].coordinateX) * (p[i].coordinateX)) + ((p[i].coordinateY) * (p[i].coordinateY)) + ((p[i].coordinateZ) * (p[i].coordinateZ)));
        D[i] = q;
        cout << D[i]<<" ";
    }
    cout << "\n";
    for (int i = 0; i < a - 1; i++) 
    {
        for (int j = 0; j < a - i - 1; j++) 
        {
            if (D[j] > D[j + 1]) 
            {
                temp = D[j];
                D[j] = D[j + 1];
                D[j + 1] = temp;
            }
        }
    }
    cout << "Sorted array of distances:\n";
    for (int i = 0; i < a; i++) 
    {
        cout << D[i] << " ";
    }
    cout << "\n\n";


    for (int j = 0;j < a;j++)
    {
        z= sqrt(((p[j].coordinateX)*(p[j].coordinateX)) + ((p[j].coordinateY)*(p[j].coordinateY)) + ((p[j].coordinateZ)*(p[j].coordinateZ)));
        A[j] = z;
    }

    for (i=0;i<a;i++) 
    {
        for (j = 0;j < a;j++)
        {
            if (D[i]==A[j])
            {
                cout << p[j].PointName;
                cout << "(";
                cout << p[j].coordinateX << ";" << p[j].coordinateY << ";" << p[j].coordinateZ;
                cout << ")";
                cout << "\n";
            }
            
        }
 
    }
}
void ElementAddition(Coordinates p[], int K, int a)
{
    int i = 0;
    i = a + 1;
    do 
    {
        p[i].PointName = p[i - 1].PointName;
        p[i].coordinateX = p[i - 1].coordinateX;
        p[i].coordinateY = p[i - 1].coordinateY;
        p[i].coordinateZ = p[i - 1].coordinateZ;
        i--;
    } while (i != (K + 1));
    cout << "Enter your new point's name and coordinates as NAME X Y Z:\n";
    cin >> p[K + 1].PointName >> p[K + 1].coordinateX >> p[K + 1].coordinateY >> p[K + 1].coordinateZ;
    cout << "Here are your added points:\n";
    for (i = 0;i <= a;i++)
    {
        cout << p[i].PointName;
        cout << "(";
        cout << p[i].coordinateX << ";" << p[i].coordinateY << ";" << p[i].coordinateZ;
        cout << ")";
        cout << "\n";
    }

}

void Delete_Element(Coordinates p[], int k, int a)
{
    int i = 0;
    for (i = k + 1;i < a-1;i++)
    {
        p[i].PointName = p[i + 1].PointName;
        p[i].coordinateX = p[i + 1].coordinateX;
        p[i].coordinateY = p[i + 1].coordinateY;
        p[i].coordinateZ = p[i + 1].coordinateZ;
    }
    cout << "Here are your remaining points:\n";
    for (i = 0;i < a-1;i++)
    {
        cout << p[i].PointName;
        cout << "(";
        cout << p[i].coordinateX << ";" << p[i].coordinateY << ";" << p[i].coordinateZ;
        cout << ")";
        cout << "\n";
    }
}

int main()
{
    Coordinates* p = new Coordinates[200];
    int i=0;
    int a,m,K,V=0;
    double k;
    char st[50];
    FILE* fp;
    errno_t r;
    
    while (1)
    {
        cout << "\n\nWhich function would you like to use - choose number: \n\n" << "1-Create array \n2-Print array\n3-Count distanced points \n";
        cout << "4-Allign points ascendingly by their distance from the point O(0;0;0) \n5-Add new point after the k point \n6-Delete the point after the k point\n7-Create file with points\n\n";
        cin >> V;

      switch (V)
      {
        case 1: 
        {
            cout << "How many points will be in your array? Please enter the number: ";
            cin >> a;
            cout << "\n\n";
            CreateArray(a, p);
        }break;
        
        case 2: if (p != NULL)
        {
            cout << "\n\n";
            PrintArray(a, p);
            cout << "\n\n";

        }break;
        
        case 3: if (p != NULL)
        {
            cout << "Please, enter your distance from the point O(0;0;0): ";
            cin >> k;
            cout << "\n";
            m = Count_Distanced_Points(k, p, a);
            cout << "\n";
            cout << "Here is your number of points outmatching the distance level:" << m << "\n";
        }break;
            
        case 4: if (p != NULL)
        {
            PointsAlligned(p, a);
        }break;

        case 5: if (p != NULL)
        {
            cout << "\n\n";
            cout << "Enter your number of point after which you want the new element to be added:";
            cin >> K;
            cout << "\n";
            ElementAddition(p, K, a);
            a++;
        }break;
        case 6:if (p != NULL)
        {
            cout << "\n\n";
            cout << "Enter your number of point after which you want the element to be deleted:";
            cin >> K;
            cout << "\n";
            Delete_Element(p, K, a);
            a--;
        }break;
        case 7:
        {
            if ((r = fopen_s(&fp, "out.txt", "w")) != 0)
            {
                cout << "Cannot open the file";
                exit(1);
            }
            for (i = 0;i < a;i++)
            {
                fprintf(fp, "%c (%d;%d;%d)\n", p[i].PointName, p[i].coordinateX, p[i].coordinateY, p[i].coordinateZ);
                
            }
            fclose(fp);
            cout << "File (out.txt) was successfully created, information about the points was retrieved into it";
        }break;
      }
    }
}

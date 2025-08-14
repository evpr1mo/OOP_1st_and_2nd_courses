#include <stdio.h>;
#include <stdlib.h>
#include  <ctime>

using namespace std;

/*
Develop and implement a sorting algorithm using counting, merging, and shaker sorting.
Generate an array of 1000 elements (with random elements); sort the resulting arrays in ascending order, obtaining the following variables: ComparisonNB - number of comparisons; ExchangeNB - number of exchanges.
*/


//---------------------------------- Functions for merge sorting -------------------------------------------
void merge(int*, int, int, int);

//--------------------------------- function which merges 2 divided arrays ---------------------------
void merge(int* arrB, int low, int top, int mid, int &ExchangeNB, int &ComparisonNB)
{
    int i1, j1, k1, c[1000];
    ComparisonNB=0, ExchangeNB=0;
    i1 = low;
    k1 = low;
    j1 = mid + 1;
    while (i1 <= mid && j1 <= top) //going through halves of divided array
    {
        
        if (arrB[i1] < arrB[j1]) //finding the smaller element and write it into temporary array  
        {
            ComparisonNB++;
            c[k1] = arrB[i1];
            ExchangeNB++;
            k1++;
            i1++;
        }
        else 
        {
            c[k1] = arrB[j1];
            ExchangeNB++;
            k1++;
            j1++;
        }
    }
    while (i1 <= mid)
    {
        
        c[k1] = arrB[i1];
        
        k1++;
        i1++;
    }
    while (j1 <= top) 
    {
        
        c[k1] = arrB[j1];
        
        k1++;
        j1++;
    }
    for (i1 = low; i1 < k1; i1++)
    {
        arrB[i1] = c[i1]; // extract sorted elements to the main array
    }
}
//----------------------------------------function which merges 2 sorted arrays----------------------------------

void merge_sort(int* arrB, int low, int top, int &p, int &g)
{
    int mid;
    if (low < top) 
    {
        mid = (low + top) / 2;     //divide the array at mid and sort independently using merge sort
        merge_sort(arrB, low, mid, p, g);
        merge_sort(arrB, mid + 1, top, p, g);
        int ExchangeNB, ComparisonNB;
        merge(arrB, low, top, mid, ExchangeNB, ComparisonNB);  // converging of the sorted arrays
        p = ExchangeNB;
        g = ComparisonNB;
    }
}

//-----------------------------------Swap function for shaker sorting method-------------------------------------
void swap(int* a, int* b) 
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------Function which sorts arrays using shaker sorting method--------------------------------
void ShakerSort(int arrC[], int m)
{
    int i, j, k;
    for (i = 0; i < m;) 
    {
        for (j = i + 1; j < m; j++) // moving from the left side to the right in the array, compare and swap if necessary
        {
            if (arrC[j] < arrC[j - 1])
                swap(&arrC[j], &arrC[j - 1]);
        }
        m--;//decreasing the size of the sorting array from the left size 

        for (k = m - 1; k > i; k--) //moving from the right side to the left, compare and swap if necessary
        {
            if (arrC[k] < arrC[k - 1])
                swap(&arrC[k], &arrC[k - 1]);
        }
        i++; //decreasing the side of the sorting array from the right side
    }
}
//----------------------------------------------------------------------------------------------------------

int main()
{
    int max,i, arrA[1000], count_arrA[1000], arrA1[1000];
    int arrB[1000];
    int arrC[1000];

    //-------------------------------Random array creation------------------------------------------------
    i = 0;
    srand(time(NULL));
    printf("Here is your random generated array A:\n ");
    for (i = 0; i < 1000; i++)
    {
        arrA[i] = rand() % 1000;
        arrB[i] = arrA[i];
        arrC[i] = arrA[i];
        printf("%d ", arrA[i]);
    }
    printf("\n\n");
    //---------------------------------------------------------------------------------------------------


        //------------------------Counting method--------------------------------------------------------
        max = arrA[0];
       int ComparisonNB = 0;
        int ExchangeNB = 0;
        int p;
        int g;
        for (i = 0;i < 1000;i++)
        {
            
            if (arrA[i] > max)
                max = arrA[i];//finding maximum in array A
        }

        for (i = 0;i <= max;++i)
        {
            count_arrA[i] = 0;//initialize elements of the count array to zeroes
        }

        for (i = 0; i < 1000; i++)
        {
            count_arrA[arrA[i]]++;   //increase number count in count array
        }

        for (i = 1;i <= max;i++)
        {
            count_arrA[i] = count_arrA[i] + count_arrA[i - 1]; //find cumulative frequency
        }
        for (i = 1000 - 1; i >= 0; i--)
        {
            arrA1[count_arrA[arrA[i]] - 1] = arrA[i]; //decrease count for same numbers
            count_arrA[arrA[i]]--;
        }
        for (i = 0; i < 1000; i++)
        {
            arrA[i] = arrA1[i]; //extract the sorted values to main array
        }
        printf("Here is your sorted (by counting method) array A:\n");
        for (int i = 0; i < 1000; ++i)
        {
            printf("%d  ", arrA[i]);
        }
        printf("\n");
        printf("Number of comparisons: %d\n", ComparisonNB);
        printf("Number of exchanges: %d", ExchangeNB);
        printf("\n\n");
        //----------------------------------------------------------------------------------

       

        //-------------------------Merge Sorting method (final output of array B using merge_sort function)---------------------------------------
        
        merge_sort(arrB, 0, 1000 - 1, p, g);
            printf("Here is your sorted (by merging method) array B\n");
            for (int i = 0; i < 1000; i++)
            {
                printf("%4d", arrB[i]);
            }
            printf("\n");
            printf("Number of comparisons: %d\n", g);
            printf("Number of exchanges: %d", p);
            printf("\n\n");
        //-------------------------------------------------------------------------------------


        //--------------------------Shaker sorting method (final output of array C using shaker swap functions)--------------------------------
            int j, k,m;
            ComparisonNB = 0;
            ExchangeNB = 0;
            m = 1000;
            for (i = 0; i < m;)
            {
                for (j = i + 1; j < m; j++) // moving from the left side to the right in the array, compare and swap if necessary
                {
                    ComparisonNB++;
                    if (arrC[j] < arrC[j - 1])
                        swap(&arrC[j], &arrC[j - 1]);
                    ExchangeNB ++;
                }
                m--;//decreasing the size of the sorting array from the left size 

                for (k = m - 1; k > i; k--) //moving from the right side to the left, compare and swap if necessary
                {
                    ComparisonNB++;
                    if (arrC[k] < arrC[k - 1])
                        swap(&arrC[k], &arrC[k - 1]);
                    ExchangeNB ++;
                }
                i++; //decreasing the side of the sorting array from the right side
            }
            printf("Here is your sorted (by shaker sorting method) array C\n");
            for (i = 0; i < 1000; i++)
            {
                printf("%4d", arrC[i]);
            }
            printf("\n");
            printf("Number of comparisons: %d\n", ComparisonNB);
            printf("Number of exchanges: %d", ExchangeNB);
            return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <iostream>
#include "Vector3D.h"


using namespace std;

extern "C"
{
    void SayHelloFromCpp()
    {
        Vector3D v = Vector3D(1,1,1);
        cout << "The norm of the vector is: " << v.Norm() << endl;
        v.PrintCores();

        printf("Now from c++ \n");
        #pragma omp parallel for
        for(int i = 0; i < 4; i++)
        {
            printf("Hello from thread %d \n", omp_get_thread_num());
        }
    }

    void PrintArray(double *pyhtonArray, int size, int x, int y, int z)
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Vector[" << i << "] = " << pyhtonArray[i] << endl;
        }
        
        cout << "Now in matrix form:" << endl;

        for (int k = 0; k < z; k++)
        {
            cout << "z = "<< k << endl;
            for (int j = 0; j < y; j++)
            {
                cout << "[" ;
                for (int i = 0; i < x; i++)
                {
                    int index = i + j * x + k * x * y;
                    cout << pyhtonArray[index] << " ";
                }
                cout << "]" << endl; 
            }
            cout << endl;
        }
        
    }
}
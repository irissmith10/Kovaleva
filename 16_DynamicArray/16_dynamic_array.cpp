#include <iostream>
using namespace std;

int main()
{
    int M = 3;
    int N = 3;
    int K = 3;
    int*** matrix;
    int a = 1;
    matrix = new int**[M]; 
    for ( int i = 0; i < M; i++) 
    {
        matrix[i] = new int*[N];
        for ( int j = 0; j < N; j++) 
        {
            matrix[i][j] = new int[K];
        }
    }

    for ( int i = 0; i < M; i++) // ввод 
        for ( int j = 0; j < N; j++) 
            for ( int k = 0; k < K; k++) 
            {
                matrix[i][j][k] = a;
                a++;
            }
    
    for ( int i=0; i < M; i++ )
        for ( int j = 0; j < N; j++ )
            for ( int k = 0; k < K; k++)
                cout << "i = " << i << "; j = " << j << "; k = " << k << "; element = " << matrix[i][j][k] << endl; 


    for ( int i=0; i < M; i++ )
        for ( int j = 0; j < N; j++ )   
            delete [] matrix[i][j];             
    return 0;


}
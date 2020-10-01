#include<iostream>
#include<stdlib.h>
using namespace std;

void display(int a[20][20], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        cout << "\n";
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
    }
}
void sparse(int a[20][20], int b[20][20], int m, int n)
{
    int k = 1;
    b[0][0] = m;
    b[0][1] = n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != 0)
            {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
    b[0][2] = k - 1;
}

void transpose(int b[20][20], int c[20][20])
{
    for (int j = 0; j < 3; j++)
        for (int i = 0; i <= b[0][2]; i++)
            c[j][i] = b[i][j];
}
void main()
{
    int a[20][20], b[20][20], c[20][20], m, n;
    cout << "Enter no of rows and columns:\n";
    cin >> m >> n;
    cout << "Enter the elements:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << "\nThe matrix you have entered is:\n";
    display(a, m, n);
    sparse(a, b, m, n);
    cout << "\nSparse Matrix:";
    int m2 = b[0][2] + 1, n2 = 3;
    display(b, m2, n2);
    transpose(b, c);
    cout << "\nTranspose of the sparse matrix:";
    display(c, n2, m2);
}
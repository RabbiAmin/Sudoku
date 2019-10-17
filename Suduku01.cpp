#include <bits/stdc++.h>
using namespace std;
#define UNASSIGNED 0 // for unassigned value
#define N 9 //sudoku size N*N
bool UnassignedAddress (int cell[N][N],int &row, int &colum);
bool legal(int cell[N][N], int row, int colum, int number);// Checks its legal or not

bool solution(int cell[N][N])
{
    int row, colum;
        if (!UnassignedAddress(cell, row, colum))
         return true;

        for (int number = 1; number <= 9; number++)
        {

            if (legal(cell, row, colum, number))
        {

            cell[row][colum] = number;

            if (solution(cell))
                return true;


     2       cell[row][colum] = UNASSIGNED;
        }
    }
    return false;
}


bool UnassignedAddress(int cell[N][N],int &row, int &colum)
{
    for (row = 0; row < N; row++)
        for (colum = 0; colum < N; colum++)
            if (cell[row][colum] == UNASSIGNED)
                return true;
                return false;
}


bool Row(int cell[N][N], int row, int number )
{
    for (int colum = 0; colum < N; colum++)
        if (cell[row][colum] == number)
            return true;
            return false;
}


bool Colum(int cell[N][N], int colum, int number)
{
    for (int row = 0; row < N; row++)
        if (cell[row][colum] == number)
            return true;
    return false;
}


bool Box(int cell[N][N], int boxStartRow, int boxStartColum, int number)
{
    for (int row = 0; row < 3; row++)
        for (int colum = 0; colum < 3; colum++)
            if (cell[row + boxStartRow]
                    [colum + boxStartColum] == number)
                return true;
    return false;
}


bool legal(int cell[N][N], int row,int colum, int number)
{

    return !Row  (cell, row, number) &&
           !Colum(cell, colum, number) &&
           !Box  (cell, row - row % 3 , colum - colum % 3, number) &&
           cell[row][colum] == UNASSIGNED;
}


void print(int cell[N][N])
{
    for (int row = 0; row < N; row++)
    {
    for (int colum = 0; colum < N; colum++)
            cout << cell[row][colum] << " ";
        cout << endl;
    }
}


int main()
{

    int cell[N][N] = {{0, 0, 0, 2, 6, 0, 7, 0, 1},
                      {6, 8, 0, 0, 7, 0, 0, 9, 0},
                      {0, 9, 0, 0, 0, 4, 5, 0, 0},
                      {8, 2, 0, 1, 0, 0, 0, 4, 0},
                      {0, 0, 4, 6, 0, 2, 9, 0, 0},
                      {0, 5, 0, 0, 0, 3, 0, 2, 8},
                      {0, 0, 9, 3, 0, 0, 0, 7, 4},
                      {0, 4, 0, 0, 5, 0, 0, 3, 6},
                      {7, 0, 3, 0, 1, 8, 0, 0, 0}};
    if ( solution(cell) == true)
        print(cell);
        //cout << "Successfully solved :) " ;
    else
        cout << "No solution exists";

    return 0;
}



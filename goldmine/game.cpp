#include "game.h"
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include "time.h"
#define MAX 100
using namespace std;

int G[MAX][MAX];
int game::getMaxGold(int goldmax[MAX][MAX], int m, int n)
{
    int right, diagonal_up, diagonal_down;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            G[i][j] = 0;
        }
    }

    for (int col = n - 1; col >= 0; col--)
    {
        for (int row = 0; row < m; row++)
        {

            if (col == n - 1)
                right = 0;
            else
            {
                right = G[row][col + 1];
            }

            if (row == 0 || col == n - 1)
            {
                diagonal_up = 0;
            }
            else
            {
                diagonal_up = G[row - 1][col + 1];
            }


            if (row == m - 1 || col == n - 1)
            {
                diagonal_down = 0;
            }
            else
            {
                diagonal_down = G[row + 1][col + 1];
            }



           G[row][col] = goldmax[row][col] + std::max(right, std::max(diagonal_up, diagonal_down));
        }
    }


    int reserve = G[0][0];
    for (int i = 1; i < m; i++)
    {
        reserve = std::max(reserve, G[i][0]);
    }
    return reserve;
}



int game::getUserGold(int m, int n, int gold[MAX][MAX])
{
   
    int col = 0, row = (rand()+time(0)) % 3;
    cout << "gold" << "[" << row << "]" << "[" << col << "]" << " = " << gold[row][col] << endl;
    int sum = gold[row][col];
    cout << "press 0 to move one step to right" << endl;
    cout << "press 1 to move one step diagonally up" << endl;
    cout << "press 2 move one step diagonally down" << endl;
    while (col != n - 1)
    {
        int controller;
       cin>> controller;
       switch (controller)
       {
           case 0:
               col++;
           break;


           case 1:
               col++;
               if (row > 0)
               {
                   row--;
               }
               break;

           case 2:
               col++;
               if (row < m)
               {
                   row++;
               }
               break;

           default:
               cout << "Invalid value, try entering a valid value \n";
               break;
       }
        cout<<"gold"<<"["<<row<<"]"<<"["<<col<<"]"<< " = "<<gold[row][col]<<endl;
        sum += gold[row][col];

    }

    return sum;
}

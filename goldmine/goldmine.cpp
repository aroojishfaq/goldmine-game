// goldmine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<conio.h>
#include "game.h"
#include <stdio.h>
#define MAX 100
using namespace std;
game A;
int main()
{
    int level = 1;

    int m = 4, n = 4, count = 0;

    int gold[MAX][MAX];


    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            gold[i][j] = 0;
        }
    }
    cout << "\t\t\t\t\t***WELCOME TO THE GOLDMINE GAME***\t\t\t\t\t" << endl;
    cout << ("\t\t\t\t\t\t***Level Simulation***\t\t\t\t\t\n");
    while (level <= 10)
    {

        switch (level)
        {
        case 1:

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    gold[i][j] = rand()%10;
                }
            }
            break;
        case 2:
            m = 5;
            n = 5;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    gold[i][j] = rand()%20;
                }
            }
            break;
        case 3:
            m = 6;
            n = 6;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    gold[i][j] = rand() % 30;;
                }
            }
            break;
        case 4:
            m = 7;
            n = 7;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    gold[i][j] = rand() % 40;
                }
            }
            break;
        case 5:
            m = 8;
            n = 8;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    gold[i][j] = rand() % 50;
                }
            }
            break;
        case 6:
            m = 9;
            n = 9;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    gold[i][j] = rand() % 60;
                }
            }
            break;
        case 7:
            m = 10;
            n = 10;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    gold[i][j] = rand() % 70;
                }
            }
            break;
        case 8:
            m = 11;
            n = 11;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    gold[i][j] = rand() % 80;
                }
            }
            break;
        case 9:
            m = 12;
            n = 12;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    gold[i][j] = rand() % 90;
                }
            }
            break;
        case 10:
            m = 13;
            n = 13;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    gold[i][j] = rand() % 100;
                }
            }
            break;

        }

        int sum = A.getUserGold(m, n, gold);

        int HighestAmountOfGold = A.getMaxGold(gold, m, n);

        cout << "\nHighestAmountOfGold at level" << level << ": " << HighestAmountOfGold << endl;
        cout << endl;
        cout<<"\nGold Collected: "<< sum;
        cout << endl;

        double r = ((double)sum / HighestAmountOfGold) * 100;

        int ratio = (int)r;

        cout<<"\nRatio ="<<ratio<<endl;
        cout << endl;

        if (ratio >= 60)
        {
            level++;
           cout<<"\nWelcome to level \n"<<level;
           cout << endl;
            count = 0;
        }
        else
        {
            count++;
            cout<<"You did not collect enough gold to proceed to the next level\nPlay Level Again\n";
            cout << endl;
        }

        if (count == 3)
        {
            count = 0;
            level = 1;
            cout<<"\n\t\t\t***** You Lost all of your lives *****\n    ";
            cout<<"\n\t\t\t***** Start again from level 1 *****\n    ";

        }
        
    }


   cout<<"Congratulations you have won the game";

   
}
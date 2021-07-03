#include <iostream>
#include "TTT_MediumGame.h"
#include "TTT_EasyGame.h"
using namespace std;
void TTT_MediumGame::add_move(char **arr, int width, int height, bool IsX)
{
    //the algorithm checking where he should to put the sign
    char sign;
    if (IsX == true)
        sign = 'X';
    else
        sign = 'O';
    for (int i = 0; i < width; i++)
    {

        //looking for logic move with the lines
        if ((arr[i][0] == arr[i][1] || arr[i][0] == arr[i][2] || arr[i][1] == arr[i][2]) && ((arr[i][0] != '-' && arr[i][1] != '-') || (arr[i][1] != '-' && arr[i][2] != '-') || (arr[i][2] != '-' && arr[i][0] != '-')) && (arr[i][0] == '-' || arr[i][1] == '-' || arr[i][2] == '-'))
        {
            if (arr[i][0] == '-')
                arr[i][0] = sign;
            else if (arr[i][1] == '-')
                arr[i][1] = sign;
            else if (arr[i][2] == '-')
                arr[i][2] = sign;
            return;
        }
    }
    if ((arr[0][0] == arr[1][1] || arr[0][0] == arr[2][2] || arr[1][1] == arr[2][2]) && ((arr[0][0] != '-' && arr[1][1] != '-') || (arr[2][2] != '-' && arr[1][1] != '-') || (arr[0][0] != '-' && arr[2][2] != '-')) && (arr[0][0] == '-' || arr[2][2] == '-' || arr[1][1] == '-'))
    { //diagonal from left to right
        if (arr[0][0] == '-')
        {
            arr[0][0] = sign;
            return;
        }
        if (arr[1][1] == '-')
        {
            arr[1][1] = sign;
            return;
        }
        if (arr[2][2] == '-')
        {
            arr[2][2] = sign;
            return;
        }
    }
    if ((arr[0][2] == arr[1][1] || arr[0][2] == arr[2][0] || arr[1][1] == arr[2][0]) && ((arr[0][2] != '-' && arr[1][1] != '-') || (arr[2][0] != '-' && arr[1][1] != '-') || (arr[0][2] != '-' && arr[2][0] != '-')) && (arr[0][2] == '-' || arr[2][0] == '-' || arr[1][1] == '-'))
    { //diagonal from right to left
        if (arr[0][2] == '-')
        {
            arr[0][2] = sign;
            return;
        }
        if (arr[1][1] == '-')
        {
            arr[1][1] = sign;
            return;
        }
        if (arr[2][0] == '-')
        {
            arr[2][0] = sign;
            return;
        }
    }
    for (int i = 0; i < height; i++)
    {//looking for logic move with the columns
        if ((arr[0][i] == arr[1][i] || arr[1][i] == arr[2][i] || arr[0][i] == arr[2][i]) && ((arr[0][i] != '-' && arr[1][i] != '-') || (arr[1][i] != '-' && arr[2][i] != '-') || (arr[2][i] != '-' && arr[0][i] != '-')) && (arr[0][i] == '-' || arr[1][i] == '-' || arr[2][i] == '-'))
        {
            if (arr[0][i] == '-')
                arr[0][i] = sign;
            else if (arr[1][i] == '-')
                arr[1][i] = sign;
            else if (arr[2][i] == '-')
                arr[2][i] = sign;
            return;
        }
    }
    //if there is no logic move make a random move
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (arr[i][j] == '-')
            {
                if (IsX == true)
                    arr[i][j] = 'X';
                else
                    arr[i][j] = 'O';
                return;
            }
        }
    }
}
int TTT_MediumGame::is_winner(char **arr, bool IsComputerX)
{
    TTT_EasyGame g;
    return g.is_winner(arr, IsComputerX);
}
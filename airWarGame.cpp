#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
using namespace std;
int height = 20;
int weight = 20;
int position_x=height/2;
int position_y=weight/2;


void gotoxy(int x,int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(out,pos);
}
int GetDirection()
{
    int ret = 0;
 
    do 
    {
        int ch = getch();
        if(isascii(ch))
            continue;
 
        ch = getch();
        switch(ch)
        {
        case 72:   
            ret = 2; // top
            break;
        case 75:   
            ret = 1; // left 
            break;
        case 77:   
            ret = 3; // right
            break;
        case 80:   
            ret = 4; // down
            break;
        default:   
            break;
        }
    } while (ret == 0);
     
    return ret;
}

int main()
{
    system("cls");//清屏函数
    gotoxy(position_x,position_y);//光标移动函数
    cout<<'*';
    system("pause");
}

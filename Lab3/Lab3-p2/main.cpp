// Lab3-p2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Canvas.h"
using namespace std;

int main()
{
    Canvas c(50, 20);

    c.DrawRect(5, 2, 20, 8, '#');
    c.FillRect(25, 3, 35, 10, '@');

    c.DrawCircle(12, 14, 4, '*');
    c.FillCircle(40, 15, 3, 'O');

    c.DrawLine(2, 2, 45, 18, '-');

    c.SetPoint(25, 15, 'X');

    c.Print();

    cout<<endl<<endl;
    c.Clear();

    c.DrawLine(0, 19, 49, 0, '/');
    c.Print();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

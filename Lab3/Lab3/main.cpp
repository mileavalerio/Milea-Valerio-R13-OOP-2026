// Lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Math.h"
using namespace std;


int main()
{
    int x = 5, y = 6, z = 7;
    double xx = 5.5, yy = 6.6, zz = 7.1;
    char s[] = "Un sir", t[] = "Inca un sir";

    cout << "Adunare pe intregi"<<endl;
    cout << Math::Add(x, y) << " " << Math::Add(x, y, z) << " "<< Math::Add(5, x, y, z, 40, 120) << endl;
    cout << "Adunare pe double" << endl;
    cout << Math::Add(xx, yy) << " "<< Math::Add(zz, yy, xx) << endl;
    cout << "Concatenare siruri" << endl;
    cout << Math::Add(s, t) << endl;

    return 0;

}



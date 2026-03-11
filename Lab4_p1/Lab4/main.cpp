// Lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Sort.h"

using namespace std;

int main()
{
    Sort s1(6, 10, 50);
    s1.Print();
    s1.BubbleSort(true);
    s1.Print();
    cout << endl;

    Sort s2({ 24, 7, 10, 2, 99 });
    s2.Print();
    s2.InsertSort(false);
    s2.Print();
    cout << endl;

    int v[] = { 100, 45, 23, 89, 12 };
    Sort s3(5, v);
    s3.Print();
    s3.QuickSort(true);
    s3.Print();
    cout << endl;

    Sort s4(4, 42, 17, 99, 3);
    s4.Print();
    s4.BubbleSort(false);
    s4.Print();
    cout << endl;

    Sort s5("10,40,100,5,70");
    s5.Print();
    s5.QuickSort();
    s5.Print();

    cout << "Count s5: " << s5.GetElementsCount() << endl;
    cout << "Element index 2 (s5): " << s5.GetElementFromIndex(2) << endl;

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

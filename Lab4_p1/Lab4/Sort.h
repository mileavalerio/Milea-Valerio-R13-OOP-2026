#pragma once
#include <initializer_list>
class Sort
{
    // add data members
    int* arr;
    unsigned int count;
    unsigned int capacity;
    void myQuickSort(int v[], int left, int right, bool ascendent = false);
public:
    // add constuctors
    Sort(unsigned int size, int minV, int maxV);
    Sort(std::initializer_list<int> list);
    Sort(unsigned int size, int v[]);
    Sort(unsigned int size, ...);
    Sort(const char* s);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
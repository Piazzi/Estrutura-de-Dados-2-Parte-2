#include <iostream>
#include <random>
#include <stdlib.h>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

class Saida
{
    public:
        ~Saida();
        ofstream quickSort;
        ofstream insertionSort;
        ofstream bubbleSort;
        ofstream heapSort;
        ofstream mergeSort;
        ofstream selectionSort;
        ofstream shellSort;
        ofstream quickSortMediana;
        ofstream quickSortInsercao;
        void getInsertion();
        void getMerge();
        void getQuick();
        void getSelection();
        void getBubble();
        void getHeap();
        void getShell();
        void getQuickMediana();
        void getQuickInsercao();
};

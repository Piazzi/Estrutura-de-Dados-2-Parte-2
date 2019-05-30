#include "Saida.h"

Saida::~Saida()
{
    mergeSort.close();
    insertionSort.close();
    quickSort.close();
    bubbleSort.close();
    selectionSort.close();
    shellSort.close();
    heapSort.close();
    quickSortMediana.close();
    quickSortInsercao.close();

}

void Saida::getInsertion()
{
    insertionSort.open("insertion.txt", ios::out);
}

void Saida::getMerge()
{
    mergeSort.open("merge.txt", ios::out);
}

void Saida::getHeap()
{
    heapSort.open("heap.txt", ios::out);
}

void Saida::getBubble()
{
    bubbleSort.open("bubble.txt", ios::out);
}

void Saida::getQuick()
{
    quickSort.open("quick.txt", ios::out);
}

void Saida::getShell()
{
    shellSort.open("shell.txt", ios::out);
}

void Saida::getSelection()
{
    selectionSort.open("selection.txt", ios::out);
}

void Saida::getQuickMediana()
{
    quickSortMediana.open("quickMediana.txt", ios::out);
}

void Saida::getQuickInsercao()
{
    quickSortInsercao.open("quickInsercao.txt", ios::out);
}

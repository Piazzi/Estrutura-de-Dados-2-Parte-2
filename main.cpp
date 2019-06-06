#include <iostream>
#include <random>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <bits/stdc++.h>
#include <chrono>
#include "Registro.h"
#include "Saida.h"
#include "Startup.h"


using namespace std;
using namespace std::chrono;

/// Variaveis do quickSort.cpp que registram as estatisticas;
extern int numComparacoes;
extern int numCopias;

/**
 * Função que troca o valor de duas vari�veis usando uma
 * variável auxiliar
 *
 * @param int *x
 * @param int *y
 * @return void
*/
void swap(int *x, int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}

/**
 * Função que gera um array de inteiros usando apenas a coluna UserId do ratings.csv
 *
 * @param Registro registros[]
 * @param int TAM
 * @return int*
*/
int *GeraVetorUserId(Registro registros[], int TAM)
{
    int *vetUserIds = new int();

    for (int i = 0; i < TAM; i++)
    {
        vetUserIds[i] = registros[i].getUserId();
    }

    return vetUserIds;
}

/**
 * Função responsável por efetuar as devidas chamadas de acordo com o algoritmo escolhido
 * além de distribuir os vetores para os algoritmos
 *
 * @param Registro registros[]
 * @param int userIds[]
 * @param int TAM
 * @param int algoritmo
 * @param ofstream &saida
 *
 * @return void
*/
void Distribuidor(Registro registros[], int userIds[], int algoritmo, ofstream &saida, int TAM)
{
    Startup startup;

    /*
    switch (algoritmo)
    {
    case 1:
        startup.StartInsertionSort(registros, userIds, TAM, saida);
        break;
    case 2:
        startup.StartHeapSort(registros, userIds, TAM, saida);
        break;
    case 3:
        startup.StartMergeSort(registros, userIds, 0, TAM, saida);
        break;
    case 4:
        startup.StartSelectionSort(registros, userIds, TAM, saida);
        break;
    case 5:
        startup.StartBubbleSort(registros, userIds, TAM, saida);
        break;
    case 6:
        startup.StartQuickSort(registros, userIds, 0, TAM - 1, saida);
        break;
    case 7:
        startup.StartQuickSortMediana(userIds, 0, TAM - 1, 5, saida);
        break;
    case 8:
    {
        int m;

        startup.StartQuickSortInsercao(userIds, 0, TAM - 1, 10, saida);
        break;
    }
    default:
        cout << "Fim." << endl;
        break;
    }
    */
}

Registro *GetRegistrosPorConjunto(ifstream &arquivo, int TAM)
{
    Registro *registros = new Registro[TAM];

    int tamanhoArquivo = arquivo.tellg();

    for (int j = 0; j < TAM; j++)
    {
        srand(time(NULL) * j * time(NULL));

        registros[j] = registros->pegarKbAleatorio(arquivo, registros[j], tamanhoArquivo);
    }

    return registros;
}

void Run(int algoritmo, ofstream &saida)
{
    ifstream arquivo;
    ifstream entrada;

    arquivo.open("ratings.csv");
    entrada.open("entrada.txt");

    if (arquivo.is_open())
    {
        arquivo.seekg(0, arquivo.end); // apontar para o final do arquivo

        while (!entrada.eof())
        {
            string tamanho;
            getline(entrada, tamanho);

            int TAM = atoi(tamanho.c_str()); // transformando tamanho para inteiro

            for (int i = 0; i < 5; i++) // rodar 5 vezes e gerar 5 conjuntos de elementos distintos de mesmo tamanho
            {
                Registro *registros = GetRegistrosPorConjunto(arquivo, TAM);
                int *userIds = GeraVetorUserId(registros, TAM);

                Distribuidor(registros, userIds, algoritmo, saida, TAM);
            }
        }
    }
}

void Menu()
{
    Saida saida;

    int option = -1;

        cout << "Escolha qual algoritmo voce quer usar: " << endl;
        cout << "[1] = Arvore Vermelho-Preto" << endl;
        cout << "[2] = Arvore B (d = 5)" << endl;
        cout << "[3] = Arvore B (d= 20)" << endl;
        cout << "[0] = Sair" << endl;

        cin >> option;
        /*
        switch (option)
        {
        case 1:
            saida.getInsertion();
            Run(1, saida.insertionSort);
            break;
        case 2:
            saida.getHeap();
            Run(2, saida.heapSort);
            break;
        case 3:
            saida.getMerge();
            Run(3, saida.mergeSort);
            break;
        }
        */

}

int main()
{

    Menu();
    return 0;
}

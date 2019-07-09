#include "No.h"
#include <iostream>

using namespace std;


/**
 * Construtor da classe
 *
*/
No::No()
{
    esquerda = nullptr;
    direita = nullptr;
    pai = nullptr;
    cor = 0;
}

No::~No()
{
    esquerda = nullptr;
    direita = nullptr;
    pai = nullptr;
}

bool No::getCor()
{
    return cor;
}

void No::setCor(bool novaCor)
{
    this->cor = novaCor;
}

int No::getValor()
{
    return valor;
}

void No::setValor(int novoValor)
{
    this->valor = novoValor;
}

No* No::getEsquerda()
{
    return esquerda;
}

void No::setEsquerda(No* no)
{
    this->esquerda = no;
}

No* No::getDireita()
{
    return direita;
}

void No::setDireita(No *no)
{
    this->direita = no;
}

No* No::getPai()
{
    return pai;
}

void No::setPai(No *no)
{
    this->pai = no;
}

int No::getAltura()
{
    return altura;
}

void No::setAltura(int novaAltura)
{
    this->altura = novaAltura;
}

void No::recolore()
{
    if(cor)
        cor = false;
    else
        cor = true;
}

#include "No.h"

using namespace std;

No::No(int valor)
{
    this->valor = valor;
    esquerdo = nullptr;
    direito = nullptr;
    pai = nullptr;
}

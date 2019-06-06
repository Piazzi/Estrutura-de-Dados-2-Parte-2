#include "ArvoreVermelhoPreto.h"
#include <stdio.h>

using namespace std;

ArvoreVermelhoPreto::ArvoreVermelhoPreto()
{
    raiz = nullptr;
}

void ArvoreVermelhoPreto::rotacionaEsquerda(No *&raiz, No *&no)
{
    No *direita = no->direito;

    no->direito = direita->esquerdo;

    if (no->direito != NULL)
        no->direito->pai = no;

    direita->pai = no->pai;

    if (no->pai == NULL)
        raiz = direita;

    else if (no == no->pai->esquerdo)
        no->pai->esquerdo = direita;

    else
        no->pai->direito = direita;

    direita->esquerdo = no;
    no->pai = direita;
}

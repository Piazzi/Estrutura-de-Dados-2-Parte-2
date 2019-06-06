#ifndef ARVOREVERMELHOPRETO_H_INCLUDED
#define ARVOREVERMELHOPRETO_H_INCLUDED
#include "No.h"

using namespace std;

class ArvoreVermelhoPreto
{
    public:
        ~ArvoreVermelhoPreto();
        No *raiz;
    protected:
        void rotacionaEsquerda(No *&, No *&);
        void rotacionaDireita(No *&, No *&);
        void corrigeViolacao(No *&, No *&);
    public:
        ArvoreVermelhoPreto();
        void inserir(const int &n);
        void inorder();
        void levelOrder();
};


#endif // ARVOREVERMELHOPRETO_H_INCLUDED

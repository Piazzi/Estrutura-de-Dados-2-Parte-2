#include "ArvoreB.h"
#include "Pagina.h"
#include "../Registro.h"


ArvoreB::ArvoreB()
{
    //ctor
    raiz = nullptr;
}

ArvoreB::ArvoreB(int ordem)
{
    //ctor
    raiz = nullptr;
    this->ordem = ordem;
}

ArvoreB::~ArvoreB()
{
    //dtor
}

void ArvoreB::insere(int n){
    if(raiz==nullptr){
        raiz->chaves[0]= n;
        raiz->numChaves++;
    }
    if(raiz->numChaves == 2*ordem+ 1){
        Pagina *novaPag = new Pagina(ordem,false);
        novaPag->filhos[0] = raiz;
        //novaPag->split(0,raiz);
        int i=0;
        if(novaPag->chaves[0]<n){
            i++;
        }
        //novaPag->filhos[i]->inserePaginaComEspaço(n);
        raiz = novaPag;
    }
    else{
        //raiz->inserePaginaComEspaco(n);
    }
}

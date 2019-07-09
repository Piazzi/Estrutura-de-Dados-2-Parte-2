#include "Pagina.h"
#include "ArvoreB.h"

Pagina::Pagina()
{
    //ctor
}

Pagina::Pagina(int ordem)
{
    //ctor
    this->minChaves = (2*ordem)-1;
}

Pagina::Pagina(int minChaves, bool ehFolha)
{
    //ctor
    this->minChaves = minChaves;
    this->ehFolha = ehFolha;
    this->chaves = new int [(2*minChaves)-1];
    this->filhos = new Pagina *[2*minChaves];
    this->numChaves = 0;
}

Pagina::~Pagina()
{
    //dtor
}

Pagina *Pagina::busca(int n){
    Pagina *atual = this;
    int i;
    for(i=0;i<atual->numChaves && n>atual->chaves[i];i++){
        //Percorre página para encontrar posição igual ou mais próxima a chave
    }
    if(chaves[i]==n){
        return atual;
    }
    if(atual->ehFolha==true){
        return nullptr;
    }
    return filhos[i]->busca(n);
}




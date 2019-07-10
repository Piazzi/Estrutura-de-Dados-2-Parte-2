#include <iostream>
#include "Pagina.h"
#include "ArvoreB.h"

using namespace std;

Pagina::Pagina()
{
    //ctor
}

Pagina::Pagina(int ordem)
{
    //ctor
    this->minChaves = ordem;
}

Pagina::Pagina(int ordem, bool ehFolha)
{
    //ctor
    this->minChaves = ordem;
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
            //percorre nó para encontrar chave
    }
    if(chaves[i]==n){
        return atual;
    }
    if(atual->ehFolha==true){
        return nullptr;
    }
    return filhos[i]->busca(n);
}
void Pagina::insereNaPagina(int n){
    int i = numChaves - 1;
    if(ehFolha == true){
        for(i;i>=0 && chaves[i]>n;i--){
            chaves[i+1]=chaves[i];
        }
        chaves[i+1]=n;
        numChaves+=1;
    }
    else{
        for(i;i>=0 && chaves[i]>n;i--){
        }
        if(filhos[i+1]->numChaves == (2*minChaves)-1){
            split(i+1,filhos[i+1]);
        }
        if(chaves[i+1]<n){
            i++;
        }
        filhos[i+1]->insereNaPagina(n);
    }
}


void Pagina::split(int k,Pagina *p){
    Pagina *pag = new Pagina(p->minChaves,p->ehFolha);
    pag->numChaves = minChaves - 1;
    for(int j = 0;j < minChaves - 1;j++){
        pag->chaves[j] = p->chaves[j+minChaves];
    }
    if (p->ehFolha == false)
    {
        for (int j = 0; j < minChaves; j++)
            pag->filhos[j] = p->filhos[j+minChaves];
    }


    p->numChaves = minChaves - 1;


    for (int j = numChaves; j >= k+1; j--)
        filhos[j+1] = filhos[j];

    filhos[k+1] = pag;


    for (int j = numChaves-1; j >= k; j--)
        chaves[j+1] = chaves[j];


    chaves[k] = p->chaves[minChaves-1];

    numChaves = numChaves + 1;
}

void Pagina::imprime(){
    int i = 0;
    for(i;i<numChaves;i++){
        if(ehFolha==false){
            filhos[i]->imprime();
        }
        std::cout << chaves[i] << " ";
    }
    if(ehFolha==true){
        filhos[i]->imprime();
    }
}






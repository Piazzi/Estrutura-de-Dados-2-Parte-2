#ifndef ARVOREVERMELHOPRETO_H_INCLUDED
#define ARVOREVERMELHOPRETO_H_INCLUDED
#include "No.h"
#include "Registro.h"

using namespace std;

class ArvoreVermelhoPreto
{
    public:

        ArvoreVermelhoPreto();
        ~ArvoreVermelhoPreto();
        No *libera(No *no);
        void imprimir();
        void inserir(int valor, Registro &registro);

    private:
        No *raiz;
        void imprimirNivel(No *no, int nivel);

        bool ehVazia();

        No* getTio(No *no);
        No* getIrmao(No *no);
        No* inserirNo(int valor, No* no, Registro &registro);

        No* verificarPropriedades(No *no);
        No* verificarRotacao(No *no);
        No* rotacaoSimplesEsquerda(No *avo);
        No* rotacaoSimplesDireita(No *avo);
        No* rotacaoDuplaDireitaEsquerda(No *avo);
        No* rotacaoDuplaEsquerdaDireita(No *avo);
        void remover(long int valor);
        No* removerNo(long int valor, No *no);
        No* netoVermelho(No *no);
        No* casoNoUmFilho(No *no);
        No* casoNoDoisFilhos(No *no, long int valor);
        No* casoNoFolha(No *no);
        No* buscaValor(int valor);

        void recolore(No *p);
        bool alturaNegra();
        int retornaCor(No *no);
        void setCor(No *no, bool cor);
        long int numRotacoes;
        long int numComparacoes;
};


#endif // ARVOREVERMELHOPRETO_H_INCLUDED

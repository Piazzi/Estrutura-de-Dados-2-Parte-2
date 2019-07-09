#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

#include <string>

using namespace std;

class No
{
    private:

        //enum Cor {vermelho, preto};
        int valor;
        bool cor; // 0 = vermelho / 1 = preto
        No *esquerda, *direita, *pai;
        int altura;

    public:
        ~No();
        No();
        int userId;
        string timestamps;
        int score;
        string title;

        void recolore();
        bool getCor();
        void setCor(bool cor);
        int getValor();
        void setValor(int valor);
        No *getEsquerda();
        void setEsquerda(No *no);
        No *getDireita();
        void setDireita(No *no);
        No *getPai();
        void setPai(No *no);
        int getAltura();
        void setAltura(int altura);
};


#endif // NO_H_INCLUDED

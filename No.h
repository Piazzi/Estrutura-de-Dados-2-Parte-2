#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

using namespace std;

class No
{
    public:
        ~No();
        No(int valor);
        enum Cor {vermelho, preto};
        int valor;
        bool cor;
        No *esquerdo, *direito, *pai;
};


#endif // NO_H_INCLUDED

#ifndef ARVOREB_H
#define ARVOREB_H
#include "Pagina.h"


class ArvoreB
{
    public:
        ArvoreB();
        ArvoreB(int ordem);
        virtual ~ArvoreB();
        int getOrdem();
        void insere(Pagina p);
        Pagina busca();

    protected:

    private:
        Pagina *raiz;
        int ordem;
};

#endif // ARVOREB_H

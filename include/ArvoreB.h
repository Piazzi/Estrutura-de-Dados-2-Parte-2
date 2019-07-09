#ifndef ARVOREB_H
#define ARVOREB_H
#include "Pagina.h"


class ArvoreB
{
    public:
        ArvoreB();
        ArvoreB(int ordem);
        virtual ~ArvoreB();
        void insere(int n);
        Pagina busca(int n);
        Pagina *raiz;
        int ordem;

    protected:

    private:

};

#endif // ARVOREB_H

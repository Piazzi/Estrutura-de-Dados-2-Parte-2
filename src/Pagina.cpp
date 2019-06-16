#include "Pagina.h"
#include "ArvoreB.h"

Pagina::Pagina()
{
    //ctor
}

Pagina::Pagina(int ordem)
{
    //ctor
    this->maxChaves = (2*ordem)-1;
}

Pagina::Pagina(int ordem, bool ehFolha)
{
    //ctor
    this->maxChaves = (2*ordem)-1;
    this->ehFolha = ehFolha;
}

Pagina::~Pagina()
{
    //dtor
}

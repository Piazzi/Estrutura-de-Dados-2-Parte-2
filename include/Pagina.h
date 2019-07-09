#ifndef PAGINA_H
#define PAGINA_H


class Pagina
{
    public:
        Pagina();
        Pagina(int minChaves);
        Pagina(int minChaves, bool ehFolha);
        virtual ~Pagina();
        //void insere(Registro registro);//adiciona chave na folha. Ordenar imediatamente após inserção.
        Pagina **filhos;//vetor de ponteiros para os filhos
        int *chaves;
        //Registro chaves[];//chaves da página
        int minChaves;//máximo de chaves
        int numChaves;//número de chaves atuais
        bool ehFolha;//boolean se a página é uma folha
        Pagina *busca(int n);

    protected:

    private:

};

#endif // PAGINA_H

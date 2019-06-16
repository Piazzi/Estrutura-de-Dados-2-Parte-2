#ifndef PAGINA_H
#define PAGINA_H


class Pagina
{
    public:
        Pagina();
        Pagina(int numChaves);
        Pagina(int numChaves, bool ehFolha);
        virtual ~Pagina();
        //void insere(Registro registro);//adiciona chave na folha. Ordenar imediatamente após inserção.


    protected:

    private:
        Pagina **filhos;//vetor de ponteiros para os filhos
        //Registro chaves[];//chaves da página
        int maxChaves;//máximo de chaves
        int numChaves;//número de chaves atuais
        bool ehFolha;//boolean se a página é uma folha
};

#endif // PAGINA_H

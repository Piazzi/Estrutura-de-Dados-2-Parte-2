#include "ArvoreVermelhoPreto.h"
#include <stdio.h>

using namespace std;

ArvoreVermelhoPreto::ArvoreVermelhoPreto()
{
    numRotacoes = 0;
}

ArvoreVermelhoPreto::~ArvoreVermelhoPreto()
{
    raiz = libera(raiz);
}

/**
 * Funcao para auxiliar o destrutor da classe. Deixa como nulo
 * o filho da direita e da esquerda do no passado como parametro,
 * alem de deixaro proprio no como nulo.
 * @param No
 * @return null
*/
No *ArvoreVermelhoPreto::libera(No *no)
{
    if (no != nullptr)
    {
        no->setEsquerda(libera(no->getEsquerda()));
        no->setDireita(libera(no->getDireita()));
        no = nullptr;
    }
    return nullptr;
}

/**
 * Verifica se a arvore esta vazia ou nao. Retorna true caso esteja
 * e false caso contrario
 * @return bool
*/
bool ArvoreVermelhoPreto::ehVazia()
{
    if(raiz->getValor() == NULL)
        return true;
    else
        return false;
}

/**
 * Verifica se a propriedade da altura negra esta sendo respeitada.
 * Os dois lados da arvore precisam ter o mesmo numero de nos pretos
 * @return bool
*/
bool ArvoreVermelhoPreto::alturaNegra()
{
    No *no = raiz;
    int contDireita = 0 ;
    int contEsquerda = 0;
    for(; no->getDireita() != nullptr; no = no->getDireita())
    {
        if(no->getCor())
            contDireita++;
    }

    for(no = raiz; no->getEsquerda() != nullptr; no = no->getEsquerda())
    {
        if(no->getCor())
            contEsquerda++;
    }

    if(contDireita == contEsquerda)
        return true;
    else
        return false;
}

/**
 * Retorna o tio do no passado por parâmetro
 * @param No
 * @return No
*/
No* ArvoreVermelhoPreto::getTio(No* no)
{
    No *avo = no->getPai()->getPai();
    if(avo != nullptr)
    {
        /// verifica qual é o tio do nó
        if(avo->getEsquerda() == no->getPai())
            return avo->getDireita();
        else
            return avo->getEsquerda();
    }
    else
        return nullptr;
}


/**
 * Retorna o irmão do no passado por parâmetro
 * @param No
 * @return No
*/
No* ArvoreVermelhoPreto::getIrmao(No* no)
{
    No *pai = no->getPai();
    if(pai != nullptr)
    {
        /// verifica quem é o irmão
        if(pai->getDireita() == no)
            return pai->getEsquerda();
        else
            return pai->getDireita();
    }
    else
        return nullptr;
}

/**
 * Recolore o nó passado por parâmetro. Se for vermelho vira preto
 * e se for preto vira vermelho.
 * @param No
 * @return
*/
void ArvoreVermelhoPreto::recolore(No*no)
{
    if(no->getCor())
        no->setCor(false);
    else
        no->setCor(true);
}

/**
 * Retorna o nó que possui o valor passado por parâmetro
 *
 * @param int, No
 * @return No
*/
No* ArvoreVermelhoPreto::buscaValor(int valor)
{
    No *no = this->raiz;
    if(no == nullptr)
        return nullptr;
    else
    {
        while(no != nullptr)
        {
            if(valor == no->getValor())
                return no;
            else
            {
                if(valor < no->getValor())
                    no = no->getEsquerda();
                else
                    no = no->getDireita();
            }
        }
        return nullptr;
    }
}

/**
 * Função de imprimir auxiliar
 *
 * @param int
 * @return
*/
void ArvoreVermelhoPreto::imprimir()
{
    imprimirNivel(this->raiz,0);
}

/**
 * Imprime a árvore por níveis
 *
 * @param No, int
 * @return
*/
void ArvoreVermelhoPreto::imprimirNivel(No*no, int nivel)
{
    if (no != nullptr)
    {
        cout << "(" << nivel << ")";
        for(int i = 1; i <= nivel; i++)
        {
            cout << "--";
        }

        cout << no->getValor();
        if(no->getCor())
        {
            cout << " (P)" << endl;
        }
        else
        {
            cout << " (V)" << endl;
        }
        imprimirNivel(no->getEsquerda(), nivel+1);
        imprimirNivel(no->getDireita(), nivel+1);
    }
}

/**
 * Insere um novo nó na árvore usando uma função auxiliar
 *
 * @param int, Registro
 * @return
*/
void ArvoreVermelhoPreto::inserir(int valor, Registro &registro)
{
    inserirNo(valor, this->raiz, registro);
}

/**
 * Insere um novo no na Arvore.
 * @param int, No, Registro
 * @return No
*/
No* ArvoreVermelhoPreto::inserirNo(int valor, No *no, Registro &registro)
{
    /// Caso 1: se a raiz está vazia, o nó a ser inserido será a nova raiz(de cor preta).
    if(ehVazia())
    {
        numComparacoes++;
        no->setValor(valor);
        no->setCor(1); /// preto
        cout << "Raiz adicionada" << endl;
        return no;
    }
    else
    {
        No *pai;
        /// procura aonde o no vai se encaixar e acha seu pai.
        while(no != nullptr)
        {
            numComparacoes++;
            pai = no;
                    cout << "aaa";

            if(valor < no->getValor())
                no = no->getEsquerda();
            else
                no = no->getDireita();
        }

        no->setCor(0); /// vermelho
        no->setPai(pai);
        no->setValor(valor);
        cout << "No adicionado com sucesso, valor: " << valor << endl;

        /// descobre se o no é filho esquerdo ou direito do pai
        if(valor > pai->getValor())
            pai->setDireita(no);
        else
            pai->setEsquerda(no);

        No*raiz;
        /// percorre a arvore para verificar se é necessário fazer alguma correção.
        while(no != nullptr)
        {
            numComparacoes++;
            no = verificarPropriedades(no);
            raiz = no;
            no = no->getPai();
        }
        return raiz;
    }
}

/**
 * Verifica se alguma propriedade da Árvore Vermelha-Preto foi quebrada
 * @param int, No, Registro
 * @return No
*/
No* ArvoreVermelhoPreto::verificarPropriedades(No*no)
{
    /// Caso 1: O nó é a raiz, nesse caso, o nó deve ser preto.
    if(ehVazia())
    {
        no->setCor(1);
        return no;
    }
    else
    {
        No *pai = no->getPai();
        No *tio = getTio(no);
        No *avo = pai->getPai();

        numComparacoes++;
        if(tio != nullptr)
        {
            /// Caso 2: Pai e tio são vermelhos, recolore pai, tio e avõ
            if(!(tio->getCor() && pai->getCor()))
            {
                avo->recolore();
                tio->recolore();
                pai->recolore();
            }
            /// Caso 3: Pai é vermelho e tio é preto. É necessário fazer alguma rotação.
            else
            {
                /// verifica qual rotação deverá ser feita
                no = verificarRotacao(no);
            }
        }

        return no;
    }

}

/**
 * Verifica qual rotação deve ser executada e em seguida à executa
 * @param No
 * @return No
*/
No* ArvoreVermelhoPreto::verificarRotacao(No*no)
{
    No *pai = no->getPai();
    No *avo = pai->getPai();

    numComparacoes++;
    if(avo->getEsquerda() == pai)
    {
        numComparacoes++;
        if(pai->getDireita() == no)
            avo = rotacaoDuplaEsquerdaDireita(avo);
        else
            avo = rotacaoSimplesDireita(avo);
    }
    else
    {
        numComparacoes++;
        if(pai->getDireita() == no)
            avo = rotacaoSimplesEsquerda(avo);
        else
            avo = rotacaoDuplaDireitaEsquerda(avo);
    }

    avo->recolore();
    avo->getEsquerda()->recolore();
    avo->getDireita()->recolore();
    return avo;
}

/**
 * Aplica uma rotação simples para a esquerda e retorna a posição certa do nó
 * @param No
 * @return No
*/
No* ArvoreVermelhoPreto::rotacaoSimplesEsquerda(No*avo)
{
    No *pai = avo->getDireita();
    No *a = avo->getEsquerda();
    No *b = pai->getEsquerda();
    No *p = avo->getPai();

    pai->setEsquerda(avo);
    avo->setEsquerda(a);
    avo->setDireita(b);

    if(!a)
        a->setPai(avo);

    if(!b)
        b->setPai(avo);

    avo->setPai(pai);
    pai->setPai(p);
    if(!p)
        p->setEsquerda(pai);

    return pai;
}

/**
 * Aplica uma rotação simples para a direita e retorna a posição certa do nó
 * @param No
 * @return No
*/
No* ArvoreVermelhoPreto::rotacaoSimplesDireita(No*avo)
{
    No *pai = avo->getEsquerda();
    No *a = avo->getDireita();
    No *b = pai->getDireita();
    No *p = avo->getPai();

    pai->setDireita(avo);
    avo->setDireita(a);
    avo->setEsquerda(b);

    if(!a)
        a->setPai(avo);

    if(!b)
        b->setPai(avo);

    avo->setPai(pai);
    pai->setPai(p);
    if(!p)
        p->setDireita(pai);

    return pai;
}

/**
 * Aplica uma rotação dupla e retorna a posição certa do nó
 * @param No
 * @return No
*/
No* ArvoreVermelhoPreto::rotacaoDuplaEsquerdaDireita(No *avo)
{
    No *pai = avo->getEsquerda();

    avo->setEsquerda(rotacaoSimplesEsquerda(pai));
    avo->getEsquerda()->setPai(avo);
    return rotacaoSimplesDireita(avo);
}

/**
 * Aplica uma rotação dupla e retorna a posição certa do nó
 * @param No
 * @return No
*/
No* ArvoreVermelhoPreto::rotacaoDuplaDireitaEsquerda(No*avo)
{
    No *pai = avo->getEsquerda();

    avo->setDireita(rotacaoSimplesDireita(pai));
    avo->getDireita()->setPai(avo);
    return rotacaoSimplesEsquerda(avo);
}

/**
 * Função auxiliar na hora de remover um nó
 * @param No
 * @return No
*/
No* ArvoreVermelhoPreto::casoNoUmFilho(No *p){
    No *aux; // auxiliar para a troca de valores

    // Verificar a existencia do filho direito ou esquerdo
    // Em ambos fazer a troca de valores, atualização dos filhos e remover o nó.
    numComparacoes++;
    if(p->getEsquerda() == nullptr){
        aux = p->getDireita();
        p->setValor(aux->getValor());
        p->setDireita(aux->getDireita());
        p->setEsquerda(aux->getEsquerda());
        delete aux;
    }
    else{
        aux = p->getEsquerda();
        p->setValor(aux->getValor());
        p->setDireita(aux->getDireita());
        p->setEsquerda(aux->getEsquerda());
        delete aux;
    }
    return p;
}

/**
 * Funcão auxiliar para fazer a troca de valores do nó que possui dois filhos.
 * Troca-se com o valor sucessor do nó p
 * @param No, long int
 * @return No
*/
No* ArvoreVermelhoPreto::casoNoDoisFilhos(No *p, long int valor){
    No *aux;

    aux = p->getDireita();
    while(aux->getEsquerda() != nullptr){
        numComparacoes++;
        aux = aux->getEsquerda();
    }
    /// Faz a troca de valores e depois faz a remoção do nó que agora
    /// contém o valor que quer retirar.
    p->setValor(aux->getValor());
    aux->setValor(valor);
    removerNo(valor, p->getDireita());
    return p;
}

/**
 * Função auxiliar na hora de remover um nó. Verifica se o nó
 * folha a ser retirado é a raiz
 * @param No
 * @return No
*/
No* ArvoreVermelhoPreto::casoNoFolha(No *p){
    // Verificar se o nó folha a ser retirada é a raiz, através da existência do pai.
    // Caso não seja a raiz, verifica se a cor do nó p é vermelha.
    numComparacoes++;
    if(p->getPai() == nullptr)
    {
        // Se não existir o pai, o nó é a raiz e faz a remoção simples.
        delete p;
    }
    else if(!p->getCor())
    {
        // Se o nó p não for a raiz mas for da cor vermelha, faz a remoção da folha com a atualização da informação do pai.
        numComparacoes++;
        No *pai = p->getPai();
        numComparacoes++;
        if(pai->getDireita() == p){
            pai->setDireita(nullptr);
        }else{
            pai->setEsquerda(nullptr);
        }
        delete p;
    }else{
        // Se o nó p não for a raiz mas for da cor preta, faz-se a verificação da cor do irmão.
        if(!getIrmao(p)->getCor()){
            numComparacoes++;
            // Se tiver irmão vermelho, remova o nó e faz a rotação a direita ou a esquerda.
            No *pai = p->getPai();
            numComparacoes++;
            if(pai->getDireita() == p){
                pai->setDireita(nullptr);
                delete p;
                pai = rotacaoSimplesDireita(pai);
            }else{
                pai->setEsquerda(nullptr);
                delete p;
                pai = rotacaoSimplesEsquerda(pai);
            }
        }else{
            // Se tiver irmão preto, verifica se contém um dos filhos da cor vermelha.
            No *irmao = getIrmao(p);
            No *pai = p->getPai();
            numComparacoes = numComparacoes + 2;
            if(irmao->getDireita()->getCor() && irmao->getEsquerda()->getCor()){
                //Se o irmão tiver dois filhos pretos, faz-se a remoção do nó e realiza a troca de cores do irmão e do pai.
                numComparacoes++;
                if(pai->getDireita() == p){
                    pai->setDireita(nullptr);
                    delete p;
                }else{
                    pai->setEsquerda(nullptr);
                    delete p;
                }
                recolore(pai);
                recolore(irmao);
            }else{
                // Se o irmão tiver pelo menos um filho da cor vermelha, faz a remoção do nó e realiza a
                // rotação necessária e altera a cor do neto vermelho.
                No *neto = netoVermelho(p); // busca o neto da cor vermelha para a análise da rotação.
                numComparacoes++;
                if(pai->getDireita() == p){
                    pai->setDireita(nullptr);
                    delete p;
                }else{
                    pai->setEsquerda(nullptr);
                    delete p;
                }
                pai = verificarRotacao(neto); // faz a rotação necessária
                //irmao = getIrmao(neto);
                recolore(neto); // troca a cor.
                recolore(getIrmao(neto));
            }
        }
    }
    return nullptr;
    // em todos os casos, foram deletados os nós com o valor procurado e com alterações necessárias na árvore.
}

/**
 * Função que remove um nó da árvore chamando uma função auxiliar
 * @param long int
 * @return
*/
void ArvoreVermelhoPreto::remover(long int valor)
{
    this->raiz = removerNo(valor, this->raiz);
}

/**
 * Função auxiliar para remover um nó, que verifica quais modificações
 * devem ser feitas após a remoção.
 * @param long int, No
 * @return No
*/
No* ArvoreVermelhoPreto::removerNo(long int valor, No *p)
{
    // Caso o nó p não exista, quer dizer que chegou no fim da árvore ou o valor não existe. Retorna NULL.
    // Caso contrário, verifico se o valor está a direita (maior) ou a esquerda (menor).
    // De forma recusiva, atualizo os novos nós, caso seja necessário.
    numComparacoes++;
    if(p == nullptr)
        return nullptr;
    else if(valor < p->getValor()){
        numComparacoes++;
        removerNo(valor, p->getEsquerda());
    }else if(valor > p->getValor()){
        numComparacoes++;
        removerNo(valor, p->getDireita());
    }
    else{
        // Caso consiga achar o valor, verifico se o nó é folha ou
        // possui um filho ou possui dois filhos
        if(p->getDireita() == nullptr && p->getEsquerda() == nullptr){
            numComparacoes = numComparacoes + 2;
            // Caso seja um nó folha, verifico qual caso irá recair e corrigir.
            p = casoNoFolha(p);
        }else if((p->getDireita() == nullptr) || (p->getEsquerda() == nullptr)){
            // Caso o nó não seja folha mas tenha um filho, apenas troco
            // os valores com o filho esquerdo ou o filho direito.
            numComparacoes = numComparacoes + 2;
            p = casoNoUmFilho(p);
        }else{
            // Caso o nó não seja folha mas tenha dois filhos, terá a
            // troca de valores com a menor subárvore direita.
            p = casoNoDoisFilhos(p, valor);
        }
    }
    return p;
}

/**
 * Função auxiliar para verificar qual rotação faço na remoção, quando possui um irmão vermelho.
 * Precisa-se ir no nó neto vermelho para a utilização da funcao verificarRotacao.
 * @param No
 * @return No
*/
No* ArvoreVermelhoPreto::netoVermelho(No *p){
    No *pai = p->getPai();
    No *aux;
    if(pai->getDireita() == p){
        aux = pai->getEsquerda();
        // Caso possui um neto mais a esquerda e da cor vermelha, retorno ele, para fazer uma rotação mais simples.
        // Caso contrário, retorno o filho direito.
        if(aux->getEsquerda() != nullptr && !aux->getEsquerda()->getCor()){
            return aux->getEsquerda();
        }else{
            return aux->getDireita();
        }
    }else{
        aux = pai->getDireita();
        // Caso possui um neto mais a direita e da cor vermelha, retorno ele, para fazer uma rotação mais simples.
        // Caso contrário, retorno o filho esquerdo.
        if(aux->getDireita() != nullptr && !aux->getDireita()->getCor()){
            return aux->getDireita();
        }else{
            return aux->getEsquerda();
        }
    }
}

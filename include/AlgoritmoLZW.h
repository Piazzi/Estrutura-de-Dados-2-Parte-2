#ifndef ALGORITMOLZW_H
#define ALGORITMOLZW_H
#include <string>
#include <map>
#include <algoritmoLZW.H>
#include <vector>

using namespace std;

class AlgoritmoLZW
{
    public:
        AlgoritmoLZW();
        virtual ~AlgoritmoLZW();
        map <string,int> dicionario;
        void imprimeDicionario();
        vector<int> comprimir(string entrada);

    protected:

    private:
};

#endif // ALGORITMOLZW_H

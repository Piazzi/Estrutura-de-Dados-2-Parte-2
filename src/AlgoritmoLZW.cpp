#include "AlgoritmoLZW.h"
#include <iostream>

using namespace std;

AlgoritmoLZW::AlgoritmoLZW()
{
    for (int i = 0; i <= 255; i++) {
        string str = "";
        str = str + char(i);
        dicionario[str] = i;
    }
}

AlgoritmoLZW::~AlgoritmoLZW()
{
    //dtor
    delete &dicionario;
}

void AlgoritmoLZW::imprimeDicionario(){
    for(map<string,int>::iterator it = dicionario.begin();it!=dicionario.end();it++){
        cout << it->second << ": " << it->first << " ";
    }
}

vector<int> AlgoritmoLZW::comprimir(string entrada){
    string s1 = "";
    string s2 = "";
    s1 += entrada[0];
    int entradaDic = 256;
    vector<int> saida;
    for (int i = 0; i < entrada.length(); i++) {
        if (i != entrada.length() - 1)
            s2 += entrada[i + 1];
        if (dicionario.find(s1 + s2) != dicionario.end()) {
            s1 = s1 + s2;
        }
        else {
            saida.push_back(dicionario[s1]);
            dicionario[s1 + s2] = entradaDic;
            entradaDic++;
            s1 = s2;
        }
        s2 = "";
    }
    saida.push_back(dicionario[s1]);
    for(vector<int>::iterator iter = saida.begin();iter!=saida.end();iter++){
        cout << *iter << " ";
    }
    return saida;
}



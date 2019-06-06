#include <iostream>
#include <random>
#include <stdlib.h>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

class Saida
{
    public:
        ~Saida();

        ofstream arvoreVermelhoPreto;
        ofstream arvoreB;
        void getArvoreVermelhoPreto();
        void getArvoreB();

};

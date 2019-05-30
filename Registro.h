#ifndef _REGISTRO_H_
#define _REGISTRO_H_

#include <iostream>
#include <random>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

class Registro
{
    int userId, movieId;
    float rating;

private:
    Registro armazenaRegistro(ifstream, Registro);

public:
    Registro();
    ~Registro();

    int getUserId();
    void setUserId(int);

    int getMovieId();
    void setMovieId(int);

    float getRating();
    void setRating(float);

    Registro pegarKbAleatorio(ifstream &arquivo, Registro registro, int tam);
    static Registro criaRegistro(ifstream &arquivo, Registro registro);
    Registro* criaArrayRegistro(ifstream &arquivo, int TAM);
};
#endif;

#include "Registro.h";

using namespace std;

int Registro::getUserId()
{
    return this->userId;
}

void Registro::setUserId(int id)
{
    this->userId = id;
}

int Registro::getMovieId()
{
    return this->movieId;
}

void Registro::setMovieId(int id)
{
    this->movieId = id;
}

float Registro::getRating()
{
    return this->rating;
}

void Registro::setRating(float rating)
{
    this->rating = rating;
}

Registro::Registro(){}

Registro::~Registro() {}

/**
 * Pega uma linha do arquivo ratings.csv e insere no objeto de registro
 *
 * @param ifstream arquivo
 * @param  Registro registro
 * @return registro
*/
Registro Registro::criaRegistro(ifstream& arquivo, Registro registro)
{
    string s;
    getline(arquivo,s,',');
    int userId = atoi(s.c_str());

    registro.setUserId(userId);

    getline(arquivo,s,',');
    int movieId = atoi(s.c_str());
    registro.setMovieId(movieId);


    getline(arquivo,s,',');
    float rating = atof(s.c_str());
    registro.setRating(rating);

    return registro;
}

/**
 * Cria um array de registros a partir de linhas selecionadas
 * aleatoriamente do arquivo ratings.csv
 *
 * @param ifstream arquivo
 * @param  int TAM
 * @return array de registros
*/
Registro* Registro::criaArrayRegistro(ifstream &arquivo, int TAM)
{
    Registro *registros = new Registro[TAM];

    int tamanhoArquivo = arquivo.tellg();

    cout << endl;
    cout << endl;

    cout << "Array original"
         << ": ";
    for (int j = 0; j < TAM; j++)
    {
        registros[j] = pegarKbAleatorio(arquivo, registros[j], tamanhoArquivo);
        cout << registros[j].getUserId() << " ";
    }

    cout << endl;
    cout << endl;

    return registros;
}

/**
 * Pega uma linha aleatória (filme) do arquivo ratings.csv
 *
 * @param ifstream arquivo
 * @param Registro registro
 * @param int tam
 * @return Registro::criaRegistro
*/
Registro Registro::pegarKbAleatorio(ifstream &arquivo, Registro registro, int tam)
{
    string lixo;
    arquivo.seekg(rand() % tam, ios::beg); // procurar do inicio ate o fim do arquivo
    getline(arquivo, lixo);                // joga a linha no lixo

    return Registro::criaRegistro(arquivo, registro);
}

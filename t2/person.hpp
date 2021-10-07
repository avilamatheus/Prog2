#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct personPF
{
    string nome;
    string nomeMae;
    string cpf;
    string endereco;
    string telefone;
};
struct personPJ
{
    string razaoSocial;
    string cnpj;
    string endereco;
    string telefone;
    string capitalSocial;
};

bool loadDatabase(string path, vector<personPF> &listPF, vector<personPJ> &listPJ);

bool SaveDatabase(string path, const vector<personPF> &listPF, const vector<personPJ> &listPJ);


#endif

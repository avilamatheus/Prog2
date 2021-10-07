#include "person.hpp"

bool loadDatabase(string path, vector<personPF> &listPF, vector<personPJ> &listPJ)
{
    ifstream fileReader(path);
    string tmp;
    while (getline(fileReader, tmp))
    {
        if (tmp == "1")
        {
            personPF p;
            getline(fileReader, p.nome);
            getline(fileReader, p.nomeMae);
            getline(fileReader, p.cpf);
            getline(fileReader, p.endereco);
            getline(fileReader, p.telefone);
            listPF.push_back(p);
        }
        else
        {
            personPJ p;
            getline(fileReader, p.razaoSocial);
            getline(fileReader, p.cnpj);
            getline(fileReader, p.endereco);
            getline(fileReader, p.telefone);
            getline(fileReader, p.capitalSocial);
            listPJ.push_back(p);
        }
    }

    return true;
}

bool SaveDatabase(string path, const vector<personPF> &listPF, const vector<personPJ> &listPJ)
{
    ofstream file(path);

    for (size_t i = 0; i < listPF.size(); i++)
    {
        file << "1" << endl << listPF.at(i).nome << endl << listPF.at(i).nomeMae << endl << listPF.at(i).cpf << endl << listPF.at(i).endereco << endl << listPF.at(i).telefone << endl;
    }
    for (size_t i = 0; i < listPJ.size(); i++)
    {
        file << "2" << endl << listPJ.at(i).razaoSocial << endl << listPJ.at(i).cnpj << endl << listPJ.at(i).endereco << endl << listPJ.at(i).telefone << endl << listPJ.at(i).capitalSocial << endl;
    }
    return true;
}

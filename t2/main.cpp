#include "person.hpp"
#define DEBUG 0

int main()
{
    vector<personPF> listPF;
    vector<personPJ> listPJ;

    if(loadDatabase("database.dat", listPF, listPJ) == false)
    {
        if(DEBUG) cout << "Database não encontrado. Criando um novo" << endl;
        //ifstream fhandle;
        //fhandle.open("database.dat", fstream::app);
    }


    while (true)
    {
        SaveDatabase("database.dat", listPF, listPJ);

        if(DEBUG) cout << "MY PAPA'S COMPANY - SIG" << endl;
        if(DEBUG) cout << "1. Add PF..." << endl;
        if(DEBUG) cout << "2. Add PJ..." << endl;
        if(DEBUG) cout << "3. Remove PF Index..." << endl;
        if(DEBUG) cout << "4. Remove PJ Index..." << endl;
        if(DEBUG) cout << "5. Print Names in Ascending Order" << endl;
        if(DEBUG) cout << "6. Exit" << endl;

        if(DEBUG) cout << "Enter an option: ";
        char option;
        cin >> option;

        cin.ignore();

        if (option == '1')
        {
            personPF p;
            if(DEBUG) cout << "Digite todos os dados da pessoa: (nome, nomeMae, cpf, endereco, telefone: " << endl;
            getline(cin, p.nome);
            getline(cin, p.nomeMae);
            getline(cin, p.cpf);
            getline(cin, p.endereco);
            getline(cin, p.telefone);

            listPF.push_back(p);

            continue;
        }

        if (option == '2')
        {
            personPJ p;
            if(DEBUG) cout << "digite os dados da pessoa: (razaoSocial, cnpj, endereco, telefone, capitalSocial): " << endl;
            getline(cin, p.razaoSocial);
            getline(cin, p.cnpj);
            getline(cin, p.endereco);
            getline(cin, p.telefone);
            getline(cin, p.capitalSocial);
            listPJ.push_back(p);
        }

        if (option == '3')
        {
            if(DEBUG) cout << "Digite um indice de PF para ser excluido: " << endl;
            if(DEBUG) cout << listPF.size() << endl;
            int index;
            cin >> index;

            if (index < 0 || index >= listPF.size())
            {
                if(DEBUG) cout << "O indice indicado e invalido" << endl;
            }
            else if (index < listPF.size())
            {
                listPF.erase(listPF.begin() + index);
            }
            continue;

        }
        if (option == '4')
        {
            if(DEBUG) cout << "Digite um indice de PJ para ser excluido: " << endl;
            if(DEBUG) cout << listPJ.size() << endl;
            int index;
            cin >> index;

            if (index < 0 || index >= listPJ.size())
            {
                if(DEBUG) cout << "O indice indicado e invalido" << endl;
            }
            else if (index < listPJ.size())
            {
                listPJ.erase(listPJ.begin() + index);
            }
            continue;
        }
        if (option == '5')
        {
            vector<string> tmp;
            for (size_t i = 0; i < listPF.size(); i++)
            {
               tmp.push_back (listPF.at(i).nome);
            }
            for (size_t i = 0; i < listPJ.size(); i++)
            {
               tmp.push_back (listPJ.at(i).razaoSocial);
            }
            sort(tmp.begin(), tmp.end());
            cout << "Names in Ascending Order:" << endl;
            for (size_t i = 0; i < tmp.size(); i++)
            {
               cout << tmp[i] << endl;
            }
            continue;

        }
        if (option == '6')
        {

            return false;
        }
    }
    return 0;
}

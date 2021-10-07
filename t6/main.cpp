#include <iostream>
#include <string>
#include "header.hpp"
#include <vector>
#include <fstream>
vector<Cliente*>myListOfClientes;
vector<Canecas*>myListOfCanecas;
vector<Agendas*>myListOfAgendas;
vector<BoxPascoa*>myListOfBoxes;
vector<BoxBirthday*>myListOfBoxBirthday;

int main()
{
int n;
cout << "Digite o numero de clientes que voce deseja inserir: " << endl;
cin >> n;
if (n <= 0)
{
    cout << "numero digitado invalido." << endl;
    return 1;
}
cin.ignore();
for (int i = 0; i<n;i++)
{
 cout << "--------------------------------------------------- " << endl;
 string name, telefone, adress;
 cout << "Insira o nome do(a) cliente #" << i+1 << " :" << endl;
 getline(cin, name);
 cout << "Insira o telefone do(a) cliente " << name << " (Formato: (xx)xxxxx-xxxx):" << endl;
 getline(cin, telefone);
 cout << "Insira o endereco do(a) cliente " << name << " :" << endl;
 getline(cin, adress);
 myListOfClientes.push_back(new Cliente(name, telefone, adress));
 int m;
cout << "Digite o numero de pedidos: " << endl;
cin >> m;
cin.ignore();
if (m <= 0)
{
    cout << "numero digitado invalido." << endl;
    for(int i=0; i<myListOfCanecas.size(); i++)
        {
            delete myListOfCanecas.at(i);
        }
    for(int i=0; i<myListOfAgendas.size(); i++)
        {
            delete myListOfAgendas.at(i);
        }
    for(int i=0; i<myListOfBoxes.size(); i++)
        {
            delete myListOfBoxes.at(i);
        }
    for(int i=0; i<myListOfBoxBirthday.size(); i++)
        {
            delete myListOfBoxBirthday.at(i);
        }
    for(int i=0; i<myListOfClientes.size(); i++)
        {
            delete myListOfClientes.at(i);
        }
    return 2;
}
 for (int j = 0; j<m;j++)
 {
     float valor;
     string dataentrega, temacaneca, capa, conteudo, nomeidade, temabox;
     int oppedido;
     cout << "Escolha o item do pedido #" << j+1 << " :" << endl;
     cout << "1 - CANECA" << endl;
     cout << "2 - AGENDA PERSONALIZADA"  << endl;
     cout << "3 - CAIXA DE PASCOA"  << endl;
     cout << "4 - CAIXA SURPRESA DE ANIVERSARIO"  << endl;
     cin >> oppedido;
     cin.ignore();
     if(oppedido == 1)
     {
         cout << "Insira a data de entrega do pedido #" << j+1 << " (Formato: dd/mm/aaaa):" << endl;
        getline(cin, dataentrega);
        Pedidos p(myListOfClientes.at(i), valor, dataentrega);
        cout << "Insira o tema da caneca: (Ex: Gremio, UFSC, Cachorros, Windows...) " << endl;
        getline(cin, temacaneca);
        Canecas caneca(myListOfClientes.at(i), valor, dataentrega, temacaneca);
        myListOfCanecas.push_back(new Canecas(caneca));
     }
     if(oppedido == 2)
     {
        cout << "Insira a data de entrega do pedido #" << j+1 << " (Formato: dd/mm/aaaa):" << endl;
        getline(cin, dataentrega);
        Pedidos p(myListOfClientes.at(i), valor, dataentrega);
        cout << "Insira a capa desejada para a agenda personalizada: (Ex: Profissoes, Nome e Ano, Times de Futebol...)" << endl;
        getline(cin, capa);
        Agendas agenda(myListOfClientes.at(i), valor, dataentrega, capa);
        myListOfAgendas.push_back(new Agendas(agenda));
     }
     if(oppedido == 3)
     {
        cout << "Insira a data de entrega do pedido #" << j+1 << " (Formato: dd/mm/aaaa):" << endl;
        getline(cin, dataentrega);
        Pedidos p(myListOfClientes.at(i), valor, dataentrega);
        cout << "Insira o(s) conteudo(s) que o cliente deseja na caixa de pascoa: (Ex: Heineken, M&Ms, Ouro Branco)" << endl;
        getline(cin, conteudo);
        BoxPascoa box(myListOfClientes.at(i), valor, dataentrega, conteudo);
        myListOfBoxes.push_back(new BoxPascoa(box));
     }
     if(oppedido == 4)
     {
        cout << "Insira a data de entrega do pedido #" << j+1 << " (Formato: dd/mm/aaaa):" << endl;
        getline(cin, dataentrega);
        Pedidos p(myListOfClientes.at(i), valor, dataentrega);
        cout << "Insira o nome e idade do aniversariante: (Fulano - x anos)" << endl;
        getline(cin, nomeidade);
        cout << "Insira o tema da caixa surpresa: (Ex: Beatles, Coca-Cola, Flamengo...)" << endl;
        getline(cin, temabox);
        BoxBirthday boxsurprise(myListOfClientes.at(i), valor, dataentrega, nomeidade, temabox);
        myListOfBoxBirthday.push_back(new BoxBirthday(boxsurprise));
     }
     else if(oppedido < 1 || oppedido > 4)
    {
        cout << "numero digitado invalido." << endl;
        for(int i=0; i<myListOfCanecas.size(); i++)
        {
            delete myListOfCanecas.at(i);
        }
        for(int i=0; i<myListOfAgendas.size(); i++)
            {
                delete myListOfAgendas.at(i);
            }
        for(int i=0; i<myListOfBoxes.size(); i++)
            {
                delete myListOfBoxes.at(i);
            }
        for(int i=0; i<myListOfBoxBirthday.size(); i++)
            {
                delete myListOfBoxBirthday.at(i);
            }
        for(int i=0; i<myListOfClientes.size(); i++)
            {
                delete myListOfClientes.at(i);
            }
        return 3;
    }

 }
 cout << "--------------------------------------------------- " << endl;
}
 cout << "PEDIDOS ORGANIZADOS POR TIPO DE ITEM (Canecas, Agendas, Caixas de Pascoa, Caixas Surpresa de Aniversario):" << endl;

 for(int i=0; i<myListOfCanecas.size(); i++)
 {
     cout << "--------------------------------------------------- " << endl << "ITEM DO PEDIDO: CANECA" << endl << "Nome do Cliente: " << myListOfCanecas.at(i)->operator&() << endl << "Telefone do Cliente: " << myListOfCanecas.at(i)->operator()() << endl << "Endereco do Cliente: " << myListOfCanecas.at(i)->operator+() << endl << "Valor: " << myListOfCanecas.at(i)->operator--() << endl << "Data de entrega: " << myListOfCanecas.at(i)->operator++() << endl << "Tema da caneca: " << myListOfCanecas.at(i)->GetTema() << endl;
 }
 for(int i=0; i<myListOfAgendas.size(); i++)
 {
     cout << "--------------------------------------------------- " << endl << "ITEM DO PEDIDO: AGENDA" << endl << "Nome do Cliente: " << myListOfAgendas.at(i)->operator&() << endl << "Telefone do Cliente: " << myListOfAgendas.at(i)->operator()() << endl << "Endereco do Cliente: " << myListOfAgendas.at(i)->operator+() << endl << "Valor: " << myListOfAgendas.at(i)->operator--() << endl << "Data de entrega: " << myListOfAgendas.at(i)->operator++() << endl << "Tema da capa da agenda: " << myListOfAgendas.at(i)->GetCapa() << endl;
 }
 for(int i=0; i<myListOfBoxes.size(); i++)
 {
     cout << "--------------------------------------------------- " << endl << "ITEM DO PEDIDO: CAIXA DE PASCOA" << endl << "Nome do Cliente: " << myListOfBoxes.at(i)->operator&() << endl << "Telefone do Cliente: " << myListOfBoxes.at(i)->operator()() << endl << "Endereco do Cliente: " << myListOfBoxes.at(i)->operator+() << endl << "Valor: " << myListOfBoxes.at(i)->operator--() << endl << "Data de entrega: " << myListOfBoxes.at(i)->operator++() << endl << "Conteudo escolhido para a caixa de pascoa: " << myListOfBoxes.at(i)->GetContent() << endl;
 }
 for(int i=0; i<myListOfBoxBirthday.size(); i++)
 {
     cout << "--------------------------------------------------- " << endl << "ITEM DO PEDIDO: CAIXA SURPRESA DE ANIVERSARIO" << endl << "Nome do Cliente: " << myListOfBoxBirthday.at(i)->operator&() << endl << "Telefone do Cliente: " << myListOfBoxBirthday.at(i)->operator()() << endl << "Endereco do Cliente: " << myListOfBoxBirthday.at(i)->operator+() << endl << "Valor: " << myListOfBoxBirthday.at(i)->operator--() << endl << "Data de entrega: " << myListOfBoxBirthday.at(i)->operator++() << endl << "Nome e idade do aniversariante: " << myListOfBoxBirthday.at(i)->GetNameAndAge() << endl << "Tema da Caixa Surpresa: " << myListOfBoxBirthday.at(i)->GetTema() << endl;
 }
cout << "--------------------------------------------------- " << endl;
cout << "deseja salvar os pedidos acima em um arquivo chamado 'pedidos.txt'? Digite 1 para salvar, qualquer outro numero para recusar." << endl;
int opsave;
cin >> opsave;
if (opsave==1)
{
    string path = "pedidos.txt";
    ofstream file;
    file.open(path, ios_base::app);
    if (file.is_open())
    {
        for(int i=0; i<myListOfCanecas.size(); i++)
            {
                file << "--------------------------------------------------- " << endl << "ITEM DO PEDIDO: CANECA" << endl << "Nome do Cliente: " << myListOfCanecas.at(i)->operator&() << endl << "Telefone do Cliente: " << myListOfCanecas.at(i)->operator()() << endl << "Endereco do Cliente: " << myListOfCanecas.at(i)->operator+() << endl << "Valor: " << myListOfCanecas.at(i)->operator--() << endl << "Data de entrega: " << myListOfCanecas.at(i)->operator++() << endl << "Tema da caneca: " << myListOfCanecas.at(i)->GetTema() << endl;
            }
         for(int i=0; i<myListOfAgendas.size(); i++)
                 {
                     file << "--------------------------------------------------- " << endl << "ITEM DO PEDIDO: AGENDA" << endl << "Nome do Cliente: " << myListOfAgendas.at(i)->operator&() << endl << "Telefone do Cliente: " << myListOfAgendas.at(i)->operator()() << endl << "Endereco do Cliente: " << myListOfAgendas.at(i)->operator+() << endl << "Valor: " << myListOfAgendas.at(i)->operator--() << endl << "Data de entrega: " << myListOfAgendas.at(i)->operator++() << endl << "Tema da capa da agenda: " << myListOfAgendas.at(i)->GetCapa() << endl;
                 }
         for(int i=0; i<myListOfBoxes.size(); i++)
             {
                 file << "--------------------------------------------------- " << endl << "ITEM DO PEDIDO: CAIXA DE PASCOA" << endl << "Nome do Cliente: " << myListOfBoxes.at(i)->operator&() << endl << "Telefone do Cliente: " << myListOfBoxes.at(i)->operator()() << endl << "Endereco do Cliente: " << myListOfBoxes.at(i)->operator+() << endl << "Valor: " << myListOfBoxes.at(i)->operator--() << endl << "Data de entrega: " << myListOfBoxes.at(i)->operator++() << endl << "Conteudo escolhido para a caixa de pascoa: " << myListOfBoxes.at(i)->GetContent() << endl;
             }
         for(int i=0; i<myListOfBoxBirthday.size(); i++)
             {
                 file << "--------------------------------------------------- " << endl << "ITEM DO PEDIDO: CAIXA SURPRESA DE ANIVERSARIO" << endl << "Nome do Cliente: " << myListOfBoxBirthday.at(i)->operator&() << endl << "Telefone do Cliente: " << myListOfBoxBirthday.at(i)->operator()() << endl << "Endereco do Cliente: " << myListOfBoxBirthday.at(i)->operator+() << endl << "Valor: " << myListOfBoxBirthday.at(i)->operator--() << endl << "Data de entrega: " << myListOfBoxBirthday.at(i)->operator++() << endl << "Nome e idade do aniversariante: " << myListOfBoxBirthday.at(i)->GetNameAndAge() << endl << "Tema da Caixa Surpresa: " << myListOfBoxBirthday.at(i)->GetTema() << endl;
             }
    }
    file.close();
    cout << "--------------------------------------------------- " << endl;
    cout << "Os pedidos foram salvos com sucesso no arquivo pedidos.txt" << endl;
    cout << "--------------------------------------------------- " << endl;
}
else
{
    cout << "--------------------------------------------------- " << endl;
    cout << "Os pedidos nao foram salvos." << endl;
    cout << "--------------------------------------------------- " << endl;
}
for(int i=0; i<myListOfCanecas.size(); i++)
{
    delete myListOfCanecas.at(i);
}
for(int i=0; i<myListOfAgendas.size(); i++)
{
    delete myListOfAgendas.at(i);
}
for(int i=0; i<myListOfBoxes.size(); i++)
{
    delete myListOfBoxes.at(i);
}
for(int i=0; i<myListOfBoxBirthday.size(); i++)
{
    delete myListOfBoxBirthday.at(i);
}
for(int i=0; i<myListOfClientes.size(); i++)
{
    delete myListOfClientes.at(i);
}

 return 0;
}

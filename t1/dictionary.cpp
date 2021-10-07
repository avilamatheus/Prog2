#include "dictionary.hpp"

bool loadDictionary(string path, vector<string> &wordlist)
{
    ifstream filereader;
    filereader.open(path); //Abre o arquivo path

    if(filereader.is_open() == false)
    {
        return false; //Retorna falso caso não consiga abrir o arquivo
    }
     string vmp; //Cria a string vpm
     while(getline(filereader,vmp)) //Faz um loop até o final do arquivo a ser aberto, atribuindo cada linha a vmp
     {
        // cout << vmp << endl;
         wordlist.push_back(vmp); //Atribui a linha de vmp para a linha wordlist
     }

    wordlist.erase(wordlist.begin() + 0);

    return true;
}

bool SearchString(const vector<string> &wordlist, string query)
{
  for(size_t i = 0; i < wordlist.size(); i++) //Roda todo o vetor wordlist
     {
         string word = wordlist.at(i); //Define word como a wordlist naquela posição
         if(word == query)             //Se a palavra word naquela posição for igual a string enviada pelo usuário, que é a buscada
         cout << word << endl;       //Irá printar a word que está sendo buscada pelo usuário
         return true; 
     }
    return false;
    }

vector<string> SearchSubStrings(const vector <string> &wordlist, string querry)
{
    vector < string > substrlist; //Cria um vetor string substrlist

    for(size_t i=0; i< wordlist.size(); i++) //Roda todo o vetor string do arquivo
    {
        string word = wordlist.at(i);   //Define word como sendo igual a wordlist naquela posição no loop for (STRING)
        size_t pos = word.find(querry); //Pega o tamanho de querry (palavra a ser buscada) na string word
        if(pos < word.length())         //Se o tamanho da palavra a ser buscada (querry) e compara com o tamanho da string (palavra total)
        {                               //Caso a palavra que está sendo buscada for menor que a palavra total, ela vai ser uma substring exemplo : pizzaiolo a substring é pizza 
                                        //Porque pizza tem um tamanho menor que pizzaiolo
            substrlist.push_back(word); //Atribui ao vetor string substrlist a string, no qual a substring se encontra 
        }
    }
     return substrlist;
}

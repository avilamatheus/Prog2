#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
bool loadDictionary(string path, vector<string> &wordlist);

bool SearchString(const vector <string> &wordlist, string querry);

vector<string> SearchSubStrings(const vector <string> &wordlist, string querry);

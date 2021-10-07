#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

bool mysorterfunction(const pair<size_t, size_t> &p1, const pair<size_t, size_t> &p2)
{
    return (p1.second > p2.second);
}
int main()
{
    string pathAlpha = "alpha.txt";
    ifstream frAlpha(pathAlpha);
    vector<char> alphabetList;
    if (!frAlpha.is_open())
    {
        cout << "Error, alphabet file not found" << endl;
        return 1;
    }
    else
    {
        string tmp;
        while (getline(frAlpha, tmp))
        {
            alphabetList.push_back(tmp.at(0));
        }
    }

    string pathManusc = "manuscript.txt";
    ifstream frManusc(pathManusc);
    stringstream manuscriptStr;
    if (!frManusc.is_open())
    {
        cout << "Error, manuscript file not found" << endl;
        return 2;
    }
    else
    {
        char ch;
        while (frManusc.get(ch))
        {
            manuscriptStr << ch;
        }
    }
    cout << manuscriptStr.str() << endl;

    vector<pair<size_t, size_t>> frequencyList;
    for (size_t i = 0; i < 256; i++)
    {
        pair<size_t, size_t> p;
        p.first = i;
        p.second = 0;
        frequencyList.push_back(p);
    }
    for (size_t i = 0; i < manuscriptStr.str().size(); i++)
    {
        char ch = manuscriptStr.str().at(i);
        frequencyList.at(ch).second++;
    }

    //sort and remove elements with zero frequency
    stable_sort(frequencyList.begin(), frequencyList.end(), mysorterfunction);
    for (size_t i = 0; i < frequencyList.size(); i++)
    {
        if (frequencyList.at(i).second == 0)
        {
            frequencyList.erase(frequencyList.begin() + i, frequencyList.end());
        }
    }

    vector<pair<size_t, size_t>> auxList;
    auxList = frequencyList;

    for (size_t i = 0; i < auxList.size(); i++)
    {
        auxList.at(i).first = alphabetList.at(i);
    }
    for (size_t i = 0; i < auxList.size(); i++)
    {
        cout << auxList.at(i).first << " -> " << (char)auxList.at(i).first << " " << auxList.at(i).second << endl;
    }

    for (size_t i = 0; i < manuscriptStr.str().size(); i++)
    {
        char ch = manuscriptStr.str().at(i);
        for (size_t j = 0; j < auxList.size(); j++)
        {
            if (ch == frequencyList.at(j).first)
            {
                cout << (char)auxList.at(j).first;
                break;
            }
        }
    }
    cout << endl;

    return 0;
}

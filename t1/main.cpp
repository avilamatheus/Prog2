#include "dictionary.hpp"

using namespace std;

#define DEBUG 0

int main()
{
    vector < vector < string > > listOfDicts;
    vector < string > listOfDictsNames;
    while(true)
    {
    if(DEBUG) cout << "DICTIONARY MANIPULATOR HACK"<< endl;
    if(DEBUG) cout << "Select an option:" << endl;
    if(DEBUG) cout << "1. Open Dictionary..." << endl;
    if(DEBUG) cout << "2. Search Substrings..." << endl;
    if(DEBUG) cout << "3. Remove Words Containing Substring..." << endl;
    if(DEBUG) cout << "4. Show Statistics" << endl;
    if(DEBUG) cout << "5. Exit" << endl;

    if(DEBUG) cout << "Option: ";
    int op;
    cin  >> op;
    switch(op)
    {
    case 1:
        {

    if(DEBUG) cout << "Type a file name" << endl;
    string path;
    cin >> path;
    vector <string> wordlist;

    if(!loadDictionary(path, wordlist))
        {
        if(DEBUG) cout << "Error, file not found";
        }
    else
    {
      listOfDicts.push_back(wordlist);
      listOfDictsNames.push_back(path);
    }
        }
        break;

    case 2:
    {
       if (DEBUG) cout << "enter substring to search:" << endl;
            string query;
            cin >> query;

         for(size_t i = 0; i < listOfDicts.size(); i++)
         {
           for(size_t j = 0; j < listOfDicts.at(i).size();j++)
           {
             string str = listOfDicts.at(i).at(j);
             size_t pos = str.find(query);
             if (pos <= str.length())
             {
                if (DEBUG) cout << "Subtring found !" << endl;
                if (DEBUG) cout << query << "found in the file" << listOfDictsNames.at(i) << " in line number " << j << endl;
                 cout <<  str << endl;
             }
           }
         }
      }
        break;
    case 3:
     {

       if (DEBUG) cout << "enter substring to delete:" << endl;
       string query;
       cin >> query;
       for(int dictIt = 0; dictIt < listOfDicts.size(); dictIt++)
       {
         for (int stringIt = 0; stringIt < listOfDicts.at(dictIt).size(); stringIt++)
         {
           if (listOfDicts.at(dictIt).at(stringIt).find(query) != string::npos)
           {
             listOfDicts.at(dictIt).erase(listOfDicts.at(dictIt).begin() + stringIt);
             stringIt--;
           }
         }

       }
        }
        break;
    case 4:
{
    cout << "Statistics:" << endl;
    for(size_t i=0; i < listOfDicts.size(); i++)
    {
       cout << listOfDictsNames.at(i) << " -> " << listOfDicts.at(i).size() << " words" << endl;
    }

}
        break;
    case 5:

       return false;

        break;
    default:
    if(DEBUG) cout << "The chosen option is invalid, type another one " << endl;
    cin >> op;
    }

    }
    return 0;


    }

#include "GenericShape.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>
using namespace std;

#define DEBUG 0
vector< GenericShape* > myListOfShapes;

int main()
{
    if (DEBUG) cout << "Enter with a shape configuration file to load: ";
    string path;
    cin >> path;

    vector<string> shapes;
    LoadFile(path, shapes);

    for(size_t i = 0; i < shapes.size(); i++)
    {
        if(shapes.at(i) == "circle")
        {
                string s = shapes.at(i+1);
                float r = stof(s);
                Circle circulo(r);
                myListOfShapes.push_back(new GenericShape(circulo));
                if(DEBUG) cout << "AREA DO CIRCULO: " << circulo.CalcArea() << endl;
        }
         if(shapes.at(i) == "sphere")
        {
                string s = shapes.at(i+1);
                float r = stof(s);
                Sphere esfera(r);
                myListOfShapes.push_back(new GenericShape(esfera));
                if(DEBUG) cout << "AREA DA ESFERA: " << esfera.CalcArea() << endl;
        }
        if(shapes.at(i) == "square")
        {
                string s = shapes.at(i+1);
                float l = stof(s);
                Square quadrado(l);
                myListOfShapes.push_back(new GenericShape(quadrado));
                if(DEBUG) cout << "AREA DO QUADRADO: " << quadrado.CalcArea() << endl;
        }
        if(shapes.at(i) == "cube")
        {
                string s = shapes.at(i+1);
                float l = stof(s);
                Cube cubo(l);
                myListOfShapes.push_back(new GenericShape(cubo));
                if(DEBUG) cout << "AREA DO CUBO: " << cubo.CalcArea() << endl;
        }
        if (shapes.at(i) == "tetrahedron")
        {

                        vector<string> tokens;
                        vector<string> aux;
                        if (shapes.at(i + 1).find(',') != std::string::npos)
                        {
                            for (size_t j = 1; j < 5; j++)
                            {
                                string tokenString(shapes.at(i + j));
                                regex delimiters{"[\\s,]+"};

                                sregex_token_iterator tokens_begin{tokenString.begin(), tokenString.end(), delimiters, -1};
                                auto tokens_end = sregex_token_iterator{};

                                for (auto token_it = tokens_begin; token_it != tokens_end; token_it++)
                                    tokens.push_back(*token_it);
                            }
                        }
                        for (size_t i=0;i<tokens.size();i++)
                        {
                            aux.push_back(tokens.at(i));
                        }
                        float r1 = stof(aux.at(0));
                        float r2 = stof(aux.at(1));
                        float r3 = stof(aux.at(2));
                        float r4 = stof(aux.at(3));
                        float r5 = stof(aux.at(4));
                        float r6 = stof(aux.at(5));
                        float r7 = stof(aux.at(6));
                        float r8 = stof(aux.at(7));
                        float r9 = stof(aux.at(8));
                        float r10 = stof(aux.at(9));
                        float r11 = stof(aux.at(10));
                        float r12 = stof(aux.at(11));
                        Tetrahedron tetra(r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12);
                        myListOfShapes.push_back(new GenericShape(tetra));
                        if(DEBUG) cout << "AREA DO TETRAEDRO: " << tetra.CalcArea() << endl;
            }

      if (shapes.at(i) == "triangle")
            {
                    vector<string> tokens;
                    vector<string> aux;
                    if (shapes.at(i + 1).find(',') != std::string::npos)
                        {
                            for (size_t j = 1; j < 4; j++)
                            {
                                    string tokenString(shapes.at(i + j));
                                    regex delimiters{"[\\s,]+"};

                                    sregex_token_iterator tokens_begin{tokenString.begin(), tokenString.end(), delimiters, -1};
                                    auto tokens_end = sregex_token_iterator{};

                                    for (auto token_it = tokens_begin; token_it != tokens_end; token_it++)
                                        tokens.push_back(*token_it);

                            }
                            for (size_t i=0;i<tokens.size();i++)
                                {
                                    aux.push_back(tokens.at(i));
                                }
                                float r1 = stof(aux.at(0));
                                float r2 = stof(aux.at(1));
                                float r3 = stof(aux.at(2));
                                float r4 = stof(aux.at(3));
                                float r5 = stof(aux.at(4));
                                float r6 = stof(aux.at(5));
                                Triangle triangulo(r1,r2,r3,r4,r5,r6);
                                myListOfShapes.push_back(new GenericShape(triangulo));
                                if(DEBUG) cout << "area do triangulo dado os VERTICES: " << triangulo.CalcArea() << endl;
                            }
                            else
                            {
                                string s1 = shapes.at(i+1);
                                float r1 = stof(s1);
                                string s2 = shapes.at(i+2);
                                float r2 = stof(s2);
                                string s3 = shapes.at(i+3);
                                float r3 = stof(s3);
                                Triangle triangulo(r1,r2,r3);
                                myListOfShapes.push_back(new GenericShape(triangulo));
                                if(DEBUG) cout << "area do tringulo dadas as RETAS: " << triangulo.CalcArea() << endl;
                            }
                }
    }
    for(size_t i=0; i< myListOfShapes.size(); i++)
    {
        cout << "Object #" << i <<" is " << myListOfShapes.at(i)->ShowInfo() << endl;
    }
    for(size_t i=0; i< myListOfShapes.size(); i++)
    {
        delete myListOfShapes.at(i);
    }
    return 0;
}

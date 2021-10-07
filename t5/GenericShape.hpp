#ifndef GENERIC_HPP
#define GENERIC_HPP
#include <vector>
#include <math.h>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

bool LoadFile(string path, vector<string> &s);

enum DataType {tnone, tcircle, tsquare, ttriangle, tsphere, ttetrahedron, tcube};

class Circle
{
    private:
    float m_ratio;

    public:
        Circle() {};
        ~Circle() {};
        Circle(float r);
        float CalcArea()
        {
            cout.setf(ios::fixed, ios::floatfield);
            cout.precision(2);
            float area = 3.14159265358979323846*(pow(m_ratio,2));
            return area;
        }
};

class Square
{
    private:
    float m_edge;

    public:
    Square() {};
    ~Square() {};
    Square(float l);
    float CalcArea()
    {
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        float area = pow(m_edge,2);
        return area;
    }

};

class Sphere
{
private:
    float m_ratio;

public:
Sphere() {};
~Sphere() {};
Sphere(float r);
float CalcArea()
{
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    float area = 4*3.14159265358979323846*(pow(m_ratio,2));
    return area;
}
};


class Cube
{
    private:
    float m_edge;

    public:
    Cube() {};
    ~Cube() {};
    Cube(float l);
    float CalcArea()
    {
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        float area = 6*(pow(m_edge,2));
        return area;
    }

};

class Tetrahedron
{
    private:
    float m_p1x, m_p1y, m_p1z, m_p2x, m_p2y, m_p2z, m_p3x, m_p3y, m_p3z, m_p4x, m_p4y, m_p4z;
    public:
    Tetrahedron() {};
    ~Tetrahedron() {};
    Tetrahedron(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4);
    float CalcArea()
    {
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        return Heron1()+Heron2()+Heron3()+Heron4();
    }
    float DistanciaEntreAeB()
    {
        float dx = pow((m_p2x-m_p1x),2);
        float dy = pow((m_p2y-m_p1y),2);
        float dz = pow((m_p2z-m_p1z),2);
        float distanciaAB = sqrt(dx+dy+dz);
        return distanciaAB;
    }
    float  DistanciaEntreAeC()
    {
        float dx = pow((m_p3x-m_p1x),2);
        float dy = pow((m_p3y-m_p1y),2);
        float dz = pow((m_p3z-m_p1z),2);
        float distanciaAC = sqrt(dx+dy+dz);
        return distanciaAC;
    }
    float DistanciaEntreAeD()
    {
        float dx = pow((m_p4x-m_p1x),2);
        float dy = pow((m_p4y-m_p1y),2);
        float dz = pow((m_p4z-m_p1z),2);
        float distanciaAD = sqrt(dx+dy+dz);
        return distanciaAD;
    }
    float DistanciaEntreBeC()
    {
        float dx = pow((m_p3x-m_p2x),2);
        float dy = pow((m_p3y-m_p2y),2);
        float dz = pow((m_p3z-m_p2z),2);
        float distanciaBC = sqrt(dx+dy+dz);
        return distanciaBC;
    }
    float DistanciaEntreBeD()
    {
        float dx = pow((m_p4x-m_p2x),2);
        float dy = pow((m_p4y-m_p2y),2);
        float dz = pow((m_p4z-m_p2z),2);
        float distanciaBD = sqrt(dx+dy+dz);
        return distanciaBD;
    }
    float DistanciaEntreCeD()
    {
        float dx = pow((m_p4x-m_p3x),2);
        float dy = pow((m_p4y-m_p3y),2);
        float dz = pow((m_p4z-m_p3z),2);
        float distanciaCD = sqrt(dx+dy+dz);
        return distanciaCD;
    }
    float Heron1()
    {
        float a = DistanciaEntreAeB();
        float b = DistanciaEntreAeC();
        float c = DistanciaEntreBeC();
        float s = (0.5)*(a+b+c);
        float heron1 = sqrt(s*(s-a)*(s-b)*(s-c));
        return heron1;
    }
    float Heron2()
    {
        float a = DistanciaEntreAeB();
        float b = DistanciaEntreAeD();
        float c = DistanciaEntreBeD();
        float s = (0.5)*(a+b+c);
        float heron2 = sqrt(s*(s-a)*(s-b)*(s-c));
        return heron2;
    }
    float Heron3()
    {
        float a = DistanciaEntreCeD();
        float b = DistanciaEntreBeC();
        float c = DistanciaEntreBeD();
        float s = (0.5)*(a+b+c);
        float heron3 = sqrt(s*(s-a)*(s-b)*(s-c));
        return heron3;
    }
     float Heron4()
    {
        float a = DistanciaEntreAeD();
        float b = DistanciaEntreAeC();
        float c = DistanciaEntreCeD();
        float s = (0.5)*(a+b+c);
        float heron4 = sqrt(s*(s-a)*(s-b)*(s-c));
        return heron4;
    }
};

class Triangle
{

private:
    float m_e1, m_e2, m_e3;
    float m_p1x, m_p1y, m_p2x, m_p2y, m_p3x, m_p3y;

public:
    Triangle() {};
    ~Triangle() {};

    Triangle(float e1, float e2, float e3)
    {
        m_e1 = e1;
        m_e2 = e2;
        m_e3 = e3;
    }
    Triangle(float x1, float y1, float x2, float y2, float x3, float y3);
    float CalcArea()
    {
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        float p = (m_e1 + m_e2 + m_e3) / 2;
        float area = sqrt(p * (p - m_e1) * (p - m_e2) * (p - m_e3));
        return area;
    }
};

class GenericShape
{
private:
    void* m_data;
    DataType m_dataType;

public:
    GenericShape(){ m_data = NULL; m_dataType=tnone; };
    GenericShape(Circle v)    { m_data = new Circle(v); m_dataType=tcircle; };
    GenericShape(Square v)    { m_data = new Square(v); m_dataType=tsquare; };
    GenericShape(Triangle v)   { m_data = new Triangle(v); m_dataType=ttriangle; };
    GenericShape(Sphere v)     { m_data = new Sphere(v); m_dataType=tsphere; };
    GenericShape(Tetrahedron v)   { m_data = new Tetrahedron(v); m_dataType=ttetrahedron; };
    GenericShape(Cube v)      { m_data = new Cube(v); m_dataType=tcube; };
    ~GenericShape(){
        if (m_dataType==tcircle)
        {
           delete((Circle*) m_data);
        }
        if (m_dataType==tsquare)
        {
           delete((Square*) m_data);
        }
        if (m_dataType==ttriangle)
        {
            delete((Triangle*) m_data);
        }
        if (m_dataType==tsphere)
        {
            delete((Sphere*) m_data);
        }
        if (m_dataType==ttetrahedron)
        {
            delete((Tetrahedron*) m_data);
        }
        if (m_dataType==tcube)
        {
            delete((Cube*) m_data);
        }
        };

    string ShowInfo() {
        stringstream sst;
        if(m_dataType == tcircle) sst << "circle -> " << std::setprecision(2) << std::fixed << ((Circle*) m_data)->CalcArea();
        if(m_dataType == tcube) sst << "cube -> " << std::setprecision(2) << std::fixed << ((Cube*) m_data)->CalcArea();
        if(m_dataType == tsquare) sst << "square -> " << std::setprecision(2) << std::fixed << ((Square*) m_data)->CalcArea();
        if(m_dataType == ttriangle) sst << "triangle -> " << std::setprecision(2) << std::fixed << ((Triangle*) m_data)->CalcArea();
        if(m_dataType == tsphere) sst << "sphere -> " << std::setprecision(2) << std::fixed << ((Sphere*) m_data)->CalcArea();
        if(m_dataType == ttetrahedron) sst << "tetrahedron -> " << std::setprecision(2) << std::fixed << ((Tetrahedron*) m_data)->CalcArea();
        return sst.str();
    };
};
#endif

#include "GenericShape.hpp"
#include <fstream>

bool LoadFile(string path, vector<string> &s)
{
    ifstream filereader;
    filereader.open(path);

    if (filereader.is_open() == false)
    {
        return false;
    }

    string shapes;
    while (getline(filereader, shapes))
    {
        s.push_back(shapes);
    }

    return true;
}

Circle::Circle(float r)
{
    m_ratio=r;
}


Square::Square(float l)
{
    m_edge=l;
}

Cube::Cube(float l)
{
    m_edge=l;
}
Sphere::Sphere(float r)
{
    m_ratio=r;
}

Tetrahedron::Tetrahedron(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4)
{
    m_p1x = x1;
    m_p1y = y1;
    m_p1z = z1;
    m_p2x = x2;
    m_p2y = y2;
    m_p2z = z2;
    m_p3x = x3;
    m_p3y = y3;
    m_p3z = z3;
    m_p4x = x4;
    m_p4y = y4;
    m_p4z = z4;
}

Triangle::Triangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
    m_p1x = x1;
    m_p1y = y1;
    m_p2x = x2;
    m_p2y = y2;
    m_p3x = x3;
    m_p3y = y3;
    float dxAB = pow((m_p2x-m_p1x),2);
    float dyAB = pow((m_p2y-m_p1y),2);
    float distanciaAB = sqrt(dxAB + dyAB);
    m_e1 = distanciaAB;

    float dxBC = pow((m_p3x - m_p2x), 2);
    float dyBC = pow((m_p3y - m_p2y), 2);
    float distanciaBC = sqrt(dxBC + dyBC);
    m_e2 = distanciaBC;

    float dxAC = pow((m_p3x - m_p1x), 2);
    float dyAC = pow((m_p3y - m_p1y), 2);
    float distanciaAC = sqrt(dxAC + dyAC);
    m_e3 = distanciaAC;
}

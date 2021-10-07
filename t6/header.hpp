#ifndef HEADER_HPP
#define HEADER_HPP

using namespace std;

class Cliente
{
private:
    string m_name;
    string m_telefone;
    string m_adress;

public:
    Cliente() : m_name(""),  m_telefone(""), m_adress("") {};
    ~Cliente() {};
    Cliente(string name, string telefone, string adress) : m_name(name), m_telefone(telefone), m_adress(adress) {};

    string GetNome() const { return m_name; };
    string GetTelefone() const { return m_telefone; };
    string GetAdress() const { return m_adress; };
};

class Pedidos
{
protected:
    float m_valor;
    string m_dataentrega;
    Cliente *m_cliente;

public:
    Pedidos() : m_cliente(NULL), m_valor(0), m_dataentrega("") {};
    ~Pedidos() {};
    Pedidos(Cliente *cliente, float valor, string data) : m_cliente(cliente), m_valor(valor), m_dataentrega(data)  {};
    float operator--()
    {
        return m_valor;
    }
    string operator++()
    {
        return m_dataentrega;
    }
    string operator&()
    {
        return m_cliente->GetNome();
    }
    string operator()()
    {
        return m_cliente->GetTelefone();
    }
    string operator+()
    {
        return m_cliente->GetAdress();
    }
};

class Canecas : public Pedidos
{
protected:
    string m_tema;
public:
    Canecas () : m_tema("") {};
    ~Canecas() {};
    Canecas (Cliente *cliente, float valor, string data, string tema) : Pedidos(cliente, valor=30, data), m_tema(tema) {};
    string GetTema() const { return m_tema; };

};

class Agendas : public Pedidos
{
protected:
    string m_capa;
public:
    Agendas () : m_capa("") {};
    ~Agendas() {};
    Agendas (Cliente *cliente, float valor, string data, string capa) : Pedidos(cliente, valor=60, data), m_capa(capa) {};
    string GetCapa() const { return m_capa; };

};

class BoxPascoa : public Pedidos
{
protected:
    string m_content;
public:
    BoxPascoa () : m_content("") {};
    ~BoxPascoa() {};
    BoxPascoa (Cliente *cliente, float valor, string data, string conteudo) : Pedidos(cliente, valor=55, data), m_content(conteudo) {};
    string GetContent() const { return m_content; };

};

class BoxBirthday : public Pedidos
{
protected:
    string m_nameage;
    string m_tema;
public:
    BoxBirthday () : m_nameage(""), m_tema("") {};
    ~BoxBirthday() {};
    BoxBirthday (Cliente *cliente, float valor, string data, string nomeidade, string tema) : Pedidos(cliente, valor=110, data), m_nameage(nomeidade), m_tema(tema) {};
    string GetNameAndAge() const { return m_nameage; };
    string GetTema() const { return m_tema; };

};


#endif



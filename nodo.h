#ifndef NODO_H
#define NODO_H
#include <string>

using namespace std;
class Nodo
{
public:
    Nodo(string v);
    string getValor();
    Nodo *getNext();
    void setNext(Nodo *n);
private:
    string valor;
    Nodo *next;
};

#endif // NODO_H

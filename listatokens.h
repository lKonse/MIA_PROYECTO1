#ifndef LISTATOKENS_H
#define LISTATOKENS_H
#include <string>
#include "nodo.h"

using namespace  std;

class listaTokens
{
public:
    listaTokens();
    void add(string v);
    string get(int n);
    int tam = 0;
    Nodo *head, *cola;

};

#endif // LISTATOKENS_H

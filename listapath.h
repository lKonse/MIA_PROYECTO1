#ifndef LISTAPATH_H
#define LISTAPATH_H
#include "nodopath.h"

class listaPath
{
public:
    listaPath();
    void add(string path, string letra, int num);
    PATH get(int n);
    bool estaVacia();
    void setNum(int x, int num);
    int tam = 0;
    nodoPath *head, *cola;
};

#endif // LISTAPATH_H

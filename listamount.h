#ifndef LISTAMOUNT_H
#define LISTAMOUNT_H
#include "nodomount.h"
#include "listapath.h"
#include <string>

using namespace std;

class listaMount
{
public:
    listaPath *Paths;

    listaMount();
    NodoMount *head, *cola;
    int tam, num, ascii;
    void add(string path, string name);
    void borrar(int x);
    MOUNT get(int x);
    bool estaVacio();
};

#endif // LISTAMOUNT_H

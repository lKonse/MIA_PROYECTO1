#ifndef NODOPATH_H
#define NODOPATH_H
#include <string>

using namespace std;

typedef struct path{
    string path;
    string letra;
    int num;
}PATH;

class nodoPath
{
public:
    nodoPath(string path, string letra, int num);
    PATH getValor();
    nodoPath *getNext();
    void setNext(nodoPath *n);
    void setNum(int num);
private:
    PATH valor;
    nodoPath *next;
};

#endif // NODOPATH_H

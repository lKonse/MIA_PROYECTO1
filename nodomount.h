#ifndef NODOMOUNT_H
#define NODOMOUNT_H
#include <string>

using namespace std;

typedef struct montar{
    string path;
    string name;
    string id;
}MOUNT;

class NodoMount
{
public:
    NodoMount(string path, string name);
    MOUNT getValor();
    NodoMount *getNext();
    NodoMount *getPrev();
    void setNext(NodoMount *n);
    void setPrev(NodoMount *n);
    void setId(string id);
private:
    MOUNT valor;
    NodoMount *next, *prev;
};

#endif // NODOMOUNT_H

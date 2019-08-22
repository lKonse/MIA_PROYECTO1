#include "nodomount.h"

NodoMount::NodoMount(string path, string name)
{
    valor.path = path;
    valor.name = name;
    next = 0;
    prev = 0;
}

MOUNT NodoMount::getValor()
{
    return valor;
}

NodoMount* NodoMount::getNext()
{
    return next;
}

NodoMount* NodoMount::getPrev(){
    return prev;
}

void NodoMount::setNext(NodoMount *n)
{
    next = n;
}

void NodoMount::setPrev(NodoMount *n)
{
    prev = n;
}

void NodoMount::setId(string id)
{
    valor.id = id;
}

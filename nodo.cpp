#include "nodo.h"

Nodo::Nodo(string v)
{
  valor = v;
  next = 0;
}

string Nodo::getValor()
{
    return valor;
}

Nodo* Nodo::getNext()
{
  return next;
}

void Nodo::setNext(Nodo *n)
{
    next = n;
}

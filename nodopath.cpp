#include "nodopath.h"

nodoPath::nodoPath(string path, string letra, int num)
{
  valor.path = path;
  valor.letra = letra;
  valor.num = num;
  next = 0;
}

PATH nodoPath::getValor()
{
    return valor;
}

nodoPath* nodoPath::getNext()
{
  return next;
}

void nodoPath::setNext(nodoPath *n)
{
    next = n;
}

void nodoPath::setNum(int num)
{
    valor.num = num;
}

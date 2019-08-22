#include "listapath.h"

listaPath::listaPath()
{
  head = 0;
  cola = 0;
  tam = 0;
}

void listaPath::add(string path, string letra, int num)
{
  nodoPath *nuevo = new nodoPath(path, letra, num);
  if(estaVacia()){
    head = nuevo;
    cola = nuevo;
  }else{
    cola->setNext(nuevo);
    cola = nuevo;
  }
  tam++;
}

PATH listaPath::get(int n)
{
    nodoPath *temp = head;
    if(n < tam)
    {
        for(int x = 0; x < n; x++)
        {
            temp = temp->getNext();
        }
    }
    return temp->getValor();
}

void listaPath::setNum(int n, int num){
    nodoPath *temp = head;
    for(int x = 0; x < n; x++)
    {
        temp = temp->getNext();
    }
    temp->setNum(num);
}

bool listaPath::estaVacia()
{
    return head == 0;
}

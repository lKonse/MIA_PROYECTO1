#include "listatokens.h"

listaTokens::listaTokens()
{
  head = 0;
  cola = 0;
  tam = 0;
}

void listaTokens::add(string v)
{
  Nodo *nuevo = new Nodo(v);
  if(head != 0){
    head = nuevo;
    cola = nuevo;
  }else{
    cola->setNext(nuevo);
    cola = nuevo;
  }
  tam++;
}

string listaTokens::get(int n)
{
    Nodo *temp = head;
    if(n < tam)
    {
        for(int x = 0; x < n; x++)
        {
            temp = temp->getNext();
        }
    }
    return temp->getValor();
}

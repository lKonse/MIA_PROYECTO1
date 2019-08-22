#include "listamount.h"
#include <iostream>
using namespace std;
listaMount::listaMount()
{
    head = 0;
    cola = 0;
    tam = 0;
    ascii = 97;
    Paths = new listaPath();
}

bool listaMount::estaVacio()
{
    return head == 0;
}

void listaMount::add(string path, string name)
{
    NodoMount *nuevo = new NodoMount(path, name);
    bool existe = false;
    string t;
    char letraC;
    letraC = ascii;
    t = letraC;

    if(estaVacio())
    {
        Paths->add(path, t, 1);

        nuevo->setId("vda1");
        head = nuevo;
        cola = nuevo;
        ascii++;

    }else {
        int j;
        for(int x = 0; x < Paths->tam; x++)
        {
            if(Paths->get(x).path == path){
                j = Paths->get(x).num;
                j++;
                nuevo->setId("vd" + Paths->get(x).letra + to_string(j));
                Paths->setNum(x, j);
                existe = true;
            }
        }

        if(!existe)
        {
            Paths->add(path, t, 1);
            nuevo->setId("vd" + t + to_string(1));
            ascii++;
            existe = false;
        }

        nuevo->setPrev(cola);
        cola->setNext(nuevo);
        cola = nuevo;
    }
    tam++;
    cout << nuevo->getValor().id << endl;
}

MOUNT listaMount::get(int x)
{
    NodoMount *aux = head;
    for(int n = 0; n < x; n++)
    {
        aux = aux->getNext();
    }
    return aux->getValor();
}

void listaMount::borrar(int x)
{
    if(x < tam){
        NodoMount *aux;
        if(x == 0)
        {
            aux = head->getNext();
            head->setNext(0);
            aux->setPrev(0);
            head = aux;
        }else if(x == tam-1){
            aux = cola->getPrev();
            cola->setPrev(0);
            aux->setNext(0);
            cola = aux;
        }else{
            aux = head;
            for(int n = 0; n < x; n++)
            {
              aux = aux->getNext();
            }
            aux->getPrev()->setNext(aux->getNext());
            aux->getNext()->setPrev(aux->getPrev());
            aux->setNext(0);
            aux->setPrev(0);
        }
        aux = 0;
        tam--;
    }
}



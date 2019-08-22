#ifndef ANALIZADORLEXICO_H
#define ANALIZADORLEXICO_H
#include <string>
#include "listatokens.h"
#include "listamount.h"

using namespace std;

class analizadorLexico
{
public:
    analizadorLexico();
    listaTokens *lista;
    string token;
    listaMount *listaMontar;

    void analizar(string t);
    void ejecutar();
    void crearDisco(string size, string path, string fit, string unit);
    void eliminarDisco(string path);
    void montar(string path, string name);
    void crearParticion(string size, string fit, string unit, string path, string type, string borrar, string name, string add);
};

#endif // ANALIZADORLEXICO_H

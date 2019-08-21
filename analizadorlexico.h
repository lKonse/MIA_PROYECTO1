#ifndef ANALIZADORLEXICO_H
#define ANALIZADORLEXICO_H
#include <string>
#include "listatokens.h"

using namespace std;

class analizadorLexico
{
public:
    analizadorLexico();
    listaTokens *lista;
    string token;

    void analizar(string t);
    void ejecutar();
    void crearDisco(string size, string path, string fit, string unit);
    void eliminarDisco(string path);
};

#endif // ANALIZADORLEXICO_H

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
};

#endif // ANALIZADORLEXICO_H

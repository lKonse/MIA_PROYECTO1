#include "analizadorlexico.h"
#include <iostream>
#include <cstring>

analizadorLexico::analizadorLexico()
{
    lista = new listaTokens();
    token = "";
}

void analizadorLexico::analizar(string t)
{
    int estado = 0;
    char variable;
    string t2 = t;
    lista = new listaTokens();
    token = "";

    int tam = t2.size() + 1;
        char texto[tam];
        strcpy(texto, t2.c_str());
        for(int x = 0; x < tam; x++)
        {
          variable = texto[x];
          switch (estado) {
            case 0:
              if(variable == ' '){

              }else if(texto[x] == '\t')
              {

              }else if(texto[x] == '\n'){

              }else if(variable >= 65 && variable <= 90)//Si es mayuscula
              {
                variable = tolower(variable);
                token += variable;
                estado = 1;
              }else if(variable >= 97 && variable <= 122)//Si es minuscula
              {
                  token += variable;
                  estado = 1;
              }
            break;
            case 1:
              if(variable >= 48 && variable <= 57)//si es un digito
              {
                token += variable;
              }else if(variable >= 65 && variable <= 90)//Si es mayuscula
              {
                variable = tolower(variable);
                token += variable;
              }else if(variable >= 97 && variable <= 122)//Si es minuscula
              {
                  token += variable;
              }else if(variable == '-')
              {
                lista->add(token);
                token = "";
                estado = 2;
              }
            break;
          }
            /*if(texto[x] == ' ')
            {
                cout << "espacio-----------------------------------------" <<endl;
            }else if(texto[x] == '\t')
            {
                cout << "tabulacion-----------------------------------------" <<endl;

            }else if(texto[x] == '\n'){
                cout << "salto-----------------------------------------" <<endl;
            }
            else
            {
                cout << texto[x] << endl;
            }*/


        }


}

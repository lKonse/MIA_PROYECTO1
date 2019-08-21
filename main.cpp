#include <QCoreApplication>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "listatokens.h"
#include "analizadorlexico.h"
#include <iostream>
#include <cstring>

//extern int yyrestart( FILE* archivo);
//extern int yyparse();

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /*FILE* input = fopen("/home/pablorocad/Escritorio/operacion.txt", "r");
            yyrestart(input);
            yyparse();*/



    //cout << "Escriba el nombre del archivo a leer: " << endl;
        string filename = "/home/pablorocad/Escritorio/operacion.txt";
        //cin >> filename;
        ifstream file(filename.c_str());
        if(!file)
        {
            cout << "Error no se puede abrir el archivo: " << filename << endl;
                    return 1;
        }
        string linea, archivo;
        while(getline(file, linea))
            archivo += linea + "\n";
        //cout << archivo;

        analizadorLexico *analizador = new analizadorLexico();
        analizador->analizar(archivo);

        /*int tam = archivo.size() + 1;
        char texto[tam];
        strcpy(texto, archivo.c_str());
        for(int x = 0; x < tam; x++)
        {
            if(texto[x] == ' ')
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
            }


        }*/


    /*cout <<"Hola" << endl;
    listaTokens *lista = new listaTokens();
    lista->add("Pablo1");
    lista->add("Pablo2");
    lista->add("Pablo3");
    lista->add("Pablo4");
    lista->add("Pablo5");

    for(int n = 0; n < lista->tam; n++){
        cout << lista->get(n) << endl;
    }*/

    return a.exec();
}

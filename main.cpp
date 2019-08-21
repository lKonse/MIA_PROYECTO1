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


        /*string st1 = "/home/pablorocad/Escritorio/disco1.disk";
        st1.replace(st1.size()-5, 5, "_ra1.disk");
        cout<<st1<<endl;

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
        analizador->analizar(archivo);*/

    /*int v = rand()%40;
    while(v != 39)
    {
        cout << "aleatorio: " << v << endl;
        v = rand()%40;
    }*/


    return a.exec();
}

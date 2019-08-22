#include <QCoreApplication>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "listatokens.h"
#include "analizadorlexico.h"
#include <iostream>
#include <cstring>
#include "listamount.h"

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

    /*listaMount *lista = new listaMount();
    lista->add("P1","N1");
    lista->add("P2","N2");
    lista->add("P3","N3");
    lista->add("P4","N4");
    lista->add("P5","N5");
    lista->add("P6","N6");
    lista->add("P7","N7");

    for(int x = 0; x < lista->tam; x++)
    {
        cout << lista->get(x).name << endl;
    }

    lista->borrar(0);
    lista->borrar(3);
    lista->borrar(4);
    lista->borrar(2);
    cout << "" << endl;
    cout << "" << endl;

    for(int x = 0; x < lista->tam; x++)
    {
        cout << lista->get(x).name << endl;
    }




        string st1 = "/home/pablorocad/Escritorio/disco1.disk";
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

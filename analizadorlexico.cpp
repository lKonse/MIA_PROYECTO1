#include "analizadorlexico.h"
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>


typedef struct datosDisco{
    int tamanio;
    char* fecha;
    //char fit[1];
}DATOSDISCO;


analizadorLexico::analizadorLexico()
{
    lista = new listaTokens();
    token = "";
}

void analizadorLexico::crearDisco(string size, string path, string fit, string unit)
{
    char comando[500];
    char tamanio[1024];
    int tam = 0;
    int n = atoi(size.c_str());


        memset(&comando[0], 0, sizeof(comando));
        memset(&tamanio[0], 0, sizeof(tamanio));
        strcat(comando, "dd if=/dev/zero of=");

        tam = path.size() + 1;
        char tempPath[tam];
        strcpy(tempPath, path.c_str());

        strcat(comando, tempPath);//escribirmos la direccion

        if(unit == "" || unit == "m" || unit == "M")
        {
            strcat(comando, " bs=1MB count=");
        }else if(unit == "k" || unit == "K")
        {
            strcat(comando, " bs=1024 count=");
        }

        tam = size.size() + 1;
        char tempSize[tam];
        strcpy(tempSize, size.c_str());

        strcat(comando, tempSize);//tamaño del disco (archivo)
        system(comando);//creamos el disco

        time_t now = time(0);
        char* dt = ctime(&now);//tomamos la fecha y hora

        DATOSDISCO disco;
        char aux[500];
        memset(&aux[0], 0, sizeof(aux));
        strcat(aux, tempPath);

        FILE* escritor = fopen(aux, "rb+");
        fseek(escritor, 0, SEEK_SET);
        disco.tamanio = n;
        //disco.fecha = dt;

        fwrite(&disco, sizeof(DATOSDISCO), 1, escritor);
        fclose(escritor);

}

void analizadorLexico::ejecutar()
{
    string comando = "", elemento = "";
    int n = 0;
    string size = "", path = "", fit = "", unit = "", type = "", borrar = "", name = "", add = "", id = "";

    for(int x = 0; x < lista->tam; x++)
    {
        comando = lista->get(x);

        if(comando == "mkdisk")
        {
            n = x+1;
            while(elemento != "NUEVO")
            {
                elemento = lista->get(n);

                if(elemento == "-size")
                {
                    size = lista->get(n+2);
                }else if(elemento == "-fit")
                {
                    fit = lista->get(n+2);
                }else if(elemento == "-unit")
                {
                    unit = lista->get(n+2);
                }else if(elemento == "-path")
                {
                    path = lista->get(n+2);
                }

                n++;
            }

            crearDisco(size, path, fit, unit);

        }
    }
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
              if(variable == ' '){

              }else if(texto[x] == '\t')
              {

              }else if(texto[x] == '\n'){

              }else if(variable >= 48 && variable <= 57)//si es un digito
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
                token += variable;
                estado = 0;
              }else if(variable == '=')
              {
                lista->add(token);
                lista->add("=");
                token = "";
                estado = 2;
              }
            break;
            case 2:
              if(variable == '-')
              {
                lista->add(token);
                token = "";
                token += variable;
                estado = 0;
              }else if(texto[x] == '\n'){
                lista->add(token);
                lista->add("NUEVO");
                token = "";
                estado = 0;
              }else if(variable == ' '){

              }else if(texto[x] == '\t')
              {

              }else if(variable >= 65 && variable <= 90)//Si es mayuscula
              {
                token += variable;
              }else{
                token += variable;
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

        for(int x = 0; x < lista->tam; x++)
        {
          cout << lista->get(x)<< endl;
        }

        ejecutar();

}

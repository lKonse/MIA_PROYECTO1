#include "analizadorlexico.h"
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>


typedef struct datosParticion{
  char* status;
  char* type;
  char* fit;
  int start;
  int size;
  char name[16];
}PARTITION;

typedef struct datosDisco{
    int tamanio;
    char* fecha;
    int signature;
    char fitDisco;
    PARTITION part[4];
}MBR;


analizadorLexico::analizadorLexico()
{
    lista = new listaTokens();
    token = "";
}

void analizadorLexico::crearDisco(string size, string path, string fit, string unit)
{
    char comando[500];
    char comando2[500];
    char tamanio[1024];
    int tam = 0;


    int MBRsize = atoi(size.c_str());

    time_t now = time(0);
    char* MBRdt = ctime(&now);//tomamos la fecha y hora

    int MBRsignature = rand()%10000;

    char MBRfit;
    if(fit == "BF"){
      MBRfit = 'B';
    }else if(fit == "FF" || fit == ""){
      MBRfit = 'F';
    }else if (fit == "WF") {
        MBRfit = 'W';
    }


        memset(&comando[0], 0, sizeof(comando));//limpiamos variables
        memset(&comando2[0], 0, sizeof(comando2));//limpiamos variables
        memset(&tamanio[0], 0, sizeof(tamanio));
        strcat(comando, "dd if=/dev/zero of=");//seteamos de ceros el archivo
        strcat(comando2, "dd if=/dev/zero of=");//seteamos de ceros el archivo

        tam = path.size() + 1;
        char tempPath[tam];
        strcpy(tempPath, path.c_str());
        strcat(comando, tempPath);//escribirmos la direccion

        if(unit == "" || unit == "m" || unit == "M")
        {
            MBRsize = MBRsize*1024*1024;

            strcat(comando, " bs=1MB count=");
        }else if(unit == "k" || unit == "K")
        {
            MBRsize = MBRsize*1024;
            strcat(comando, " bs=1024 count=");
        }

        tam = size.size() + 1;
        char tempSize[tam];
        strcpy(tempSize, size.c_str());

        strcat(comando, tempSize);//tamaño del disco (archivo)
        system(comando);//creamos el disco----------------------------

        MBR disco;
        char aux[500];
        memset(&aux[0], 0, sizeof(aux));
        strcat(aux, tempPath);


        FILE* escritor = fopen(aux, "rb+");//rb+ funcion para abrir un archivo binario en escritura y lectura
        fseek(escritor, 0, SEEK_SET);//seteamos desde la posicion 0 la informacion
        disco.tamanio = MBRsize;
        disco.fecha = MBRdt;
        disco.signature = MBRsignature;
        disco.fitDisco = MBRfit;
        fwrite(&disco, sizeof(MBR), 1, escritor);//Escribo las estructuras en el archivo
        fclose(escritor);

        /*fclose(escritor);
        //escribir algo nuevo----------------------------------------------------------------------------------------

        MBR temp;//DELCARO ESTRUCTURA
        fseek(escritor, 0, SEEK_SET);//nos posicionamos la inicio
        fread(&temp, sizeof(MBR), 1, escritor);//obtengo la estructura (datos)
        temp.signature = 8200;//nuevo elemento
        fseek(escritor, 0, SEEK_SET);
        fwrite(&temp, sizeof(MBR), 1, escritor);




        //Mostrar datos---------------------------------------
        MBR d;
        fseek(escritor, 0, SEEK_SET);
        // fread sera la herramienta para obtener los datos y los parametros son los mismos que el fwrite
        fread(&d, sizeof(MBR), 1, escritor);
        printf("------------------------------\n");
        printf(" tamanio: %d\n", d.tamanio);
        printf(" time: %s\n", d.fecha);
        printf(" asignature: %d\n", d.signature);
        printf(" fit: %c\n", d.fitDisco);
        printf("------------------------------\n");*/

}

void analizadorLexico::eliminarDisco(string path)
{
    int tam = path.size() + 1;
    char tempPath[tam];
    strcpy(tempPath, path.c_str());

    if(remove(tempPath) == 0)
    {
      cout << "Disco eliminado" << endl;
    }else{
      cout << "ERROR: No existe el disco" << endl;
    }
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
            elemento = "";
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

            string pathRa = path;
            pathRa.replace(pathRa.size()-5, 5, "_ra1.disk");
            crearDisco(size, path, fit, unit);
            crearDisco(size, pathRa, fit, unit);

        }else if(comando == "rmdisk"){
          elemento = "";
          n = x+1;
          while(elemento != "NUEVO")
          {
              elemento = lista->get(n);

              if(elemento == "-path")
              {
                  path = lista->get(n+2);
              }
              n++;
          }
          eliminarDisco(path);
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

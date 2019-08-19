%{
#include "scanner.h"//se importa el header del analisis sintactico

#include <iostream> //libreria para imprimir en cosola de C

#include <QString> //libreria para manejo de STRINGS de QT

#include <QHash> //Libreria para manejar HASH TABLES de QT, se usa para la tabla de simbolos

#include "tablas.h" //clase que contiene los valores de la tabla de simbolos

//#include <QTextEdit> //libreria QTextEdit de QT para poder mostrar el resultado en pantalla

using namespace std;

extern int yylineno; //linea actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern int columna; //columna actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern char *yytext; //lexema actual donde esta el parser (analisis lexico) lo maneja BISON

int yyerror(const char* mens){
//metodo que se llama al haber un error sintactico
//SE IMPRIME EN CONSOLA EL ERROR
std::cout <<mens<<" "<<yytext<< std::endl;
return 0;
}

/*QTextEdit* salida; //puntero al QTextEdit de salida
void setSalida(QTextEdit* sal) {
//metodo que asigna el valor al QTextEdit de salida
salida=sal;
}*/

QHash <QString, tablas*> tabla_s; //TABLA DE SIMBOLOS

struct Operador{
//ESTRUCTURA LA CUAL CONTENDRA LOS TIPOS DE LOS NO TERMINALES PARA HEREDAR VALORES
QString  texto;
int valor;
};

%}
//error-verbose si se especifica la opcion los errores sintacticos son especificados por BISON
%error-verbose

%union{
//se especifican los tipo de valores para los no terminales y lo terminales
char TEXT [256];
struct Operador * VAL;
}
//TERMINALES DE TIPO TEXT, SON STRINGS
%token<TEXT> Niden
%token<TEXT> Nnum
%token<TEXT> print
%token<TEXT>  mas
%token<TEXT>  menos
%token<TEXT>  por
%token<TEXT>  igual
%token<TEXT>  coma
%token<TEXT>  aparen
%token<TEXT>  cparen
//NO TERMINALES DE TIPO VAL, POSEEN ATRIBUTOS INT VALOR, Y QSTRING TEXTO
%type<VAL>  E
%type<VAL>  S
%type<VAL>  L
//LOS NO TERMINALES PUEDEN SER DE DIFERENTE TIPO, LOS TERMINALES SIEMPRE SON STRINGS O NO SE ESPECIFICA TIPO
//PRECEDENCIA DE LOS OPERADORES PARA QUITAR LA AMBIGUEDAD DEN LA GRAMTICA
%left mas menos
%left por

%%
L : S L
   |S;

S : print aparen E cparen coma{
        //SE IMPRIME EN PANTALLA EL RESULTADO DE PRINT
        QString temp=QString::number($3->valor);//CONVIERTE DE INT A QSTRING
        //salida->append(temp);
        cout << temp.toStdString() << endl;
    }

    |Niden igual E coma{
        //SE INSERTA EN LA TABLA DE SIMBOLOS LA VARIABLE Niden, representada por $1, y se asigna el valor de E ($3)
        tablas* temp=new tablas();
        temp->nom=$1;
        temp->valor=$3->valor;
        tabla_s.insert($1,temp);
    };

E : E mas E{
        //OPERACION MAS
        $$=$1;//EL VALOR DE E ES IGUAL E1, PARA NO DESPERDICIAR MEMORIA
        $$->valor = $1->valor + $3->valor; //SE MULTIPLICAN LOS VALORES E=E1*E2
    }

    |E por E{
        //OPERACION POR
        $$=$1;//EL VALOR DE E ES IGUAL E1, PARA NO DESPERDICIAR MEMORIA
        $$->valor = $1->valor * $3->valor; //SE MULTIPLICAN LOS VALORES E=E1*E2
    }

    |E menos E{
        //OPERACION MENOS
        $$=$1;//EL VALOR DE E ES IGUAL E1, PARA NO DESPERDICIAR MEMORIA
        $$->valor = $1->valor - $3->valor; //SE RESTAN LOS VALORES E=E1-E2
    }

    |Niden{
        $$=new Operador(); //$$ EQUIVALE AL VALOR DE E
        tablas* temp;
        if (tabla_s.contains($1)){ //SI LA VARIABLE Niden EQUIVALENTE A $1, EXISTE EN LA TABLA DE SIMBOLOS
            temp=tabla_s[$1];
            $$->valor=temp->valor; //RECUPERA EL VALOR Y LO ASIGNA A E->VALOR
        }
        else{
        //SI LA VARIALBE $1 NO EXISTE CREA LA VARIABLE EN LA TABLA DE SIMBOLOS Y LE ASIGNA VALOR 0
            temp=new tablas();
            temp->nom=$1;
            tabla_s.insert($1,temp);
            $$->valor=0;
        }
    }

    |Nnum{
        $$=new Operador(); //$$ EQUIVALE AL VALOR DE E
        QString temp = $1;
        $$->valor= temp.toInt();
    };

%%

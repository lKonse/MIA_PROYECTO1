%{
#include "scanner.h"//se importa el header del analisis sintactico

#include <iostream> //libreria para imprimir en cosola de C

#include <QString> //libreria para manejo de STRINGS de QT

#include <QHash> //Libreria para manejar HASH TABLES de QT, se usa para la tabla de simbolos

//#include <QTextEdit> //libreria QTextEdit de QT para poder mostrar el resultado en pantalla

using namespace std;

extern int yylineno; //linea actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern int columna; //columna actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern char *yytext; //lexema actual donde esta el parser (analisis lexico) lo maneja BISON

int yyerror(const char* mens){
//metodo que se llama al haber un error sintactico
//SE IMPRIME EN CONSOLA EL ERROR
std::cout <<mens<<" "<<yytext<<std::endl;
return 0;
}

/*QTextEdit* salida; //puntero al QTextEdit de salida
void setSalida(QTextEdit* sal) {
//metodo que asigna el valor al QTextEdit de salida
salida=sal;
}*/

//QHash <QString, tablas*> tabla_s; //TABLA DE SIMBOLOS

struct Operador{
//ESTRUCTURA LA CUAL CONTENDRA LOS TIPOS DE LOS NO TERMINALES PARA HEREDAR VALORES
QString  texto;

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
%token<TEXT> igual
%token<TEXT> guion
%token<TEXT> comillas
%token<TEXT> espacio
%token<TEXT> ruta
%token<TEXT> identificador
%token<TEXT> num
%token<TEXT> mkdisk
%token<TEXT> rmdisk
%token<TEXT> fdisk
%token<TEXT> mount
%token<TEXT> unmount
%token<TEXT> rep
%token<TEXT> exec
%token<TEXT> size
%token<TEXT> fit
%token<TEXT> unit
%token<TEXT> path
%token<TEXT> type
%token<TEXT> borrar
%token<TEXT> name
%token<TEXT> add
%token<TEXT> id
%token<TEXT> BF
%token<TEXT> FF
%token<TEXT> WF
%token<TEXT> kilo
%token<TEXT> mega
%token<TEXT> byte
%token<TEXT> primaria
%token<TEXT> extendida
%token<TEXT> logica
%token<TEXT> fast
%token<TEXT> full

//NO TERMINALES DE TIPO VAL, POSEEN ATRIBUTOS INT VALOR, Y QSTRING TEXTO
%type<TEXT>  INITIAL
%type<TEXT>  S
%type<TEXT>  CO
%type<TEXT>  MK
%type<TEXT>  MKK
%type<TEXT>  CADS
%type<TEXT>  FIT
%type<TEXT>  UN
%type<TEXT>  TY
%type<TEXT>  DE
//LOS NO TERMINALES PUEDEN SER DE DIFERENTE TIPO, LOS TERMINALES SIEMPRE SON STRINGS O NO SE ESPECIFICA TIPO
//PRECEDENCIA DE LOS OPERADORES PARA QUITAR LA AMBIGUEDAD DEN LA GRAMTICA

%%
INITIAL : S{cout << "Zi" << endl;};
S : S CO
    |CO
  ;

CO : mkdisk MK
    |rmdisk guion path igual CADS
    |fdisk MK
    |mount MK
    |unmount guion id igual identificador
    |rep MK
    |exec guion path igual CADS
;

MK : MK guion MKK
    |guion MKK
;

MKK : size igual num
    |fit igual FIT
    |unit igual UN
    |path igual CADS{cout << "HEHE" << endl;}
    |type igual TY
    |borrar igual DE
    |name igual CADS
    |add igual num
    |id igual identificador
    ;

CADS : ruta
    |comillas ruta comillas
;

FIT : BF
    |FF
    |WF
;

UN : kilo
    |mega
    |byte
;

TY : primaria
    |extendida
    |logica
;

DE : fast
    |full
;


%%

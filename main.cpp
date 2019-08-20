#include <QCoreApplication>
#include <stdio.h>
#include <stdlib.h>
extern int yyrestart( FILE* archivo);
extern int yyparse();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FILE* input = fopen("/home/pablorocad/Escritorio/operacion.txt", "r");
        yyrestart(input);
        yyparse();

    return a.exec();
}

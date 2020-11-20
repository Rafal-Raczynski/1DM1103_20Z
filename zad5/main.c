#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studenci.h"
#include "dziekanat.h"


int main(int argc, char ** argv) {
    student dane[100];
    int ile;
    ile = wczytaj(dane, argv[1]);
    if(strcmp("student",argv[2])==0)
    najlepszy_student(dane, ile);
    if(strcmp("najlepszy_p",argv[2])==0)
    najlepszy_przedmiot(dane, ile);
    if(strcmp("najgorszy_p",argv[2])==0)
    najgorszy_przedmiot(dane, ile);
    
    return 0;
}
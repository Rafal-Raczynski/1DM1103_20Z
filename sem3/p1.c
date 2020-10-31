#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    float a,b;
       
    if(argc>1)
    printf("Suma:%f\n", atof(argv[1])+atof(argv[2]));
    else if (argc==1)
    printf("Nie podano ani jednej liczby\n");
    
}
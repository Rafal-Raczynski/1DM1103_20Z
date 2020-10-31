#include<stdio.h>
#include<stdlib.h>

int dlugosc_napisu(char napis[])
{
    //int l=0;
    //for(l=0;napis[l]!=0;l++)
   //     ;
   // return l;

   int l=0;
   while(napis[l]!=0)
    l++;
    return l;

}

void skopiuj(char gdzie[], char co[], int max)
{
    int i=0;
    while ((co[i]!=0) && (i<max))
    {
        gdzie[i]=co[i];
        i++;
    }
}

void nawielkie(char n[])
{
    char male[]="abcdefghijklmopqrstuvwxyz"
    char duze[]=
}

//cel:
//dlugosc napisu
//skopiowac

int main(int argc,char *argv[])
{
    char napis[255];
    printf("%s ma dlugosc: %d", argv[1],dlugosc_napisu(argv[1]));

    skopiuj(napis,argv[2],254)
    printf("%s ma dlugosc: %d", napis,dlugosc_napisu(napis));

    


    return 0;
}
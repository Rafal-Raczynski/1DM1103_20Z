#ifndef _WCZYT_H
#define _WCZYT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct macierz 
{
    int wiersze;
    int kolumny;
    float **tab;
};
struct macierz* wczytaj(char *fnazwa);
void wypisz(struct macierz m);
void wypisztxt(char *fnazwa,struct macierz m);
void zwolnij(struct macierz *m);   

#endif
#ifndef _STUDENCI_H
#define _STUDENCI_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student {
    char imie[25];
    char nazwisko[50];
    char nr_albumu[10];
    char kod_przed[10];
    char nazwa_przed[255];
    float ocena;
    int ects;
} student;


int wczytaj(student dane[100], char *fnazwa);
void wypisz(student dane[100], int n);
int znajdz_k(char *szukany_kod, char kod[100][10], int n);
int znajdz_kod(char kod[100][10], student dane[100], int n);
int znajdz_s(char *szukany_nr, char nr_albumow[100][10], int n);
int znajdz_studentow(char nr_albumow[100][10], student dane[100], int n);

#endif
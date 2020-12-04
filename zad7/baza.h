#ifndef _BAZA_H
#define _BAZA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Student {
    char * imie;
    char * nazwisko;
    char * nr_albumu;
    char * email;

    struct _Student *nast;
} Student;

 typedef struct _Przedmiot {
     char * kod;
     char * nazwa;
     char * semestr;
     struct _Przedmiot *nast;
 } Przedmiot;

 typedef struct _Ocena {
     char * kod;
     char * nr_albumu;
     float ocena;
     char * komentarz;
     struct _Ocena *nast;
 } Ocena;


typedef struct _SBaza {
    Student *lista_studentow; /* Głowa listy! */
    Przedmiot *lista_przedmiotow;
    Ocena *lista_ocen;

} SBaza;



Student * wczytaj_studentow(FILE *fin);
Ocena * wczytaj_oceny(FILE *fin);
Przedmiot * wczytaj_przedmioty(FILE *fin);
SBaza * wczytaj_baze(char *nazwa_pliku);
void zapisz_baze(char *nazwa_pliku, SBaza * baza);
void listuj_studentow(SBaza *baza);
void listuj_przedmioty(SBaza *baza);
void listuj_oceny(SBaza *baza);
void zwolnij(SBaza *baza);
void zwolnij_liste_studentow(Student *s);
void zwolnij_liste_przedmiotow(Przedmiot *s);
void zwolnij_liste_ocen(Ocena *s);
void zwolnij_student(Student *s);
void zwolnij_przedmiot(Przedmiot *s);
void zwolnij_ocena(Ocena *s);
int ile_studentow(SBaza *baza);
int ile_przedmiotow(SBaza *baza);
int ile_ocen(SBaza *baza);
void dodaj_studenta(SBaza *baza,char* imie,char* nazwisko, char *nr_albumu, char * mail);
void dodaj_przedmiot(SBaza *baza,char* kod,char* nazwa, char *semestr);
void dodaj_ocene(SBaza *baza,char* kod,char* nr_albumu, float ocena, char * komentarz);



//SBaza* dodaj_studenta(SBaza *m,char* imie,char* nazwisko, char *nr_albumu, char * mail);

#endif
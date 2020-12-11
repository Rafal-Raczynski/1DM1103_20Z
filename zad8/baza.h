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
    
    struct _Student *poprz;
    struct _Student *nast;
} Student;

 typedef struct _Przedmiot {
     char * kod;
     char * nazwa;
     char * semestr;
     struct _Przedmiot *poprz;
     struct _Przedmiot *nast;
 } Przedmiot;

 typedef struct _Ocena {
     char * kod;
     char * nr_albumu;
     float ocena;
     char * komentarz;
     struct _Ocena *poprz;
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
void dodaj_studentadp(SBaza *baza, char *kod, char *nr_albumu);
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
void wypisz_rekurencyjnie(Student *el);
Student * ostatni(Student *glowa);
Student * usun(Student *glowa, Student *el);
Student * najwiekszy(Student *el);
Student * sortuj_przez_wybieranie_mal(Student *glowa);
Student * zwroc(Student *glowa, int i);
Student * sortuj_przez_wybieranie_ros(Student *glowa);
void listuj_studentow_od_konca(SBaza *b);
Przedmiot * ostatni_przed(Przedmiot *glowa);
Przedmiot * usun_przed(Przedmiot *glowa, Przedmiot *el);
Przedmiot * najwiekszy_przed_nazw(Przedmiot *el);
Przedmiot * najmniejszy_przed_nazw(Przedmiot *el);
Przedmiot * sortuj_przed_przez_wybieranie_mal_nazw(Przedmiot *glowa);
Przedmiot * sortuj_przed_przez_wybieranie_ros_nazw(Przedmiot *glowa);
Przedmiot * najwiekszy_przed_kod(Przedmiot *el);
Przedmiot * najmniejszy_przed_kod(Przedmiot *el);
Przedmiot * sortuj_przed_przez_wybieranie_mal_kod(Przedmiot *glowa);
Przedmiot * sortuj_przed_przez_wybieranie_ros_kod(Przedmiot *glowa);
void filtruj_nazwa(SBaza *baza,char*kod);
void filtruj_stud(SBaza *baza,char*nr_albumu);



//SBaza* dodaj_studenta(SBaza *m,char* imie,char* nazwisko, char *nr_albumu, char * mail);

#endif
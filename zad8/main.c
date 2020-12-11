#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baza.h"

int main(int argc, char ** argv) {
    SBaza *baza;
    
    baza = wczytaj_baze(argv[1]);  
    if (strcmp("list_students", argv[2]) == 0) {
        listuj_studentow(baza);
    } else if (strcmp("add_student", argv[2]) == 0) {
         dodaj_studenta(baza, argv[3], argv[4], argv[5], argv[6]);
    } else if (strcmp("count_students", argv[2]) == 0) {
        printf("Liczba studentów: %d\n", ile_studentow(baza));
    } else if (strcmp("add_subject", argv[2]) == 0) {
        dodaj_przedmiot(baza, argv[3], argv[4], argv[5]);
    } else if (strcmp("add_ocenka", argv[2]) == 0) {
        dodaj_ocene(baza, argv[3], argv[4], atof(argv[5]),argv[6]);
    } else if (strcmp("add_studp", argv[2]) == 0) {
        dodaj_studentadp(baza, argv[3], argv[4]);
    } else if (strcmp("sort_descending", argv[2]) == 0) {
        baza->lista_studentow = sortuj_przez_wybieranie_mal(baza->lista_studentow); 
        listuj_studentow(baza);
    } else if (strcmp("sort_ascending", argv[2]) == 0) {
        baza->lista_studentow = sortuj_przez_wybieranie_ros(baza->lista_studentow); 
        listuj_studentow(baza);
    }else if (strcmp("sort_descending_przed_nazw", argv[2]) == 0) {
        baza->lista_przedmiotow = sortuj_przed_przez_wybieranie_mal_nazw(baza->lista_przedmiotow); 
        listuj_przedmioty(baza);
    }else if (strcmp("sort_ascending_przed_nazw", argv[2]) == 0) {
        baza->lista_przedmiotow = sortuj_przed_przez_wybieranie_ros_nazw(baza->lista_przedmiotow); 
        listuj_przedmioty(baza);
    }else if (strcmp("sort_ascending_przed_kod", argv[2]) == 0) {
        baza->lista_przedmiotow = sortuj_przed_przez_wybieranie_ros_kod(baza->lista_przedmiotow); 
        listuj_przedmioty(baza);
    }else if (strcmp("sort_descending_przed_kod", argv[2]) == 0) {
        baza->lista_przedmiotow = sortuj_przed_przez_wybieranie_mal_kod(baza->lista_przedmiotow); 
        listuj_przedmioty(baza);
    }else if (strcmp("filtr_przed", argv[2]) == 0) {
        filtruj_nazwa(baza,argv[3]);
    }else if (strcmp("filtr_stud", argv[2]) == 0) {
        filtruj_stud(baza,argv[3]);}
        
    

    
    zapisz_baze(argv[1], baza);
    zwolnij(baza);
    return 0;
}
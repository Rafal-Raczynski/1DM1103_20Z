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
} student, *pstudent;

int wczytaj(student dane[100], char *fnazwa) {
    FILE * fin = fopen(fnazwa, "r");
    int cnt, i;
    char bufor[1024];
    char *w;

    fgets(bufor, 1023, fin);
    sscanf(bufor, "%d", &cnt);
 
    for (i=0; i<cnt; i++) {
        fgets(bufor, 1023, fin);
        // printf("%s", bufor);
        w = strtok(bufor, "|");
        strncpy(dane[i].imie, w, 24);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwisko, w, 49);
        
        w = strtok(NULL, "|");
        strncpy(dane[i].nr_albumu, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].kod_przed, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwa_przed, w, 254);

        w = strtok(NULL, "|");
        dane[i].ocena = atof(w);

        w = strtok(NULL, "|");
        dane[i].ects = atoi(w);
    }

    fclose(fin);
    return cnt;
}



int znajdz(char *szukany_kod, char kod[100][10], int n) {
    int i;
    for (i=0; i<n; i++) {
        if (strcmp(szukany_kod, kod[i]) == 0)
            return i;
    }
    return -1;
}

int znajdz_kod(char kod[100][10],char nazwa [100][40], student dane[100], int n) {
    int ile_znalazlem = 0;
    int i;
    

    for (i=0; i <n; i++) {
        if (znajdz(dane[i].kod_przed, kod, ile_znalazlem ) == -1) {
            strncpy(kod[ile_znalazlem], dane[i].kod_przed, 9);
            strncpy(nazwa[ile_znalazlem], dane[i].nazwa_przed, 40);
            ile_znalazlem++;
        }
    }
    return ile_znalazlem;
}


void najgorszy_i_najlepszy_przedmiot(student dane[100], int ile_rekordow) {
    char kod[100][10];
    int ile_przedmiot;
    float sumy_wazonych_ocen[100];
    int sumy_ects[100];
    int i;
    int pozycja;
    int najlepsza_pozycja;
    int najgorsza_pozycja;
    float najlepsza = 0.0f;
    float najgorsza = 1000;
    char nazwa [100][40];


    ile_przedmiot = znajdz_kod(kod, nazwa, dane, ile_rekordow);

    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz( dane[i].kod_przed, kod, ile_przedmiot );
        // if (pozycje >= 0)
        sumy_wazonych_ocen[pozycja] += dane[i].ocena * dane[i].ects;
        sumy_ects[pozycja] += dane[i].ects;
    }    

//for (i=0;i<ile_przedmiot; i++) 
//    printf("Przedmiot [%d]: %s %s - %f:%d - %f \n", i+1, kod[i], nazwa[i] ,
//    sumy_wazonych_ocen[i], sumy_ects[i], sumy_wazonych_ocen[i] / sumy_ects[i]);

    for (i=0; i < ile_przedmiot; i++) {
        if (najlepsza < sumy_wazonych_ocen[i] / sumy_ects[i]) {
            najlepsza = sumy_wazonych_ocen[i] / sumy_ects[i];
            najlepsza_pozycja = i;
        }
    }

    for (i=0; i < ile_przedmiot; i++) {
        if (najgorsza > sumy_wazonych_ocen[i] / sumy_ects[i]) {
            najgorsza = sumy_wazonych_ocen[i] / sumy_ects[i];
            najgorsza_pozycja = i;
        }
    }

    
    printf("Najlepsza średnia: %s %s - %.2f \n", 
         kod[najlepsza_pozycja], nazwa[najlepsza_pozycja],
        sumy_wazonych_ocen[najlepsza_pozycja] / sumy_ects[najlepsza_pozycja]
    );
    
    
    printf("Najgorsza średnia: %s %s - %.2f \n", 
         kod[najgorsza_pozycja], nazwa[najgorsza_pozycja],
        sumy_wazonych_ocen[najgorsza_pozycja] / sumy_ects[najgorsza_pozycja]
    );

}

int main(int argc, char ** argv) {
    student dane[100];
    int ile;
    // dane == &dane[0]
    ile = wczytaj(dane, argv[1]);

    najgorszy_i_najlepszy_przedmiot(dane, ile);

    return 0;
}
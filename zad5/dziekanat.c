#include "dziekanat.h"



void najlepszy_student(student dane[100], int ile_rekordow) {
    char nr_albumow[100][10];
    int ile_studentow;
    float sumy_wazonych_ocen[100];
    int sumy_ects[100];
    float srednie[100];
    int i;
    int pozycja;
    int najlepsza_pozycja;
    float najlepsza = 0.0f;
    for (int i=0; i<100; i++)
    {
        sumy_wazonych_ocen[i]=0;
        sumy_ects[i]=0;
        
    }

    ile_studentow = znajdz_studentow(nr_albumow, dane, ile_rekordow);

    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz_s( dane[i].nr_albumu, nr_albumow, ile_studentow );
        sumy_wazonych_ocen[pozycja] += dane[i].ocena * dane[i].ects;
        sumy_ects[pozycja] += dane[i].ects;
    }    



    for (i=0; i < ile_studentow; i++) {
        if (najlepsza < sumy_wazonych_ocen[i] / sumy_ects[i]) {
            najlepsza = sumy_wazonych_ocen[i] / sumy_ects[i];
            najlepsza_pozycja = i;
        }
    }

     printf("Najlepszy student: \n");
     printf("Student [%d]: %s - %f \n", 
        najlepsza_pozycja+1, nr_albumow[najlepsza_pozycja],
        sumy_wazonych_ocen[najlepsza_pozycja] / sumy_ects[najlepsza_pozycja]
    );

}

void najlepszy_przedmiot(student dane[100], int ile_rekordow) {
    char kod[100][10];
    int ile_przedmiot;
    float sumy_wazonych_ocen[100];
    int sumy_ects[100];
    int i;
    int pozycja;
    int najlepsza_pozycja;
    
    float najlepsza = 0.0f;
    char nazwa [100][200];
    for (int i=0; i<100; i++)
    {
        sumy_wazonych_ocen[i]=0;
        sumy_ects[i]=0;
        
    }


    ile_przedmiot = znajdz_kod(kod, dane, ile_rekordow);

    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz_k( dane[i].kod_przed, kod, ile_przedmiot );
        strncpy(nazwa[pozycja], dane[i].nazwa_przed, 40);
        sumy_wazonych_ocen[pozycja] += dane[i].ocena * dane[i].ects;
        sumy_ects[pozycja] += dane[i].ects;
    }    

    

    for (i=0; i < ile_przedmiot; i++) {
        if (najlepsza < sumy_wazonych_ocen[i] / sumy_ects[i]) {
            najlepsza = sumy_wazonych_ocen[i] / sumy_ects[i];
            najlepsza_pozycja = i;
        }
    }

   
    printf("Najlepsza średnia: %s %s - %.2f \n", 
         kod[najlepsza_pozycja], nazwa[najlepsza_pozycja],
        sumy_wazonych_ocen[najlepsza_pozycja] / sumy_ects[najlepsza_pozycja]
    );
    
    

}

   void najgorszy_przedmiot(student dane[100], int ile_rekordow) {
    char kod[100][10];
    int ile_przedmiot;
    float sumy_wazonych_ocen[100];
    int sumy_ects[100];
    int i;
    int pozycja;
    int najgorsza_pozycja;
    float najgorsza = 1000;
    char nazwa [100][200];
    for (int i=0; i<100; i++)
    {
        sumy_wazonych_ocen[i]=0;
        sumy_ects[i]=0;
        
    }
 
 
    ile_przedmiot = znajdz_kod(kod, dane, ile_rekordow);
 
    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz_k( dane[i].kod_przed, kod, ile_przedmiot );
        strncpy(nazwa[pozycja], dane[i].nazwa_przed, 40);
        sumy_wazonych_ocen[pozycja] += dane[i].ocena * dane[i].ects;
        sumy_ects[pozycja] += dane[i].ects;
    }    
 
    
 
    for (i=0; i < ile_przedmiot; i++) {
        if (najgorsza > sumy_wazonych_ocen[i] / sumy_ects[i]) {
            najgorsza = sumy_wazonych_ocen[i] / sumy_ects[i];
            najgorsza_pozycja = i;
        }
    }
 
    
    
    
    printf("Najgorsza średnia: %s %s - %.2f \n", 
         kod[najgorsza_pozycja], nazwa[najgorsza_pozycja],
        sumy_wazonych_ocen[najgorsza_pozycja] / sumy_ects[najgorsza_pozycja]
    );

}
 
 
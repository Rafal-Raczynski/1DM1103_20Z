#include "baza.h"
// rekurencja
void wypisz_rekurencyjnie(Student *el) {
    if (el != NULL) {
        printf("%s %s %s %s\n", el->imie, el->nazwisko, el->nr_albumu, el->email);        
        wypisz_rekurencyjnie( el->nast );
    }
}

Student * ostatni(Student *glowa) {
    Student *el = glowa;
    if (el != NULL) {
        while (el->nast != NULL)
            el = el->nast;

        return el;
    } else
        return NULL;
}

Student * usun(Student *glowa, Student *el) {
    Student *c = glowa;
    if (glowa == el) {
        glowa = glowa->nast;
    } else {
        while (c != NULL) {
            if (c == el) {
                c->poprz->nast = c->nast;
                if (c->nast != NULL)
                    c->nast->poprz = c->poprz;

                break;
            }

            c = c->nast;
        }
    }
    c->nast = NULL;
    c->poprz = NULL;
    return glowa;
}

Student * najwiekszy(Student *el) {
    Student * max = NULL;
    while (el != NULL) {
        if (max == NULL) {
            max = el;
        } else {
            if ( strcmp(el->nazwisko, max->nazwisko) > 0 ) 
                max = el;
        }
        el = el->nast;
    }
    return max;
}

Student * najmniejszy(Student *el) {
    Student * min = NULL;
    while (el != NULL) {
        if (min == NULL) {
            min = el;
        } else {
            if ( strcmp(el->nazwisko, min->nazwisko) < 0 ) 
                min = el;
        }
        el = el->nast;
    }
    return min;
}

Student * sortuj_przez_wybieranie_mal(Student *glowa) {
    Student * nglowa = NULL;
    Student * m;
    Student * o; // = NULL;

    while (glowa != NULL) {
        m = najwiekszy(glowa);
        glowa = usun(glowa, m);
        
        o = ostatni(nglowa);
        if (o == NULL) {
            nglowa = m;
        } else {
            o->nast = m;
            m->poprz = o;
        }
        // o = m;

        // printf("Najwiekszy: %s\n", m->nazwisko);
        // wypisz_rekurencyjnie(glowa);
    }

    return nglowa;
}

Student * sortuj_przez_wybieranie_ros(Student *glowa) {
    Student * nglowa = NULL;
    Student * m;
    Student * o; // = NULL;

    while (glowa != NULL) {
        m = najmniejszy(glowa);
        glowa = usun(glowa, m);
        
        o = ostatni(nglowa);
        if (o == NULL) {
            nglowa = m;
        } else {
            o->nast = m;
            m->poprz = o;
        }
        
    }

    return nglowa;
}

Student * zwroc(Student *glowa, int i) {
    while (glowa != NULL && i-- > 0) // i jest zmniejszany postfixowo - czyli po porownaniu z 0
        glowa = glowa->nast;    
    
    return glowa;
}

void listuj_studentow_od_konca(SBaza *b) {
    // Student *ogon = ostatni(b->lista_studentow);
    Student *c;
    /*
    while (c != null) {
        c = c->poprz;
    }
    */
    // for (c=ogon; c != NULL; c = c->poprz) {
    //     printf("%s %s %s %s\n", c->imie, c->nazwisko, c->nr_albumu, c->email);        
    // }

    int i;
    int n = ile_studentow(b);
    for (i=(n-1); i >= 0; i--) {
        c = zwroc(b->lista_studentow, i);
        printf("%s %s %s %s\n", c->imie, c->nazwisko, c->nr_albumu, c->email);        
    }
}

Przedmiot * ostatni_przed(Przedmiot *glowa) {
    Przedmiot *el = glowa;
    if (el != NULL) {
        while (el->nast != NULL)
            el = el->nast;

        return el;
    } else
        return NULL;
}

Przedmiot * usun_przed(Przedmiot *glowa, Przedmiot *el) {
    Przedmiot *c = glowa;
    if (glowa == el) {
        glowa = glowa->nast;
    } else {
        while (c != NULL) {
            if (c == el) {
                c->poprz->nast = c->nast;
                if (c->nast != NULL)
                    c->nast->poprz = c->poprz;

                break;
            }

            c = c->nast;
        }
    }
    c->nast = NULL;
    c->poprz = NULL;
    return glowa;
}

Przedmiot * najwiekszy_przed_nazw(Przedmiot *el) {
    Przedmiot * max = NULL;
    while (el != NULL) {
        if (max == NULL) {
            max = el;
        } else {
            if ( strcmp(el->nazwa, max->nazwa) > 0 ) 
                max = el;
        }
        el = el->nast;
    }
    return max;
}

Przedmiot * najmniejszy_przed_nazw(Przedmiot *el) {
    Przedmiot * min = NULL;
    while (el != NULL) {
        if (min == NULL) {
            min = el;
        } else {
            if ( strcmp(el->nazwa, min->nazwa) < 0 ) 
                min = el;
        }
        el = el->nast;
    }
    return min;
}

Przedmiot * sortuj_przed_przez_wybieranie_mal_nazw(Przedmiot *glowa) {
    Przedmiot * nglowa = NULL;
    Przedmiot * m;
    Przedmiot * o; // = NULL;

    while (glowa != NULL) {
        m = najwiekszy_przed_nazw(glowa);
        glowa = usun_przed(glowa, m);
        
        o = ostatni_przed(nglowa);
        if (o == NULL) {
            nglowa = m;
        } else {
            o->nast = m;
            m->poprz = o;
        }
        // o = m;

        // printf("Najwiekszy: %s\n", m->nazwisko);
        // wypisz_rekurencyjnie(glowa);
    }

    return nglowa;
}

Przedmiot * sortuj_przed_przez_wybieranie_ros_nazw(Przedmiot *glowa) {
    Przedmiot * nglowa = NULL;
    Przedmiot * m;
    Przedmiot * o; // = NULL;

    while (glowa != NULL) {
        m = najmniejszy_przed_nazw(glowa);
        glowa = usun_przed(glowa, m);
        
        o = ostatni_przed(nglowa);
        if (o == NULL) {
            nglowa = m;
        } else {
            o->nast = m;
            m->poprz = o;
        }
        
    }

    return nglowa;
}

Przedmiot * najwiekszy_przed_kod(Przedmiot *el) {
    Przedmiot * max = NULL;
    while (el != NULL) {
        if (max == NULL) {
            max = el;
        } else {
            if ( strcmp(el->kod, max->kod) > 0 ) 
                max = el;
        }
        el = el->nast;
    }
    return max;
}

Przedmiot * najmniejszy_przed_kod(Przedmiot *el) {
    Przedmiot * min = NULL;
    while (el != NULL) {
        if (min == NULL) {
            min = el;
        } else {
            if ( strcmp(el->kod, min->kod) < 0 ) 
                min = el;
        }
        el = el->nast;
    }
    return min;
}

Przedmiot * sortuj_przed_przez_wybieranie_mal_kod(Przedmiot *glowa) {
    Przedmiot * nglowa = NULL;
    Przedmiot * m;
    Przedmiot * o; // = NULL;

    while (glowa != NULL) {
        m = najwiekszy_przed_kod(glowa);
        glowa = usun_przed(glowa, m);
        
        o = ostatni_przed(nglowa);
        if (o == NULL) {
            nglowa = m;
        } else {
            o->nast = m;
            m->poprz = o;
        }
        // o = m;

        // printf("Najwiekszy: %s\n", m->nazwisko);
        // wypisz_rekurencyjnie(glowa);
    }

    return nglowa;
}

Przedmiot * sortuj_przed_przez_wybieranie_ros_kod(Przedmiot *glowa) {
    Przedmiot * nglowa = NULL;
    Przedmiot * m;
    Przedmiot * o; // = NULL;

    while (glowa != NULL) {
        m = najmniejszy_przed_kod(glowa);
        glowa = usun_przed(glowa, m);
        
        o = ostatni_przed(nglowa);
        if (o == NULL) {
            nglowa = m;
        } else {
            o->nast = m;
            m->poprz = o;
        }
        
    }

    return nglowa;
}

void filtruj_nazwa(SBaza *baza,char*kod)
{   
    Ocena* obecny;
    obecny=baza->lista_ocen;
    while(obecny!=NULL)
    {

        if(strcmp(obecny->kod,kod)==0)
        {
         if(obecny->ocena==0)
         printf("%s %s %c %s\n", obecny->kod, obecny->nr_albumu, ' ', obecny->komentarz);
         else
         printf("%s %s %.1f %s\n", obecny->kod, obecny->nr_albumu, obecny->ocena, obecny->komentarz);
        }
        
        obecny=obecny->nast;
    
    }
    
}
void filtruj_stud(SBaza *baza,char*nr_albumu)
{   
    Ocena* obecny;
    obecny=baza->lista_ocen;
    while(obecny!=NULL)
    {

        if(strcmp(obecny->nr_albumu,nr_albumu)==0)
        {
         if(obecny->ocena==0)
         printf("%s %s %c %s\n", obecny->kod, obecny->nr_albumu, ' ', obecny->komentarz);
         else
         printf("%s %s %.1f %s\n", obecny->kod, obecny->nr_albumu, obecny->ocena, obecny->komentarz);
        }
        
        obecny=obecny->nast;
    
    }
    
}



// rekurencja
void wypisz_rekurencyjnie_od_konca(Student *el) {
    if (el != NULL) {
        wypisz_rekurencyjnie( el->nast );
        printf("%s %s %s %s\n", el->imie, el->nazwisko, el->nr_albumu, el->email);        
    }
}

Student * wczytaj_studentow(FILE *fin) {
    char bufor[255];
    int n, i;
    char *s;
    Student *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    Student *c;

    for (i=0; i<n; i++) 
    {
        Student *stud = (Student*) malloc(sizeof(Student));
        stud->nast = NULL;
        stud->poprz = NULL;

        if (glowa == NULL)
            glowa = stud;
        else {
            c = ostatni(glowa);
            c->nast = stud;
            stud->poprz = c;
        }

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        stud->imie = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->imie, s);

        s = strtok(NULL, ";");
        stud->nazwisko = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nazwisko, s);

        s = strtok(NULL, ";");
        stud->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nr_albumu, s);

        s = strtok(NULL, "\n");
        stud->email = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->email, s);
    }

    return glowa;
}

SBaza * wczytaj_baze(char *nazwa_pliku) {
    FILE *fin = fopen(nazwa_pliku, "r");
    if (fin == NULL) {
        printf("BŁĄD! Nie moge otworzyc pliku: %s.\n", nazwa_pliku);
        exit(-1);
    }

    SBaza *baza = (SBaza*) malloc( sizeof(SBaza) );
    baza->lista_studentow = wczytaj_studentow(fin);
    baza->lista_przedmiotow = wczytaj_przedmioty(fin);
    baza->lista_ocen = wczytaj_oceny(fin);
    
        fclose(fin);
    return baza;
}

void zapisz_baze(char *nazwa_pliku, SBaza * baza) {
   
   int n=ile_studentow(baza);
   int m=ile_przedmiotow(baza);
   int r=ile_ocen(baza);

   FILE *fin = fopen(nazwa_pliku, "w+");
   Student * stud = baza->lista_studentow;
   Przedmiot* prze= baza->lista_przedmiotow;
   Ocena* oce= baza->lista_ocen;
   fprintf(fin,"%d\n",n);
    while (stud != NULL) {
        fprintf(fin,"%s;%s;%s;%s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud = stud->nast;
    }
   fprintf(fin,"%d\n",m);
   while (prze != NULL) {
       fprintf(fin,"%s;%s;%s\n", prze->kod, prze->nazwa, prze->semestr);
       prze = prze->nast;
   }
    fprintf(fin,"%d\n",r);
    while (oce != NULL) {
        if(oce->ocena==0)
        {
          fprintf(fin,"%s;%s;%s;%s\n", oce->kod, oce->nr_albumu, " ", oce->komentarz);  
        }
        else
        fprintf(fin,"%s;%s;%.1f;%s\n", oce->kod, oce->nr_albumu, oce->ocena, oce->komentarz);
        oce = oce->nast;
    }
    fclose(fin);
   
}

int ile_studentow(SBaza *baza) {
    int n = 0;
    Student * stud = baza->lista_studentow;
    while (stud != NULL) {
        n++;
        stud = stud->nast;
    }
    return n;
}

int ile_przedmiotow(SBaza *baza) {
    int n = 0;
    Przedmiot * prze = baza->lista_przedmiotow;
    while (prze != NULL) {
        n++;
        prze = prze->nast;
    }
    return n;
}

int ile_ocen(SBaza *baza) {
    int n = 0;
    Ocena * oce = baza->lista_ocen;
    while (oce != NULL) {
        n++;
        oce = oce->nast;
    }
    return n;
}

void listuj_studentow(SBaza *baza) {
    Student * stud = baza->lista_studentow;
    while (stud != NULL) {
        printf("%s %s %s %s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud = stud->nast;
    }
}

void listuj_przedmioty(SBaza *baza) {
    Przedmiot * prze = baza->lista_przedmiotow;
    while (prze != NULL) {
        printf("%s %s %s\n", prze->kod, prze->nazwa, prze->semestr);
        prze = prze->nast;
    }
}

void listuj_oceny(SBaza *baza) {
    Ocena * oce = baza->lista_ocen;
    while (oce != NULL) {
        printf("%s %s %f %s\n", oce->kod, oce->nr_albumu, oce->ocena, oce->komentarz);
        oce = oce->nast;
    }
}

void zwolnij_student(Student *s) {
    free(s->imie);
    free(s->nazwisko);
    free(s->nr_albumu);
    free(s->email);
    free(s);
}

void zwolnij_przedmiot(Przedmiot *s) {
    free(s->kod);
    free(s->nazwa);
    free(s->semestr);
    free(s);
}

void zwolnij_ocena(Ocena *s) {
    free(s->kod);
    free(s->nr_albumu);
    free(s->komentarz);
    free(s);
}

void zwolnij_liste_studentow(Student *s) {
    Student *n;
    while (s != NULL) {
        n = s->nast;
        zwolnij_student(s);
        s = n;
    }
}

void zwolnij_liste_przedmiotow(Przedmiot *s) {
    Przedmiot *n;
    while (s != NULL) {
        n = s->nast;
        zwolnij_przedmiot(s);
        s = n;
    }
}

void zwolnij_liste_ocen(Ocena *s) {
    Ocena *n;
    while (s != NULL) {
        n = s->nast;
        zwolnij_ocena(s);
        s = n;
    }
}

void zwolnij(SBaza *baza) {
    zwolnij_liste_studentow(baza->lista_studentow);
    zwolnij_liste_przedmiotow(baza->lista_przedmiotow);
    zwolnij_liste_ocen(baza->lista_ocen);
    free(baza);
}



void dodaj_studenta(SBaza *baza, char *imie, char *nazwisko, char *nr_albumu, char *email){
    
    Student *nowy=(Student*) malloc(sizeof(Student));
    Student *obecny=NULL;
    nowy->nast=NULL;
    nowy->imie = (char*) malloc( sizeof(char) * (strlen(imie) + 1));
    strcpy(nowy->imie, imie);
    nowy->nazwisko = (char*) malloc( sizeof(char) * (strlen(nazwisko) + 1));
    strcpy(nowy->nazwisko, nazwisko);
    nowy->nr_albumu = (char*) malloc( sizeof(char) * (strlen(nr_albumu) + 1));
    strcpy(nowy->nr_albumu, nr_albumu);
    nowy->email = (char*) malloc( sizeof(char) * (strlen(email) + 1));
    strcpy(nowy->email, email);
    obecny=baza->lista_studentow;
    if(ile_studentow(baza)==0)
    {
        baza->lista_studentow=nowy;
        
    }
    else{
    for(int i=1;i<ile_studentow(baza);i++)
    {   
        obecny=obecny->nast;
    }
    obecny->nast=nowy;}


    
}


void dodaj_przedmiot(SBaza *baza, char *kod, char *nazwa, char *semestr){
    Przedmiot *nowy=(Przedmiot*) malloc(sizeof(Przedmiot));
    Przedmiot *obecny=NULL;
    nowy->nast=NULL;
    nowy->kod = (char*) malloc( sizeof(char) * (strlen(kod) + 1));
    strcpy(nowy->kod, kod);
    nowy->nazwa = (char*) malloc( sizeof(char) * (strlen(nazwa) + 1));
    strcpy(nowy->nazwa, nazwa);
    nowy->semestr = (char*) malloc( sizeof(char) * (strlen(semestr) + 1));
    strcpy(nowy->semestr, semestr);
    obecny=baza->lista_przedmiotow;
    if(ile_przedmiotow(baza)==0)
    {
        baza->lista_przedmiotow=nowy;
        
    }
    else{
    for(int i=1;i<ile_przedmiotow(baza);i++)
    {
        obecny=obecny->nast;
    }
    obecny->nast=nowy;}    
    
}

void dodaj_ocene(SBaza *baza, char *kod, char *nr_albumu, float ocena, char *komentarz){
    Ocena *nowy=(Ocena*) malloc(sizeof(Ocena));
    Ocena *obecny=NULL;
    nowy->nast=NULL;
    nowy->kod = (char*) malloc( sizeof(char) * (strlen(kod) + 1));
    strcpy(nowy->kod, kod);
    nowy->nr_albumu = (char*) malloc( sizeof(char) * (strlen(nr_albumu) + 1));
    strcpy(nowy->nr_albumu, nr_albumu);
    nowy->ocena=ocena;
    nowy->komentarz = (char*) malloc( sizeof(char) * (strlen(komentarz) + 1));
    strcpy(nowy->komentarz, komentarz);
    obecny=baza->lista_ocen;
    if(ile_ocen(baza)==0)
    {
        baza->lista_ocen=nowy;
        
    }
    else{
    for(int i=1;i<ile_ocen(baza);i++)
    {
        obecny=obecny->nast;
    }
    obecny->nast=nowy;}    
    
}

void dodaj_studentadp(SBaza *baza, char *kod, char *nr_albumu){
    char* komentarz=" ";
    Ocena *nowy=(Ocena*) malloc(sizeof(Ocena));
    Ocena *obecny=NULL;
    nowy->nast=NULL;
    nowy->kod = (char*) malloc( sizeof(char) * (strlen(kod) + 1));
    strcpy(nowy->kod, kod);
    nowy->nr_albumu = (char*) malloc( sizeof(char) * (strlen(nr_albumu) + 1));
    strcpy(nowy->nr_albumu, nr_albumu);
    nowy->ocena=0;
    nowy->komentarz = (char*) malloc( sizeof(char) * (strlen(komentarz) + 1));
    strcpy(nowy->komentarz, komentarz);
    obecny=baza->lista_ocen;
    if(ile_ocen(baza)==0)
    {
        baza->lista_ocen=nowy;
        
    }
    else{
    for(int i=1;i<ile_ocen(baza);i++)
    {
        obecny=obecny->nast;
    }
    obecny->nast=nowy;}    
    
}

Przedmiot * wczytaj_przedmioty(FILE *fin) {


    char bufor[255];
    int n, i;
    char *s;
    Przedmiot *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);
    Przedmiot *c;

    for (i=0; i<n; i++) 
    {
        Przedmiot *prze = (Przedmiot*) malloc(sizeof(Przedmiot));
        prze->nast = NULL;
        prze->poprz = NULL;

        if (glowa == NULL)
            glowa = prze;
        else {
            c = ostatni_przed(glowa);
            c->nast = prze;
            prze->poprz = c;
        }
        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        prze->kod = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(prze->kod, s);

        s = strtok(NULL, ";");
        prze->nazwa = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(prze->nazwa, s);

        s = strtok(NULL, "\n");
        prze->semestr = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(prze->semestr, s);

    }

    return glowa;
}

Ocena * wczytaj_oceny(FILE *fin) {

    char bufor[255];
    int n, i;
    char *s;
    Ocena *last_ocena = NULL;
    Ocena *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i=0; i<n; i++) {
        Ocena *oce = (Ocena*) malloc(sizeof(Ocena));
        oce->nast = NULL;

        if (last_ocena == NULL)
            glowa = oce;
        else
            last_ocena->nast = oce;
        last_ocena = oce;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        oce->kod = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(oce->kod, s);

        s = strtok(NULL, ";");
        oce->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(oce->nr_albumu, s);
        
        s = strtok(NULL, ";");
        oce->ocena=atof(s);

        s = strtok(NULL, "\n");
        oce->komentarz = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(oce->komentarz, s);

    }

    return glowa;
}

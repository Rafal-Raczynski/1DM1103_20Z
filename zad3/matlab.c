#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Macierz 
{
    int kolumny;
    int wiersze;
    float tab[100][100];
};

void wczytaj(FILE * fin, struct Macierz *m) 
{
    fscanf(fin, "%d%d", &m->wiersze,&m->kolumny);

    for (int i=0; i < m->wiersze; i++) {
        for (int j=0; j < m->kolumny; j++) {
            fscanf(fin, "%f", &m->tab[i][j]);
        }
    }
}

void wypisz(struct Macierz m) 
{
    int i, j;
    printf("[ ");
    for (i = 0; i < m.wiersze; i++)
    {
        for (j=0; j < m.kolumny; j++) 
        {
        printf("%6.1f ", m.tab[i][j]);
        }
        if (i < (m.wiersze-1))
        printf("\n  ");
    }
    printf("]\n");
}

void wypisztxt(FILE *fin,struct Macierz m) 
{
    int i, j;
    fprintf(fin,"%d\n%d\n",m.wiersze,m.kolumny);
    for (i = 0; i < m.wiersze; i++)
    {
        for (j=0; j < m.kolumny; j++) 
        {
        fprintf(fin,"%.1f ",m.tab[i][j]);
        }
        fprintf(fin,"\n");
    }
}

void sum(struct Macierz m, struct Macierz n, struct Macierz *wynikowy)
{
    for(int i=0; i < m.wiersze; i++)
        for(int j=0; j < m.kolumny; j++)
            wynikowy->tab[i][j] = m.tab[i][j] + n.tab[i][j];
            wynikowy->wiersze=m.wiersze;
            wynikowy->kolumny=m.kolumny;
}

struct Macierz subtract(struct Macierz m, struct Macierz n,struct Macierz *wynikowy)
{
    for(int i=0; i < m.wiersze; i++)
        for(int j=0; j < m.kolumny; j++)
            wynikowy->tab[i][j] = m.tab[i][j] - n.tab[i][j];
            wynikowy->wiersze=m.wiersze;
            wynikowy->kolumny=m.kolumny;
}

struct Macierz prod(struct Macierz m, struct Macierz n, struct Macierz *wynikowy)
{   
    float sum=0;
    for(int i=0; i < m.wiersze; i++)
    {    for(int j=0; j < m.kolumny; j++)
        {   
            for(int k=0; k < m.kolumny; k++)
            wynikowy->tab[i][j] += m.tab[i][k] * n.tab[k][j];
        }
    }
    wynikowy->wiersze=m.wiersze;
    wynikowy->kolumny=m.kolumny;
}

float multiply(struct Macierz m, float a,struct Macierz *wynikowy) 
{
    for (int i=0; i < m.wiersze; i++) 
    {
        for (int j=0; j < m.kolumny; j++) 
        {
            wynikowy->tab[i][j]= a*m.tab[i][j];
        }
    }
    wynikowy->wiersze=m.wiersze;
    wynikowy->kolumny=m.kolumny;
}

float norm(struct Macierz m ) 
{
    float suma = 0;

    for (int i=0; i < m.wiersze; i++) 
    {
        for (int j=0; j < m.kolumny; j++) 
        {
            suma += m.tab[i][j] * m.tab[i][j];
        }
    }
    return sqrt(suma);
}


int main(int argc, char *argv[])
{
    struct Macierz m1,m2,wynikowa;

    FILE * plik1;
    FILE * plik2;
    FILE * plik3;

    if ( strcmp( argv[1], "sum") == 0 )
    {
        {
            plik1= fopen(argv[2],"r");
            plik2= fopen(argv[3],"r");
            wczytaj(plik1,&m1);
            wczytaj(plik2,&m2);
            if((m1.wiersze != m2.wiersze)|| (m1.kolumny != m2.kolumny))
            printf("Nie można dodać tych macierzy\n");
            else
            {
                sum(m1,m2,&wynikowa);
                if(argc>4)
                {
                    plik3= fopen(argv[4],"w+");
                    wypisztxt(plik3,wynikowa);
                    fclose(plik3);
                }
                else
                wypisz(wynikowa);
            }   
            fclose(plik1);
            fclose(plik2);
        }    
    }   else if(strcmp( argv[1], "subtract") == 0)
    {
            plik1= fopen(argv[2],"r");
            plik2= fopen(argv[3],"r");
            wczytaj(plik1,&m1);
            wczytaj(plik2,&m2);
            if((m1.wiersze != m2.wiersze)|| (m1.kolumny != m2.kolumny))
            printf("Nie można odjąć tych macierzy\n");
            else
            {
                subtract(m1,m2,&wynikowa);
                if(argc>4)
                {
                    plik3= fopen(argv[4],"w+");
                    wypisztxt(plik3,wynikowa);
                    fclose(plik3);
                }
                else
                wypisz(wynikowa);
            }   
            fclose(plik1);
            fclose(plik2);
    }
            else if(strcmp( argv[1], "prod") == 0)
        {
            plik1= fopen(argv[2],"r");
            plik2= fopen(argv[3],"r");
            wczytaj(plik1,&m1);
            wczytaj(plik2,&m2);
            if((m1.kolumny != m2.wiersze))
            printf("Nie można wymnożyć tych macierzy\n");
            else
            {
                prod(m1,m2,&wynikowa);
                if(argc>4)
                {
                    plik3= fopen(argv[4],"w+");
                    wypisztxt(plik3,wynikowa);
                    fclose(plik3);
                }
                else
                wypisz(wynikowa);
            }   
            fclose(plik1);
            fclose(plik2);
        }       
            else if(strcmp( argv[1], "multiply") == 0) 
        {
            plik1= fopen(argv[2],"r");
            wczytaj(plik1,&m1);
            float a=atof(argv[3]);
            multiply(m1,a,&wynikowa);
            if(argc>4)
            {
                plik3= fopen(argv[4],"w+");
                wypisztxt(plik3,wynikowa);
                fclose(plik3);
            }
            else
            wypisz(wynikowa);
            fclose(plik1);

        }

         else if(strcmp( argv[1], "norm") == 0) 
        {
            
            plik1= fopen(argv[2],"r");
            wczytaj(plik1,&m1);
            if(argc>3)
            {
                plik3= fopen(argv[3],"w+");
                fprintf(plik3,"%d\n%d\n%.2f",1,1,norm(m1));
            }
            else
            printf("[ %.2f ]\n",norm(m1));
            fclose(plik1);

        }
    

    return 0;
}
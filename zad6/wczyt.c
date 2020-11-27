#include "wczyt.h"


struct macierz* wczytaj(char *fnazwa) 
{   
    FILE *fin;
    int i,j;
    struct macierz *m;
    fin=fopen(fnazwa,"r");
    m = (struct macierz*) malloc(sizeof(struct macierz));
    fscanf(fin, "%d%d", &m->wiersze,&m->kolumny);
    

    m->tab = (float**) malloc(sizeof(float*) * m->wiersze);
    for (i=0;i<m->wiersze;i++) {
        m->tab[i] = (float*) malloc(sizeof(float) * m->kolumny);
        for (j=0;j< m->kolumny; j++)
            m->tab[i][j] = j+1+i;
    }
    

    for (int i=0; i < m->wiersze; i++) {
        for (int j=0; j < m->kolumny; j++) {
            fscanf(fin, "%f", &m->tab[i][j]);
        }
    }
    fclose(fin);

    return m;
}

void wypisz(struct macierz m) 
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

void wypisztxt(char *fnazwa,struct macierz m) 
{
    FILE *fin;
    fin=fopen(fnazwa,"w+");
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
    fclose(fin);
}

void zwolnij(struct macierz *m)
{
    int i;
     for (i=0;i<m->wiersze;i++) 
        free( m->tab[i] );
    free(m->tab);
    free(m);
}
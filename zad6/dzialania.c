#include "dzialania.h"

struct macierz* sum(struct macierz m, struct macierz n)
{   
    int i,j;
    struct macierz *M;
    M= (struct macierz*) malloc(sizeof(struct macierz));
    M->wiersze=m.wiersze;
    M->kolumny=m.kolumny;
    M->tab = (float**) malloc(sizeof(float*) * M->wiersze);
    for (i=0;i<M->wiersze;i++) {
        M->tab[i] = (float*) malloc(sizeof(float) * M->kolumny);
        for (j=0;j< M->kolumny; j++)
            M->tab[i][j] = j+1+i;
    }
    
    for(int i=0; i < m.wiersze; i++)
        for(int j=0; j < m.kolumny; j++)
            M->tab[i][j] = m.tab[i][j] + n.tab[i][j];
            
         
    return M;
}

struct macierz* subtract(struct macierz m, struct macierz n)
{   
    int i,j;
    struct macierz *M;
    M= (struct macierz*) malloc(sizeof(struct macierz));
    M->wiersze=m.wiersze;
    M->kolumny=m.kolumny;
    M->tab = (float**) malloc(sizeof(float*) * M->wiersze);
    for (i=0;i<M->wiersze;i++) {
        M->tab[i] = (float*) malloc(sizeof(float) * M->kolumny);
        for (j=0;j< M->kolumny; j++)
            M->tab[i][j] = j+1+i;
    }
    
    for(int i=0; i < m.wiersze; i++)
        for(int j=0; j < m.kolumny; j++)
            M->tab[i][j] = m.tab[i][j] - n.tab[i][j];
            
         
    return M;
}

struct macierz* multiply(struct macierz m, float a) 
{   
    int i,j;
    struct macierz *M;
    M= (struct macierz*) malloc(sizeof(struct macierz));
    M->wiersze=m.wiersze;
    M->kolumny=m.kolumny;
    M->tab = (float**) malloc(sizeof(float*) * M->wiersze);
    for (i=0;i<M->wiersze;i++) {
        M->tab[i] = (float*) malloc(sizeof(float) * M->kolumny);
        for (j=0;j< M->kolumny; j++)
            M->tab[i][j] = j+1+i;
    }
    for (int i=0; i < m.wiersze; i++) 
    {
        for (int j=0; j < m.kolumny; j++) 
        {
            M->tab[i][j]= a*m.tab[i][j];
        }
    }
    return M;
}

struct macierz* prod(struct macierz m, struct macierz n)
{   
    int i,j;
    struct macierz *M;
    M= (struct macierz*) malloc(sizeof(struct macierz));
    M->wiersze=m.wiersze;
    M->kolumny=n.kolumny;
    M->tab = (float**) malloc(sizeof(float*) * M->wiersze);
    for (i=0;i<M->wiersze;i++) {
        M->tab[i] = (float*) malloc(sizeof(float) * M->kolumny);
        for (j=0;j< M->kolumny; j++)
            M->tab[i][j] = j+1+i;
    }
    float sum=0;
    for(int i=0; i < m.wiersze; i++)
    {    for(int j=0; j < n.kolumny; j++)
        {   
            for(int k=0; k < m.kolumny; k++)
            {sum+= m.tab[i][k] * n.tab[k][j];
            
            }
            M->tab[i][j]=sum;
            sum=0;
        }
    }
    return M;
}

float norm(struct macierz m ) 
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

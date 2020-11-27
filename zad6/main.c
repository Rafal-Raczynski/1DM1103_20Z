#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dzialania.h"
#include "wczyt.h"



int main(int argc, char *argv[])
{
  struct macierz *m;
  struct macierz *n;
  struct macierz *w;
  
  

    
    FILE * plik3;

    if ( strcmp( argv[1], "sum") == 0 )
    {
        {
            
            m=wczytaj(argv[2]);
            n=wczytaj(argv[3]);
            if((m->wiersze != n->wiersze)|| (m->kolumny != n->kolumny))
            {printf("Nie można dodać tych macierzy\n");
             zwolnij(m);
             zwolnij(n);}
            else
            {
                w=sum(*m,*n);
                if(argc>4)
                {
                    
                    wypisztxt(argv[4],*w);
                    
                }
                else
                wypisz(*w);
                zwolnij(m);
                zwolnij(n);
                zwolnij(w);
            }   
            
        }    
    }   else if(strcmp( argv[1], "subtract") == 0)
    {
            
            
            m=wczytaj(argv[2]);
            n=wczytaj(argv[3]);
            if((m->wiersze != n->wiersze)|| (m->kolumny != n->kolumny))
            {printf("Nie można odjąć tych macierzy\n");
            zwolnij(m);
              zwolnij(n);}
            else
            {
                w=subtract(*m,*n);
                if(argc>4)
                {
                    wypisztxt(argv[4],*w);
                    
                    
                }
                else
                wypisz(*w);
                zwolnij(m);
                zwolnij(n);
                zwolnij(w);
            }  
            
            
            
    }
            else if(strcmp( argv[1], "prod") == 0)
        {
            m=wczytaj(argv[2]);
            n=wczytaj(argv[3]);
            
            if((m->kolumny != n->wiersze))
            {printf("Nie można wymnożyć tych macierzy\n");
            zwolnij(m);
            zwolnij(n);
            }
            else
            {
                w=prod(*m,*n);
                if(argc>4)
                {
                    
                    wypisztxt(argv[4],*w);
                    
                }
                else
                wypisz(*w);
                zwolnij(m);
                zwolnij(n);
                zwolnij(w);
            
            }   
            
            
        }       
            else if(strcmp( argv[1], "multiply") == 0) 
        {
            
            m=wczytaj(argv[2]);
            float a=atof(argv[3]);
            w=multiply(*m,a);
            if(argc>4)
            {
                wypisztxt(argv[4],*w);
                
                
            }
            else
            wypisz(*w);
            zwolnij(m);
            
            zwolnij(w);
            

        }

         else if(strcmp( argv[1], "norm") == 0) 
        {
            
            m=wczytaj(argv[2]);
            if(argc>3)
            {
                plik3= fopen(argv[3],"w+");
                fprintf(plik3,"%d\n%d\n%.2f",1,1,norm(*m));
            }
            else
            printf("[ %.2f ]\n",norm(*m));
            zwolnij(m);
            

            
            

        }
    return 0;

}
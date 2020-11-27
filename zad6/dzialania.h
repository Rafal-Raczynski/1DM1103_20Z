#ifndef _DZIEKANAT_H
#define _DZIEKANAT_H

#include "wczyt.h"

struct macierz* sum(struct macierz m, struct macierz n);
struct macierz* subtract(struct macierz m, struct macierz n);
struct macierz* multiply(struct macierz m, float a);
struct macierz* prod(struct macierz m, struct macierz n);
float norm(struct macierz m );

#endif
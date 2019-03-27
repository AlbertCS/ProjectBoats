#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "funcions.h"
#include "tipus.h"
#define MAXP 30
#define MAXR 25
#define DIMAX 10


int main()
{

    record r[MAXR];
    int opcio,dim,numjug,ndades,totaltirs,sumatirs;
    char j1_v[DIMAX][DIMAX],j2_v[DIMAX][DIMAX],j1_ll[DIMAX][DIMAX],j2_ll[DIMAX][DIMAX];
    printf("\n");
    printf("||    ||    ______                         ____       ||\n||    ||   ||_____|  ||        ||        ||    ||     ||\n||    ||   ||        ||        ||        ||    ||     ||\n||----||   ||-----   ||        ||        ||    ||     ||\n||    ||   ||-----   ||        ||        ||    ||\n||    ||   ||-----   ||        ||        ||    ||\n||    ||   ||_____   ||_____   ||_____   ||    ||\n||    ||   ||_____|  ||_____|  ||_____|    ----       ||   ");
    printf("\n\n");
    system("pause");
    totaltirs=0;sumatirs=0;
    menu_inicial(&opcio,&ndades,r);
    if(opcio!=6)
    {
        menu_normal(&opcio,j1_v,j2_v,j1_ll,j2_ll,&dim,&numjug,&ndades,r,&totaltirs,&sumatirs);
    }
    else
    {
        printf("\nFins aviat.\n");
        system("pause");
    }

    return 0;

}

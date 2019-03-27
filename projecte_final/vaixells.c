#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "tipus.h"
#include "funcions.h"
#define MAXP 30
#define MAXR 25
#define DIMAX 10


void clean_board_v(char t[][DIMAX], int dim) /*Redimsio del taulell i neteja*/
{
    int i,j;
    for(i=0;i<DIMAX;i++)
    {
        for(j=0;j<DIMAX;j++)
        {
            if((j<dim)&(i<dim))
            {
                    t[i][j]='.';
            }
            else
            {
                t[i][j]='a';
            }
        }
    }
}

void clean_board_ll(char t[][DIMAX], int dim)   /*Redimsio del taulell i neteja*/
{
    int i,j;
    for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        {
            t[i][j]='?';
        }
    }
}
void rodejar(int f,int c, char t[][DIMAX])  /*Rodejar vaixells amb aigua*/
{
    switch(f)
    {
        case (DIMAX-1):
            switch(c)
            {
                case (DIMAX-1):
                    if((t[f-1][c-1]!='@')&(t[f-1][c-1]!='a'))
                        {t[f-1][c-1]='a';}
                    if((t[f-1][c]!='@')&(t[f-1][c]!='a'))
                        {t[f-1][c]='a';}
                    if((t[f][c-1]!='@')&(t[f][c-1]!='a'))
                        {t[f][c-1]='a';}
                    break;
                case 0:
                    if((t[f-1][c+1]!='@')&(t[f-1][c+1]!='a'))
                        {t[f-1][c+1]='a';}
                    if((t[f-1][c]!='@')&(t[f-1][c]!='a'))
                        {t[f-1][c]='a';}
                    if((t[f][c+1]!='@')&(t[f][c+1]!='a'))
                        {t[f][c+1]='a';}
                    break;
                default:
                    if((t[f-1][c+1]!='@')&(t[f-1][c+1]!='a'))
                        {t[f-1][c+1]='a';}
                    if((t[f-1][c-1]!='@')&(t[f-1][c-1]!='a'))
                        {t[f-1][c-1]='a';}
                    if((t[f-1][c]!='@')&(t[f-1][c]!='a'))
                        {t[f-1][c]='a';}
                    if((t[f][c+1]!='@')&(t[f][c+1]!='a'))
                        {t[f][c+1]='a';}
                    if((t[f][c-1]!='@')&(t[f][c-1]!='a'))
                        {t[f][c-1]='a';}
                    break;
            }
            break;
        case 0:
            switch(c)
            {
                case (DIMAX-1):
                    if((t[f+1][c-1]!='@')&(t[f+1][c-1]!='a'))
                        {t[f+1][c-1]='a';}
                    if((t[f+1][c]!='@')&(t[f+1][c]!='a'))
                        {t[f+1][c]='a';}
                    if((t[f][c-1]!='@')&(t[f][c-1]!='a'))
                        {t[f][c-1]='a';}
                    break;
                case 0:
                    if((t[f+1][c+1]!='@')&(t[f+1][c+1]!='a'))
                        {t[f+1][c+1]='a';}
                    if((t[f+1][c]!='@')&(t[f+1][c]!='a'))
                        {t[f+1][c]='a';}
                    if((t[f][c+1]!='@')&(t[f][c+1]!='a'))
                        {t[f][c+1]='a';}
                    break;
                default:
                    if((t[f+1][c+1]!='@')&(t[f+1][c+1]!='a'))
                        {t[f+1][c+1]='a';}
                    if((t[f+1][c-1]!='@')&(t[f+1][c-1]!='a'))
                        {t[f+1][c-1]='a';}
                    if((t[f+1][c]!='@')&(t[f+1][c]!='a'))
                        {t[f+1][c]='a';}
                    if((t[f][c+1]!='@')&(t[f][c+1]!='a'))
                        {t[f][c+1]='a';}
                    if((t[f][c-1]!='@')&(t[f][c-1]!='a'))
                        {t[f][c-1]='a';}
                    break;
            }
            break;
        default:
            switch(c)
            {
                case (DIMAX-1):
                    if((t[f-1][c-1]!='@')&(t[f-1][c-1]!='a'))
                        {t[f-1][c-1]='a';}
                    if((t[f-1][c]!='@')&(t[f-1][c]!='a'))
                        {t[f-1][c]='a';}
                    if((t[f][c-1]!='@')&(t[f][c-1]!='a'))
                        {t[f][c-1]='a';}
                    if((t[f+1][c-1]!='@')&(t[f+1][c-1]!='a'))
                        {t[f+1][c-1]='a';}
                    if((t[f+1][c]!='@')&(t[f+1][c]!='a'))
                        {t[f+1][c]='a';}
                    break;
                case 0:
                    if((t[f-1][c]!='@')&(t[f-1][c]!='a'))
                        {t[f-1][c]='a';}
                    if((t[f-1][c+1]!='@')&(t[f-1][c+1]!='a'))
                        {t[f-1][c+1]='a';}
                    if((t[f][c+1]!='@')&(t[f][c+1]!='a'))
                        {t[f][c+1]='a';}
                    if((t[f+1][c]!='@')&(t[f+1][c]!='a'))
                        {t[f+1][c]='a';}
                    if((t[f+1][c+1]!='@')&(t[f+1][c+1]!='a'))
                        {t[f+1][c+1]='a';}
                    break;
                default:
                    if((t[f-1][c-1]!='@')&(t[f-1][c-1]!='a'))
                        {t[f-1][c-1]='a';}
                    if((t[f-1][c]!='@')&(t[f-1][c]!='a'))
                        {t[f-1][c]='a';}
                    if((t[f-1][c+1]!='@')&(t[f-1][c+1]!='a'))
                        {t[f-1][c+1]='a';}
                    if((t[f][c-1]!='@')&(t[f][c-1]!='a'))
                        {t[f][c-1]='a';}
                    if((t[f][c+1]!='@')&(t[f][c+1]!='a'))
                        {t[f][c+1]='a';}
                    if((t[f+1][c-1]!='@')&(t[f+1][c-1]!='a'))
                        {t[f+1][c-1]='a';}
                    if((t[f+1][c]!='@')&(t[f+1][c]!='a'))
                        {t[f+1][c]='a';}
                    if((t[f+1][c+1]!='@')&(t[f+1][c+1]!='a'))
                        {t[f+1][c+1]='a';}
                    break;
                }
            break;
    }
}

void inicia_taulell(char t[][DIMAX], int dim)  /*Col·locacio vaixells automatic*/
{
    int w,x,j,i,limit,f,c,vh,kk;
    limit=0;x=0;
    srand(time(NULL));
    while(x!=1)
    {
        kk=0;i=0;
        /* portaavions*/
        while(i<1)
        {
            f=limit+(rand()%(dim-limit+1));c=dim-(rand()%(dim-limit+1));vh=(rand()%2);
            if(vh==0)
            {
                if(c>(dim-4)){c=c-4;}
                if((t[f][c]!='@')&(t[f][c]!='a')&(t[f][c+1]!='@')&(t[f][c+1]!='a')&(t[f][c+2]!='@')&(t[f][c+2]!='a')&(t[f][c+3]!='@')&(t[f][c+3]!='a'))
                {
                    t[f][c]='@';t[f][c+1]='@';t[f][c+2]='@';t[f][c+3]='@';
                    rodejar(f,c,t);rodejar(f,(c+1),t);rodejar(f,(c+2),t);rodejar(f,(c+3),t);
                    i++;
                }
            }
            else
            {
                if(f>(dim-4)){f=f-4;}
                if((t[f][c]!='@')&(t[f][c]!='a')&(t[f+1][c]!='@')&(t[f+1][c]!='a')&(t[f+2][c]!='@')&(t[f+2][c]!='a')&(t[f+3][c]!='@')&(t[f+3][c]!='a'))
                {
                    t[f][c]='@';t[f+1][c]='@';t[f+2][c]='@';t[f+3][c]='@';
                    rodejar(f,c,t);rodejar((f+1),c,t);rodejar((f+2),c,t);rodejar((f+3),c,t);
                    i++;
                }
            }
        }i=0;
        /* destructors*/
        while(i<2)
        {
            f=limit+(rand()%(dim-limit+1));c=dim-(rand()%(dim-limit+1));vh=(rand()%2);
            if(vh==0)
            {
                if(c>(dim-3)){c=c-3;}
                if((t[f][c]!='@')&(t[f][c]!='a')&(t[f][c+1]!='@')&(t[f][c+1]!='a')&(t[f][c+2]!='@')&(t[f][c+2]!='a'))
                {
                    t[f][c]='@';t[f][c+1]='@';t[f][c+2]='@';
                    rodejar(f,c,t);rodejar(f,(c+1),t);rodejar(f,(c+2),t);
                    i++;
                }
            }
            else
            {
                if(f>(dim-3)){f=f-3;}
                if((t[f][c]!='@')&(t[f][c]!='a')&(t[f+1][c]!='@')&(t[f+1][c]!='a')&(t[f+2][c]!='@')&(t[f+2][c]!='a'))
                {
                    t[f][c]='@';t[f+1][c]='@';t[f+2][c]='@';
                    rodejar(f,c,t);rodejar((f+1),c,t);rodejar((f+2),c,t);
                    i++;
                }
            }
        }i=0;
        /* dragamines*/
        while(i<3)
        {
            f=limit+(rand()%(dim-limit+1));c=dim-(rand()%(dim-limit+1));vh=(rand()%2);
            if(vh==0)
            {
                if(c>(dim-2)){c=c-2;}
                if((t[f][c]!='@')&(t[f][c]!='a')&(t[f][c+1]!='@')&(t[f][c+1]!='a'))
                {
                    t[f][c]='@';t[f][c+1]='@';
                    rodejar(f,c,t);rodejar(f,(c+1),t);
                    i++;
                }
            }
            else
            {
                if(f>(dim-2)){f=f-2;}
                if((t[f][c]!='@')&(t[f][c]!='a')&(t[f+1][c]!='@')&(t[f+1][c]!='a'))
                {
                    t[f][c]='@';t[f+1][c]='@';
                    rodejar(f,c,t);rodejar((f+1),c,t);
                    i++;
                }
            }
        }i=0;
        /* submarins*/
        w=0;
        while((w<dim)&(i<4))
        {
            j=0;
            while((j<dim)&(i<4))
            {
                if(t[w][j]=='.'){t[w][j]='@';i++;rodejar(w,j,t);}
                j++;
            }w++;
        }
        for(i=0;i<dim;i++)
        {
            for(j=0;j<dim;j++)
            {
                if(t[i][j]=='a'){t[i][j]='.';}
                if(t[i][j]=='@'){kk++;}
            }
        }
        if(kk==20){x=1;}
        else{clean_board_v(t,dim);}
    }
}

void inicia_elmeu_taulell(char t[][DIMAX], int dim)        /*Posicionament vaixells manuak*/
{
    int i,j,w,x,f,c,vh,kk,ok,disponible;
    char carac,c1,llegir[MAXP];
    x=0;disponible=0;w=0;
    while(x!=1)
    {
        kk=0;
        /* portaavions*/
        while(w<1)
        {
            system("cls");ok=0;
            printf("\n \t");for(i=0;i<dim;i++)
                {printf("%d ",i+1);}
            carac=65;
            for(i=0;i<dim;i++)
            {
                printf("\n%c\t", carac);
                for(j=0;j<dim;j++)
                {
                    printf("%c ",t[i][j]);
                }carac++;
            }i=0;j=0;
            printf("\n\nTaulell on es posicionen els vaixells.\n");
            printf("\nPosiciona el portaavions (ocupa 4 caselles).\n");
            printf("\nIntrodueix 1(per vertical), o 0(per horitzontal). En cas de que seleccionis un nombre incorrecte es posicionara verticalment per defecte.\n");
            fflush(stdin);scanf("%d", &vh);
            printf("\nEspecifica les coordenades on vols que comenci el vaixell, tenint en compte que es colocara cap a baix(si es vol vertical) o cap a la dreta(si es vol horitzontal),exemple(A1),recorda que la lletra va en mayuscula: \n");
            fflush(stdin);scanf("%c",&c1);
            while((c1!='\n')&(j<MAXP))
            {
                llegir[j]=c1;
                j++;
                scanf("%c",&c1);
            }
            carac=llegir[0];
            if(dim<10)
            {
                c=llegir[1]-48;
            }
            else
            {
                if((llegir[1]==49)&(llegir[2]==48)){j=2;c=10;}
                else{c=llegir[1]-48;}
            }
            f=carac-65;c--;
            if(vh==0)
            {
                if(c<(dim-4)){kk++;}
                if((t[f][c]!='@')&(t[f][c]!='a')&(t[f][c+1]!='@')&(t[f][c+1]!='a')&(t[f][c+2]!='@')&(t[f][c+2]!='a')&(t[f][c+3]!='@')&(t[f][c+3]!='a'))
                {
                    t[f][c]='@';t[f][c+1]='@';t[f][c+2]='@';t[f][c+3]='@';
                    rodejar(f,c,t);rodejar(f,(c+1),t);rodejar(f,(c+2),t);rodejar(f,(c+3),t);
                    w++;
                }
                else
                    {
                        system("cls");
                        printf("\n\nError amb les coordenades, prova de nou.\n\n");
                        system("pause");
                    }
            }
            else
            {
                if(f<(dim-4)){kk++;}
                if((ok==1)&(t[f][c]!='@')&(t[f][c]!='a')&(t[f+1][c]!='@')&(t[f+1][c]!='a')&(t[f+2][c]!='@')&(t[f+2][c]!='a')&(t[f+3][c]!='@')&(t[f+3][c]!='a'))
                {
                    t[f][c]='@';t[f+1][c]='@';t[f+2][c]='@';t[f+3][c]='@';
                    rodejar(f,c,t);rodejar((f+1),c,t);rodejar((f+2),c,t);rodejar((f+3),c,t);
                    w++;
                }
                else
                    {
                        system("cls");
                        printf("\n\nError amb les coordenades, prova de nou.\n\n");
                        system("pause");
                    }
            }
        }w=0;
        /* destructors*/
        while(w<2)
        {
            system("cls");kk=0;
            printf("\n \t");
            for(i=0;i<dim;i++){printf("%d ",i+1);}
            carac=65;
            for(i=0;i<dim;i++)
            {
                printf("\n%c\t", carac);
                for(j=0;j<dim;j++)
                {
                    printf("%c ",t[i][j]);
                }carac++;
            }i=0;j=0;
            printf("\n\nS'ha posicionat el portaavions correctament, i s'han marcat les caselles on no es pot colocar un altre vaixell amb 'a'.\n");
            printf("\nPosiciona els destructors (que ocupa 3 caselles cadascun).\n");
            printf("\nIntrodueix 1(per vertical), o 0(per horitzontal). En cas de que seleccionis un nombre incorrecte es posicionara verticalment per defecte.\n");
            fflush(stdin);scanf("%d", &vh);
            printf("\nEspecifica les coordenades on vols que comenci el vaixell, tenint en compte que es colocara cap a baix(si es vertical) o cap a la dreta(si es horitzontal),exemple(A1),recorda que la lletra va en mayuscula: \n");
            fflush(stdin);scanf("%c",&c1);
            while((c1!='\n')&(j<MAXP))
            {
                llegir[j]=c1;
                j++;
                scanf("%c",&c1);
            }
            carac=llegir[0];
            if(dim<10)
            {
                c=llegir[1]-48;
            }
            else
            {
                if((llegir[1]==49)&(llegir[2]==48)){j=2;c=10;}
                else{c=llegir[1]-48;}
            }
            f=carac-65;c--;
            if(vh==0)
            {
                if(c<(dim-3)){ok++;}
                if((ok==1)&(t[f][c]!='@')&(t[f][c]!='a')&(t[f][c+1]!='@')&(t[f][c+1]!='a')&(t[f][c+2]!='@')&(t[f][c+2]!='a'))
                {
                    t[f][c]='@';t[f][c+1]='@';t[f][c+2]='@';
                    rodejar(f,c,t);rodejar(f,(c+1),t);rodejar(f,(c+2),t);
                    w++;
                }
                else
                    {
                        system("cls");
                        printf("\n\nError amb les coordenades, prova de nou.\n\n");
                        system("pause");
                    }
            }
            else
            {
                if(f<(dim-3)){ok++;}
                if((ok==1)&(t[f][c]!='@')&(t[f][c]!='a')&(t[f+1][c]!='@')&(t[f+1][c]!='a')&(t[f+2][c]!='@')&(t[f+2][c]!='a'))
                {
                    t[f][c]='@';t[f+1][c]='@';t[f+2][c]='@';
                    rodejar(f,c,t);rodejar((f+1),c,t);rodejar((f+2),c,t);
                    w++;
                }
                else
                    {
                        system("cls");
                        printf("\n\nError amb les coordenades, prova de nou.\n\n");
                        system("pause");
                    }
            }
        }w=0;
        /* dragamines*/
        while(w<3)
        {
            system("cls");ok=0;
            printf("\n \t");for(i=0;i<dim;i++){printf("%d ",i+1);}
            carac=65;
            for(i=0;i<dim;i++)
            {
                printf("\n%c\t", carac);
                for(j=0;j<dim;j++)
                {
                    printf("%c ",t[i][j]);
                }carac++;
            }i=0;j=0;
            printf("\n\nS'ha posicionat els 2 destructors correctament, i s'han marcat les caselles on no es pot colocar altre vaixell amb 'a'.\n");
            printf("\nPosiciona els dragamines (que ocupen 2 caselles cadascun).\n");
            printf("\nIntrodueix 1(si per vertical), o 0(si per horitzontal). En cas de que seleccionis un nombre incorrecte es posicionara verticalment per defecte.\n");
            fflush(stdin);scanf("%d", &vh);
            printf("\nEspecifica les coordenades on vols que comenci el vaixell, tenint en compte que es colocara cap a baix(si es vertical) o cap a la dreta(si es horitzontal),exemple(A1),recorda que la lletra va en mayuscula: \n");
            fflush(stdin);scanf("%c",&c1);
            while((c1!='\n')&(j<MAXP))
            {
                llegir[j]=c1;
                j++;
                scanf("%c",&c1);
            }
            carac=llegir[0];
            if(dim<10)
            {
                c=llegir[1]-48;
            }
            else
            {
                if((llegir[1]==49)&(llegir[2]==48)){j=2;c=10;}
                else{c=llegir[1]-48;}
            }
            f=carac-65;c--;
            if(vh==0)
            {
                if(c<(dim-2)){ok++;}
                if((ok==1)&(t[f][c]!='@')&(t[f][c]!='a')&(t[f][c+1]!='@')&(t[f][c+1]!='a'))
                {
                    t[f][c]='@';t[f][c+1]='@';
                    rodejar(f,c,t);rodejar(f,(c+1),t);
                    w++;
                }
                else
                    {
                        system("cls");
                        printf("\n\nError amb les coordenades, prova de nou.\n\n");
                        system("pause");
                    }
            }
            else
            {
                if(f<(dim-2)){ok++;}
                if((ok==1)&(t[f][c]!='@')&(t[f][c]!='a')&(t[f+1][c]!='@')&(t[f+1][c]!='a'))
                {
                    t[f][c]='@';t[f+1][c]='@';
                    rodejar(f,c,t);rodejar((f+1),c,t);
                    w++;
                }
                else
                    {
                        system("cls");
                        printf("\n\nError amb les coordenades, prova de nou.\n\n");
                        system("pause");
                    }
            }
        }w=0;disponible=0;
        /* submarins*/
        while(w<4)
        {
            system("cls");ok=0;
            printf("\n \t");for(i=0;i<dim;i++){printf("%d ",i+1);}
            carac=65;
            for(i=0;i<dim;i++)
            {
                printf("\n%c\t", carac);
                for(j=0;j<dim;j++)
                {
                    printf("%c ",t[i][j]);
                    if((t[i][j]!='a')&(t[i][j]!='@')){disponible++;}
                }carac++;
            }i=0;j=0;
            if(disponible!=0)
            {
                printf("\n\nS'han posicionat els 3 dragamines correctament, i a mes s'han marcat les caselles on no es pot colocar un altre vaixell amb 'a'.\n");
                printf("\nAra cal posicionar els submarins (que ocupen 1 casella cadascun).\n");
                printf("\nEspecifica les coordenades on vols que comenci el vaixell, tenint en compte que es colocara cap a baix(si es vol vertical) o cap a la dreta(si es vol horitzontal),exemple(A1),recorda que la lletra va en mayuscula: \n");
                fflush(stdin);scanf("%c",&c1);
                while((c1!='\n')&(j<MAXP))
                {
                    llegir[j]=c1;
                    j++;
                    scanf("%c",&c1);
                }
                carac=llegir[0];
                if(dim<10)
                {
                    c=llegir[1]-48;
                }
                else
                {
                    if((llegir[1]==49)&(llegir[2]==48)){j=2;c=10;}
                    else{c=llegir[1]-48;}
                }
                f=carac-65;c--;
                if((c<dim)&(f<dim)){ok++;}
                if((ok==1)&(t[f][c]!='@')&(t[f][c]!='a'))
                {
                    t[f][c]='@';
                    rodejar(f,c,t);
                    w++;
                }
                else
                    {
                        system("cls");
                        printf("\n\nError amb les coordenades, prova de nou.\n\n");
                        system("pause");
                    }
            }
            else{w=4;}
        }
        for(i=0;i<dim;i++)
        {
            for(j=0;j<dim;j++)
            {
                if(t[i][j]=='a'){t[i][j]='.';}
                if(t[i][j]=='@'){kk++;}
            }
        }if(kk==20){x=1;}
        else
            {
                system("cls");
                printf("\nPosicionament dels vaixells incorrecte, tornau a intentar de nou\n");
                system("pause");
                clean_board_v(t,dim);
            }
    }
    system("cls");
    printf("\n \t");for(i=0;i<dim;i++){printf("%d ",i+1);}
    carac=65;
    for(i=0;i<dim;i++)
    {
        printf("\n%c\t", carac);
        for(j=0;j<dim;j++)
        {
            printf("%c ",t[i][j]);
        }carac++;
    }
    printf("\n\nAquest es el teu taulell de vaixells.\n\n");
    system("pause");
}

int dispara(int f,int c,char v[][DIMAX],char ll[][DIMAX])
{
    int resultatTirs;
    switch(v[f][c])
    {
        case '@': v[f][c]='X';ll[f][c]='@';ll[f+1][c+1]='.';ll[f+1][c-1]='.';ll[f-1][c+1]='.';ll[f-1][c-1]='.';
            if((v[f+1][c]!='@')&(v[f-1][c]!='@')&(v[f][c+1]!='@')&(v[f][c-1]!='@'))
            {
                if(ll[f+1][c]=='?'){ll[f+1][c]='.';}
                if(ll[f-1][c]=='?'){ll[f-1][c]='.';}
                if(ll[f][c+1]=='?'){ll[f][c+1]='.';}
                if(ll[f][c-1]=='?'){ll[f][c-1]='.';}
                resultatTirs=3;
            }
            else{resultatTirs=2;}
            break;
        case '.': v[f][c]='-';ll[f][c]='.';resultatTirs=1;
            break;
        default:resultatTirs=0;
            break;
    }
    return resultatTirs;
}

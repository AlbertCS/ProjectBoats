/*----------------------------------------------------------------
|	Autor:Albert Cañellas
|   e-mail: albert.cañellas@estudiants.urv.cat
|	Data: Gener 2016                 Versio: 6.0
|-----------------------------------------------------------------|
|	Nom projecte: Projecte_final
|	Nom: funcions.c
|   Descripcio del Programa:   Les funcions.
| ----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "tipus.h"
#include "vaixells.h"
#define MAXP 30
#define MAXR 25
#define DIMAX 10




void dim_taulell(int *dim)         /*Coneixer la dim del taulell*/
{
    printf("\nIntrodueix la dim del taulell 8 (per 8x8), 9 (per 9x9) o 10 (per 10x10): \t");
    while ((*dim!=8)&(*dim!=9)&(*dim!=10))
    {
        fflush(stdin);scanf("%d", &*dim);
        switch (*dim)
        {
            case 8:system("cls");
                break;
            case 9:system("cls");
                break;
            case 10:system("cls");
                break;
            default:system("cls");
                printf("\nHas selecionat una dim de taulell incorrecte. Selecciona 8(8x8), 9 (9x9) o 10(10x10): \t");
                break;
        }
    }
}
void mode_joc(int *numjug)     /*Num jugadors*/
{
    printf("\nSelecciona el nombre de jugadors:\n\n");
    printf("Cap jugador(0).\n");
    printf("Un jugador(1).\n");
    printf("Dos jugadors(2).\n");
    while ((*numjug!=0)&(*numjug!=1)&(*numjug!=2))
    {
        fflush(stdin);scanf("%d", &*numjug);
        switch (*numjug)
        {
            case 0:system("cls");
                break;
            case 1:system("cls");
                break;
            case 2:system("cls");
                break;
            default:system("cls");
                printf("\nHas selecionat un nombre de jugadors erroni. Prova amb  1, 2 o 0.\n");
                break;
        }
    }
}


void jugar(int *f,int *c,char v[][DIMAX],char ll[][DIMAX],int dim,int *conta)
{
    int i,j,limit,tretB;
    char carac;
    limit=0;tretB=0;
    for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        {
            if(v[i][j]=='@')
                {*conta=*conta+1;}
            if((ll[i][j]=='@')&(ll[i][j+1]=='?')&(j!=dim))
                {tretB++;*f=i;*c=j+1;}
            if((ll[i][j]=='@')&(ll[i][j-1]=='?')&(j!=0))
                {tretB++;*f=i;*c=j-1;}
            if((ll[i][j]=='@')&(ll[i+1][j]=='?')&(i!=dim))
                {tretB++;*f=i+1;*c=j;}
            if((ll[i][j]=='@')&(ll[i-1][j]=='?')&(i!=0))
                {tretB++;*f=i-1;*c=j;}
        }
    }i=0;
    if(*conta!=0)
    {
        if(tretB==0)
        {
            while(i<1)
            {
                *f=limit+(rand()%(dim-limit+1));
                *c=dim-(rand()%(dim-limit+1));
                if((ll[*f][*c]=='?')){i++;}
            }
        }carac=65+*f;
        printf("\nEl llansament se realitzara a les coordenades %c%d.\n",carac,*c+1);
    }
    else
    {
        for(i=0;i<dim;i++)
        {
            for(j=0;j<dim;j++)
            {
                if(ll[i][j]=='?'){ll[i][j]='.';}
            }
        }
    }
}
void jugada_nova(int *f,int *c,char v[][DIMAX],char ll[][DIMAX],int dim,int *conta)
{
    int i,j;
    char carac,llegir[MAXP],c1;
    for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        {
            if(v[i][j]=='@'){*conta=*conta+1;}
        }
    }i=0;
    if(*conta!=0)
    {
        while(i<1)
        {
            j=0;c1='\0';
            printf("\nIndica les coordenades on vols realitzar el llanzament,exemple(A1),recorda que la lletra va en mayuscula: \n");
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
                *c=llegir[1]-48;
            }
            else
            {
                if((llegir[1]==49)&(llegir[2]==48)){j=2;*c=10;}
                else{*c=llegir[1]-48;}
            }
            *f=carac-65;*c=(*c)-1;
            if((*f<dim)&(*c<dim)&(j==2)){i++;}
            else{system("cls");printf("\nEl llancament es troba a fora de la dimsio del taulell.\n");}
        }system("cls");
        printf("\nEl llancament s'ha realitzat a les coordenades %c%d.\n",carac,*c+1);
    }
    else
    {
        for(i=0;i<dim;i++)
        {
            for(j=0;j<dim;j++)
            {
                if(ll[i][j]=='?'){ll[i][j]='.';}
            }
        }
    }
}

int calcular_puntuacio(char t[][DIMAX],int dim,int totaltirs,int resultatTirs,int *sumatirs)
{
    int puntuacio;
    *sumatirs=*sumatirs+resultatTirs-1;
    puntuacio=100*(dim*1.000/totaltirs*1.000)*(*sumatirs);
    return puntuacio;
}
int recupera_records(record r[MAXR])
{
    int ndades,i,j;
    char c;
    FILE *f;
    ndades=0;i=0;j=0;
    system("cls");
    f=fopen("records.txt", "r+");
    if(f==NULL)
    {
        printf("\nNo hi ha cap record guardat.\n\n");
        while(j<MAXR)
        {
            r[j].nom[i]='\0';r[j].puntuacio=0;
            j++;
        }
    }
    else
    {
        fscanf(f,"%c",&c);
        while((c!=32)&(i<MAXP))
        {
            r[j].nom[i]=c;
            i++;
            fscanf(f,"%c",&c);
        }r[j].nom[i]='\0';i=0;
        fscanf(f,"%d",&r[j].puntuacio);ndades++;j++;
        while(j<MAXR)
        {
            if(!feof(f))
            {
                c='w';fscanf(f,"%c",&c);fscanf(f,"%c",&c);
                while((c!=32)&(i<MAXP))
                {
                    r[j].nom[i]=c;
                    i++;
                    fscanf(f,"%c",&c);
                }r[j].nom[i]='\0';i=0;
                fscanf(f,"%d",&r[j].puntuacio);
                ndades++;
            }
            else
            {
                r[j].nom[i]='\0';r[j].puntuacio=0;
            }j++;
        }
        fclose(f);
    }
    return ndades;
}
void insercio_ordenada(record r[MAXR],record nou,int ndades)
{
    int i,j,esmesgran;
    record aux;
    i=0;j=0;esmesgran=1;
    while ((esmesgran!=0)&(i<ndades))
    {
        if(r[i].puntuacio>nou.puntuacio){esmesgran=1;i++;}
        else{esmesgran=0;}
    }
    if(esmesgran!=0)
    {
        r[i].puntuacio=nou.puntuacio;
        while(r[i].nom[j]!='\0')
        {
            r[i].nom[j]=nou.nom[j];
            j++;
        }j=0;
    }
    else
    {
        while(i<ndades)
        {
            aux.puntuacio=r[i].puntuacio;
            while(r[i].nom[j]!='\0')
            {
                aux.nom[j]=r[i].nom[j];
                j++;
            }aux.nom[j]='\0';j=0;
            r[i].puntuacio=nou.puntuacio;
            while(nou.nom[j]!='\0')
            {
                r[i].nom[j]=nou.nom[j];
                j++;
            }r[i].nom[j]='\0';j=0;
            nou.puntuacio=aux.puntuacio;
            while(aux.nom[j]!='\0')
            {
                nou.nom[j]=aux.nom[j];
                j++;
            }nou.nom[j]='\0';j=0;
            i++;
        }
    }
}
void emmagatzema_records(record r[MAXR], int ndades)
{
    int i,j;
    FILE *f;
    char c;
    f=fopen("records.txt", "w+");
    c=32;
    for(i=0;i<ndades;i++)
    {
        j=0;
        while((c!='\0')&(j<MAXP))
        {
            c=r[i].nom[j];
            j++;
            if(c!='\0'){fprintf(f,"%c",c);}
        }c=32;
        fprintf(f,"%c",c);
        fprintf(f,"%d",r[i].puntuacio);
        if((i+1)<ndades){fprintf(f,"%c",c);}
    }
    fclose(f);
}
void mostrar_records(int ndades,record r[MAXR])
{
    int i,j;
    if(ndades!=0)
    {
        system("cls");
        printf("\n RECORDS: \n\n");
        printf("\n\tNOM\t\t\t\tRECORD\n");
        for(i=0;i<ndades;i++)
        {
            j=0;
            while(r[i].nom[j]!='\0'){j++;}
            printf("\n%d.\t%s", i+1, r[i].nom);
            if(j<8){printf("\t\t\t\t");}
            else
            {
                if(j<15){printf("\t\t\t");}
                else{printf("\t\t");}
            }
            printf("%d",r[i].puntuacio);
        }
        printf("\n\nTornar al menu.\n\n");
    }
    system("pause");system("cls");
}
void nou_record(int puntuacio)
{
    int i,ndades;
    record r[MAXR],nou;
    char c;
    i=0;
    ndades=recupera_records(r);
    system("cls");
    if(ndades<25){ndades++;}
    if(r[24].puntuacio<puntuacio)
    {
        printf("\nEscriu el nom per a guardar-lo amb aquesta puntuacio(amb menys de 25 caracters):\n");
        fflush(stdin);scanf("%c",&c);
        while((c!='\n')&(i<MAXP))
        {
            nou.nom[i]=c;
            i++;
            scanf("%c",&c);
        }nou.nom[i]='\0';
        nou.puntuacio=puntuacio;
        insercio_ordenada(r,nou,ndades);
        emmagatzema_records(r,ndades);
    }
    else
    {
        system("cls");
        printf("\nEt trobes per sota dels 25 millors records, que es mostraran a continuacio.\n\n");
        system("pause");
    }
    mostrar_records(ndades,r);
}
void jugar_partida(char v1[][DIMAX],char v2[][DIMAX],char ll1[][DIMAX],char ll2[][DIMAX],int dim, int numjug,int *totaltirs, int *sumatirs)
{
    int i,j,w,f,c,conta,partida,puntuacio,resultatTirs,torn;
    char pausa, carac;
    w=1;partida=0;puntuacio=0;torn=2;
    switch (numjug)
    {
        case 0:
            for(i=0;i<dim;i++)
            {
                for(j=0;j<dim;j++)
                {
                    if(ll1[i][j]=='?'){partida++;}
                }
            }
            if(partida!=0)
            {
                while(w!=0)
                {
                    conta=0;system("cls");
                    printf("\n \t");
                    for(i=0;i<dim;i++)
                        {printf("%d ",i+1);}
                    carac=65;
                    for(i=0;i<dim;i++)
                    {
                        printf("\n%c\t", carac);
                        for(j=0;j<dim;j++)
                        {
                            printf("%c ",ll1[i][j]);
                        }carac++;
                    }
                    printf("\n\n \t");
                    for(i=0;i<dim;i++)
                        {printf("%d ",i+1);}
                    carac=65;
                    for(i=0;i<dim;i++)
                    {
                        printf("\n%c\t", carac);
                        for(j=0;j<dim;j++)
                        {
                            printf("%c ",v1[i][j]);
                        }carac++;
                    }
                    printf("\n\nA dalt el taulell de llancaments i a baix el de vaixells.\n");
                    jugar(&f,&c,v1,ll1,dim,&conta);
                    if(conta!=0)
                    {
                        printf("\nPulsa 'p' per a anar al menu o qualsevol altra tecla per a continuar.\n");
                        pausa=getch();
                        if(pausa!='p')
                        {
                            resultatTirs=dispara(f,c,v1,ll1);(*totaltirs)++;
                            puntuacio=calcular_puntuacio(v1,dim,*totaltirs,resultatTirs,&*sumatirs);
                        }
                    }
                    else
                    {
                        system("cls");
                        printf("\n \t");
                        for(i=0;i<dim;i++)
                            {printf("%d ",i+1);}
                        carac=65;
                        for(i=0;i<dim;i++)
                        {
                            printf("\n%c\t", carac);
                            for(j=0;j<dim;j++)
                            {
                                printf("%c ",ll1[i][j]);
                            }carac++;
                        }
                        printf("\n\n \t");
                        for(i=0;i<dim;i++)
                            {printf("%d ",i+1);}
                        carac=65;
                        for(i=0;i<dim;i++)
                        {
                            printf("\n%c\t", carac);
                            for(j=0;j<dim;j++)
                            {
                                printf("%c ",v1[i][j]);
                            }carac++;
                        }
                        printf("\n\nA dalt el taulell de llancaments i a baix el de vaixells.\n");
                        printf("\nPartida acavada.\n");
                        printf("\nI els punts aconseguits son: %d.\n", puntuacio);
                        printf("\n");system("pause");nou_record(puntuacio);
                    }
                    if((pausa=='p')||(pausa=='P')){conta=0;}
                    w=conta;
                }
            }
            else{printf("\nLa partida s'ha acabat, carrega o inicia un altra.\n");printf("\n");
            system("pause");}
            break;
        case 1:
            for(i=0;i<dim;i++)
            {
                for(j=0;j<dim;j++)
                {
                    if(ll1[i][j]=='?'){partida++;}
                }
            }
            if(partida!=0)
            {
                system("cls");
                while(w!=0)
                {
                    conta=0;printf("\n \t");for(i=0;i<dim;i++){printf("%d ",i+1);}
                    carac=65;
                    for(i=0;i<dim;i++)
                    {
                        printf("\n%c\t", carac);
                        for(j=0;j<dim;j++)
                        {
                            printf("%c ",ll1[i][j]);
                        }carac++;
                    }
                    printf("\n\nAquesta es el teu taulell de llancaments.\n\n");
                    jugada_nova(&f,&c,v1,ll1,dim,&conta);
                    if(conta!=0)
                    {
                        resultatTirs=dispara(f,c,v1,ll1);(*totaltirs)++;
                        puntuacio=calcular_puntuacio(v1,dim,*totaltirs,resultatTirs,&*sumatirs);
                        printf("\n \t");
                        for(i=0;i<dim;i++)
                            {printf("%d ",i+1);}
                        carac=65;
                        for(i=0;i<dim;i++)
                        {
                            printf("\n%c\t", carac);
                            for(j=0;j<dim;j++)
                            {
                                printf("%c ",ll1[i][j]);
                            }carac++;
                        }
                        printf("\n\nAquesta es el teu taulell de llancaments.\n");
                        printf("\nPulsa 'p' per a anar al menu o qualsevol altra tecla per a continuar.\n");
                        pausa=getch();system("cls");
                    }
                    else
                    {
                        system("cls");
                        printf("\n \t");
                        for(i=0;i<dim;i++)
                            {printf("%d ",i+1);}
                        carac=65;
                        for(i=0;i<dim;i++)
                        {
                            printf("\n%c\t", carac);
                            for(j=0;j<dim;j++)
                            {
                                printf("%c ",ll1[i][j]);
                            }carac++;
                        }
                        printf("\n\nAquesta es el teu taulell de llancaments\n");
                        printf("\nLa partida ha acavat.\n");
                        printf("\nEls punts aconseguits son: %d.\n", puntuacio);
                        printf("\n");system("pause");nou_record(puntuacio);
                    }
                    if((pausa=='p')||(pausa=='P')){conta=0;}
                    w=conta;
                }
            }
            else{printf("\nLa partida ha finalitzat, carrega o inicia un altra.\n");printf("\n");system("pause");}
            break;
        case 2:
            for(i=0;i<dim;i++)
            {
                for(j=0;j<dim;j++)
                {
                    if(ll1[i][j]=='?'){partida++;}
                    if(v1[i][j]=='@'){partida++;}
                }
            }
            if(partida!=0)
            {
                while(w!=0)
                {
                    conta=0;system("cls");
                    printf("\n \t");
                    for(i=0;i<dim;i++)
                        {printf("%d ",i+1);}
                    carac=65;
                    for(i=0;i<dim;i++)
                    {
                        printf("\n%c\t", carac);
                        for(j=0;j<dim;j++)
                        {
                            printf("%c ",ll1[i][j]);
                        }carac++;
                    }
                    printf("\n\n \t");
                    for(i=0;i<dim;i++)
                        {printf("%d ",i+1);}
                    carac=65;
                    for(i=0;i<dim;i++)
                    {
                        printf("\n%c\t", carac);
                        for(j=0;j<dim;j++)
                        {
                            printf("%c ",v1[i][j]);
                        }carac++;
                    }
                    printf("\n\nA dalt el teu taulell de llancaments i a baix el teu de vaixells.\n");
                    if(torn%2==0)
                    {
                        printf("\nEs el teu torn.\n");jugada_nova(&f,&c,v2,ll1,dim,&conta);
                        if(conta!=0)
                        {
                            resultatTirs=dispara(f,c,v2,ll1);(*totaltirs)++;
                            puntuacio=calcular_puntuacio(v1,dim,*totaltirs,resultatTirs,&*sumatirs);
                            printf("\n\n");system("pause");
                        }
                        else
                        {
                            system("cls");
                            printf("\n \t");for(i=0;i<dim;i++){printf("%d ",i+1);}
                            carac=65;
                            for(i=0;i<dim;i++)
                            {
                                printf("\n%c\t", carac);
                                for(j=0;j<dim;j++)
                                {
                                    printf("%c ",ll1[i][j]);
                                }carac++;
                            }
                            printf("\n\n \t");
                            for(i=0;i<dim;i++)
                                {printf("%d ",i+1);}
                            carac=65;
                            for(i=0;i<dim;i++)
                            {
                                printf("\n%c\t", carac);
                                for(j=0;j<dim;j++)
                                {
                                    printf("%c ",v1[i][j]);
                                }carac++;
                            }
                            printf("\n\nA dalt et trobes el taulell de llancaments i a baix el de vaixells.\n");
                            printf("\nLa partida ha acavat. Has guanyat ENHORABONA!!!!.\n");
                        }
                        if(resultatTirs>1){torn=2;}
                        else{torn++;}
                    }
                    else
                    {
                        printf("\nTorn del Ordinador.\n");jugar(&f,&c,v1,ll2,dim,&conta);
                        if(conta!=0)
                        {
                            resultatTirs=dispara(f,c,v1,ll2);(*totaltirs)++;
                            printf("\nPulsa 'p' per a anar al menu o qualsevol altra tecla per a continuar.\n");
                            pausa=getch();
                        }
                        else
                        {
                            printf("\nLa partida ha acavat. Ha guanyat l'Ordinador.\n");
                            printf("\n");system("pause");
                        }
                        if(resultatTirs>1){torn=3;}
                        else{torn++;}
                    }
                    if(conta==0)
                    {
                        printf("\nEls punts que s'han aconseguit son: %d.\n", puntuacio);
                        printf("\n");system("pause");nou_record(puntuacio);
                    }
                    if((pausa=='p')||(pausa=='P')){conta=0;}
                    w=conta;
                }
            }
            else{printf("\nLa partida ha finalitzat, carrega o inicia una altra.\n");printf("\n");system("pause");}
            break;
        default:
            break;
    }system("cls");
}
void joc_nou(char j1_v[DIMAX][DIMAX],char j2_v[DIMAX][DIMAX],char j1_ll[DIMAX][DIMAX],char j2_ll[DIMAX][DIMAX], int *dim,int *numjug)
{
    int am,i;
    am=0;i=0;*dim=0;*numjug=-1;
    dim_taulell(&*dim);
    clean_board_v(j1_v,*dim);
    clean_board_v(j2_v,*dim);
    clean_board_ll(j1_ll,*dim);
    clean_board_ll(j2_ll,*dim);
    mode_joc(&*numjug);
    switch(*numjug)
    {
        case 0:
            inicia_taulell(j1_v,*dim);
            break;
        case 1:
            inicia_taulell(j1_v,*dim);
            break;
        case 2:
            while(i<1)
            {
                system("cls");
                printf("\nSelecciona (1) per la colocacio automatica dels vaixells o (2) per a colocacio manual.\n");
                fflush(stdin);scanf("%d",&am);
                switch(am)
                {
                    case 1:
                        inicia_taulell(j1_v,*dim);
                        inicia_taulell(j2_v,*dim);
                        i++;
                        break;
                    case 2:
                        inicia_elmeu_taulell(j1_v,*dim);
                        inicia_taulell(j2_v,*dim);
                        i++;
                        break;
                    default:
                        printf("\nOpcio erronia, introdueix una opcio valida.\n\n");system("pause");
                        break;
                }
            }
            break;
        default:
            break;
    }system("cls");
}
void guardar_dades(int dim,int numjug,int totaltirs,int sumatirs)
{
    FILE *dades;
    char t[11],c1;
    int desenes,unitats;
    dades=fopen("dades.bin","wb+");
    if(dim<10)
    {
        if(dim==8){t[0]='8';}
        else{t[0]='9';}
        t[1]='.';t[2]='.';
    }
    else
    {
        t[0]='1';t[1]='0';t[2]='.';
    }
    c1=numjug+48;t[3]=c1;t[4]='.';
    if(totaltirs<10)
    {
        c1=totaltirs+48;t[5]=c1;t[6]='.';t[7]='.';
    }
    else
    {
        desenes=(totaltirs/10);unitats=(totaltirs%10);
        c1=desenes+48;t[5]=c1;c1=unitats+48;t[6]=c1;t[7]='.';
    }
    if(sumatirs<10)
    {
        c1=sumatirs+48;t[8]=c1;t[9]='.';t[10]='.';
    }
    else
    {
        desenes=(sumatirs/10);unitats=(sumatirs%10);
        c1=desenes+48;t[8]=c1;c1=unitats+48;t[9]=c1;t[10]='.';
    }
    fwrite(&t,sizeof(char),11,dades);
    fclose(dades);
}
void guardar_taulells(char j1_v[][DIMAX],char j2_v[][DIMAX],char j1_ll[][DIMAX],char j2_ll[][DIMAX],int dim)
{
    int i;
    FILE *j1_vf, *j1_llf, *j2_vf, *j2_llf;

    j1_vf=fopen("j1_dispar.bin","wb+");
    j1_llf=fopen("j1_def.bin","wb+");
    j2_vf=fopen("j2_dispar.bin","wb+");
    j2_llf=fopen("j2_def.bin","wb+");

    for (i=0;i<dim;i++)
    {
        fwrite(&j1_v[i], sizeof(char),DIMAX,j1_vf);
    }
    for (i=0;i<dim;i++)
    {
        fwrite(&j1_ll[i],sizeof(char),DIMAX,j1_llf);
    }
    for (i=0;i<dim;i++)
    {
        fwrite(&j2_v[i],sizeof(char),DIMAX,j2_vf);
    }
    for (i=0;i<dim;i++)
    {
        fwrite(&j2_ll[i],sizeof(char),DIMAX,j2_llf);
    }
    fclose(j1_vf);
    fclose(j1_llf);
    fclose(j2_vf);
    fclose(j2_llf);
}
void emmagatzema_joc(char j1_v[DIMAX][DIMAX],char j2_v[DIMAX][DIMAX],char j1_ll[DIMAX][DIMAX],char j2_ll[DIMAX][DIMAX],int dim,int numjug,int totaltirs,int sumatirs)
{
   guardar_dades(dim,numjug,totaltirs,sumatirs);
   guardar_taulells(j1_v,j2_v,j1_ll,j2_ll,dim);
   printf("\nLa partida s'ha guardat correctament.\n\n");system("pause");system("cls");
}
void cargar_dades(int *dim,int *numjug,int *totaltirs,int *sumatirs)
{
    FILE *dades;
    char t[11],c1;
    int desenes,unitats;
    dades=fopen("dades.bin","rb+");
    fread(&t,sizeof(char),11,dades);
    if((t[0]=='8')||(t[0]=='9'))
    {
        if(t[0]=='8'){*dim=8;}
        else{*dim=9;}
    }
    else
    {
        *dim=10;
    }
    c1=t[3];*numjug=c1-48;
    if(t[6]=='.')
    {
        c1=t[5];*totaltirs=c1-48;
    }
    else
    {
        c1=t[5];desenes=c1-48;c1=t[6];unitats=c1-48;
        *totaltirs=(desenes*10)+unitats;
    }
    if(t[9]=='.')
    {
        c1=t[8];*sumatirs=c1-48;
    }
    else
    {
        c1=t[8];desenes=c1-48;c1=t[9];unitats=c1-48;
        *sumatirs=(desenes*10)+unitats;
    }
    fclose(dades);
}
void cargar_taulells(int dim,char j1_v[][DIMAX],char j2_v[][DIMAX],char j1_ll[][DIMAX],char j2_ll[][DIMAX])
{
    int i;
    FILE *j1_vf, *j1_llf, *j2_vf, *j2_llf;

    j1_vf=fopen("j1_dispar.bin","rb+");
    j1_llf=fopen("j1_def.bin","rb+");
    j2_vf=fopen("j2_dispar.bin","rb+");
    j2_llf=fopen("j2_def.bin","rb+");
    if((j1_vf==NULL)||(j1_llf==NULL)||(j2_vf==NULL)||(j1_llf==NULL))
    {
        printf("\nNo hi ha cap partida guardada.\n\n");system("pause");system("cls");
    }
    else
    {
        printf("\nLa partida s'ha carregat correctament.\n\n");system("pause");system("cls");
    }
    for (i=0;i<dim;i++)
    {
        fread(&j1_v[i],sizeof(char),DIMAX,j1_vf);
    }


    for (i=0;i<dim;i++)
    {
        fread(&j1_ll[i],sizeof(char),DIMAX,j1_llf);
    }

    for (i=0;i<dim;i++)
    {
        fread(&j2_v[i],sizeof(char),DIMAX,j2_vf);
    }

    for (i=0;i<dim;i++)
    {
        fread(&j2_ll[i],sizeof(char),DIMAX,j2_llf);
    }
    fclose(j1_vf);
    fclose(j1_llf);
    fclose(j2_vf);
    fclose(j2_llf);
}
void recupera_joc(int *dim,char j1_v[DIMAX][DIMAX],char j2_v[DIMAX][DIMAX],char j1_ll[DIMAX][DIMAX],char j2_ll[DIMAX][DIMAX],int *numjug,int *totaltirs,int *sumatirs)
{
   cargar_dades(&*dim,&*numjug,&*totaltirs,&*sumatirs);
   cargar_taulells(*dim,j1_v,j2_v,j1_ll,j2_ll);
}
void menu_inicial(int *opcio,int *ndades,record r[MAXR])
{
    printf("Selecciona una opcio del menu introduint el nombre de la opcio:\n");
    printf("\n1. Crear un nou joc.\n");
    printf("2. Carregar un joc emmagatzemat.\n");
    printf("5. Veure podium.\n");
    printf("6. Sortir del joc.\n");

    fflush(stdin);scanf("%d", &*opcio);
    system("cls");
    if (*opcio !=6)
    {
        while((*opcio !=6)&(*opcio !=1)&(*opcio !=2))
        {
            if(*opcio==5)
            {
                *ndades=recupera_records(r);
                mostrar_records(*ndades,r);
            }
            printf("Selecciona una opcio del menu introduint el nombre de la opcio:\n");
            printf("\n1. Crear un nou joc.\n");
            printf("2. Carregar un joc emmagatzemat.\n");
            printf("5. Veure podium.\n");
            printf("6. Sortir del joc.\n");

            fflush(stdin);scanf("%d", &*opcio);system("cls");
        }
    }
}
void menu_normal(int *opcio,char v1[DIMAX][DIMAX],char v2[DIMAX][DIMAX],char ll1[DIMAX][DIMAX],char ll2[DIMAX][DIMAX],int *dim,int *numjug,int *ndades,record r[MAXR],int *totaltirs,int *sumatirs)
{
    if (*opcio !=6)
    {
        if (*opcio ==1)
        {
            joc_nou(v1,v2,ll1,ll2,&*dim,&*numjug);
        }
        if (*opcio ==2)
        {
            recupera_joc(&*dim,v1,v2,ll1,ll2,&*numjug,&*totaltirs,&*sumatirs);
        }
        printf("Selecciona una opcio del menu introduient el nombre de la opcio:\n");
        printf("\n1. Crear un nou joc.\n");
        printf("2. Carregar un joc emmagatzemat.\n");
        printf("3. Jugar partida.\n");
        printf("4. Emmagatzemar el joc.\n");
        printf("5. Veure podium.\n");
        printf("6. Sortir del joc.\n");

        fflush(stdin);scanf("%d", &*opcio);
        system("cls");
        while(*opcio !=6)
        {
            switch(*opcio)
            {
                case 1:
                    joc_nou(v1,v2,ll1,ll2,&*dim,&*numjug);
                    break;
                case 2:
                    recupera_joc(&*dim,v1,v2,ll1,ll2,&*numjug,&*totaltirs,&*sumatirs);
                    break;
                case 3:
                    jugar_partida(v1,v2,ll1,ll2,*dim,*numjug,&*totaltirs,&*sumatirs);
                    break;
                case 4:
                    emmagatzema_joc(v1,v2,ll1,ll2,*dim,*numjug,*totaltirs,*sumatirs);
                    break;
                case 5:
                    *ndades=recupera_records(r);
                    mostrar_records(*ndades,r);
                    break;
                case 6:
                    break;
                default:
                    printf("\nOpcio incorrecta\n\n");
                    break;
            }
            printf("Selecciona una opcio del menu introduient el nombre de la opcio:\n");
            printf("\n1. Crear un nou joc.\n");
            printf("2. Carregar un joc emmagatzemat.\n");
            printf("3. Jugar partida.\n");
            printf("4. Emmagatzemar el joc.\n");
            printf("5. Veure podium.\n");
            printf("6. Sortir del joc.\n");

            fflush(stdin);scanf("%d", &*opcio);
            system("cls");
        }
        printf("\nFins aviat.\n");
    }
}

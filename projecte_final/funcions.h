/*----------------------------------------------------------------
|	Autor:Albert Cañellas
|   e-mail: albert.cañellas@estudiants.urv.cat
|	Data: Gener 2016                 Versio: 6.0
|-----------------------------------------------------------------|
|	Nom projecte: Projecte_final
|	Nom: funcions.h
|   Descripcio del Programa:   Les capçaleres de les funcions.
| ----------------------------------------------------------------*/


#include "tipus.h"

#define MAXP 30
#define MAXR 25
#define DIMAX 10

void dim_taulell(int *dim);
void mode_joc(int *numjug);
void jugar(int *f,int *c,char v[][DIMAX],char ll[][DIMAX],int dim,int *conta);
void jugada_nova(int *f,int *c,char v[][DIMAX],char ll[][DIMAX],int dim,int *conta);
int calcular_puntuacio(char t[][DIMAX],int dim,int totaltirs,int resultatTirs,int *sumatirs);
int recupera_records(record r[MAXR]);
void insercio_ordenada(record r[MAXR],record nou,int ndades);
void emmagatzema_records(record r[MAXR], int ndades);
void mostrar_records(int ndades,record r[MAXR]);
void nou_record(int puntuacio);
void jugar_partida(char v1[][DIMAX],char v2[][DIMAX],char ll1[][DIMAX],char ll2[][DIMAX],int dim, int numjug,int *totaltirs, int *sumatirs);
void joc_nou(char j1_v[DIMAX][DIMAX],char j2_v[DIMAX][DIMAX],char j1_ll[DIMAX][DIMAX],char j2_ll[DIMAX][DIMAX], int *dim,int *numjug);
void guardar_dades(int dim,int numjug,int totaltirs,int sumatirs);
void guardar_taulells(char j1_v[DIMAX][DIMAX],char j2_v[DIMAX][DIMAX],char j1_ll[DIMAX][DIMAX],char j2_ll[DIMAX][DIMAX],int dim);
void emmagatzema_joc(char j1_v[DIMAX][DIMAX],char j2_v[DIMAX][DIMAX],char j1_ll[DIMAX][DIMAX],char j2_ll[DIMAX][DIMAX],int dim,int numjug,int totaltirs,int sumatirs);
void cargar_dades(int *dim,int *numjug,int *totaltirs,int *sumatirs);
void cargar_taulells(int dim,char j1_v[][DIMAX],char j2_v[][DIMAX],char j1_ll[][DIMAX],char j2_ll[][DIMAX]);
void recupera_joc(int *dim,char j1_v[DIMAX][DIMAX],char j2_v[DIMAX][DIMAX],char j1_ll[DIMAX][DIMAX],char j2_ll[DIMAX][DIMAX],int *numjug,int *totaltirs,int *sumatirs);
void menu_inicial(int *opcio,int *ndades,record r[MAXR]);
void menu_normal(int *opcio,char v1[DIMAX][DIMAX],char v2[DIMAX][DIMAX],char ll1[DIMAX][DIMAX],char ll2[DIMAX][DIMAX],int *dim,int *numjug,int *ndades,record r[MAXR],int *totaltirs,int *sumatirs);



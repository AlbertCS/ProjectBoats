/*----------------------------------------------------------------
|	Autor: Professors de Fonaments de Programacio
|	Data: Novembre 2015                 Versio: 1.0
|-----------------------------------------------------------------|
|   Nom projecte: vaixells
|	Nom fitxer: vaixell.h
|   Descripcio del Programa: cap de procediments donats.
| ----------------------------------------------------------------*/
#ifndef VAIXELLS_H_INCLUDED
#define VAIXELLS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

#define MAXP 30
#define MAXR 25
#define DIMAX 10
#include "tipus.h"

enum orientacio
{
    HORITZONTAL = 0,
    VERTICAL = 1
};

enum casella
{
    CASELLA_BUIDA = '?',
    CASELLA_AIGUA = '.',
    CASELLA_VAIXELL = '@',
    CASELLA_VAIXELL_TOCAT = 'X',
    CASELLA_AIGUA_TOCADA = '-'
};

enum tret
{
    ERROR = -1,
    REPETIT = 0,
    AIGUA = 1,
    TOCAT = 2,
    ENFONSAT = 3
};

void clean_board_v(char t[][DIMAX], int dim);
void clean_board_ll(char t[][DIMAX], int dim);
void rodejar(int f,int c, char t[][DIMAX]);
void inicia_taulell(char t[][DIMAX], int dim);
void inicia_elmeu_taulell(char t[][DIMAX], int dim);
int dispara(int f,int c,char v[][DIMAX],char ll[][DIMAX]);

#endif /* VAIXELLS_H_INCLUDED */

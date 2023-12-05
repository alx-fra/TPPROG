// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2021-2022
/*
 * Alexandre José Leonardo Ferreira 2021138219
 * Ficheiro baseado nos ficheiros de suporte ao Trabalho Prático
 */

#ifndef TRABALHOPRATICO_MATDIN_H
#define TRABALHOPRATICO_MATDIN_H

#include <stdlib.h>
#include <stdio.h>

// Liberta uma matriz dinâmica de caracteres com nLin linhas
void libertaMat(char **p, int nLin);

// Cria uma matriz dinâmica de caracteres  com nLin linhas e nCol colunas
// Devolve endereço inicial da matriz
char **criaMat(int nLin, int nCol);


#endif //TRABALHOPRATICO_MATDIN_H

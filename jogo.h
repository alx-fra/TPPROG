// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2021-2022
/*
 * Alexandre José Leonardo Ferreira 2021138219
*/


#ifndef TRABALHOPRATICO_JOGO_H
#define TRABALHOPRATICO_JOGO_H
#define N 3

#include <stdio.h>

//void initTab(char galo[][N]);
void initTab(char **galo);

//void printTab(char galo[N][N]);
//void printTab(char **galo);
void printTab(char **aux1, char **aux2, char **aux3, char **aux4, char **aux5, char **aux6, char **aux7, char **aux8,
              char **aux9);

//void jogada(char galo[N][N], int jogador, int* pposicao);
void jogada(char **galo, int jogador, int *pposicao, int *tipoJogo);

//int confirma(char galo[][N]);
int confere_galo(char **galo, char *c);

//altera a matriz para os caracteres conforme se terminou
int altera_galo(int *fim, char **galo, char *c);

//converte matriz linha em linha e coluna com o caracter do vencedor em cada posicao
void converte(char **mat1, char **mat2);

//printa vencedor ou empatado
int final(int tipo, char vencedor);

//apresenta no inicio do prgrama como funcionam as posicoes no tabuleiro
void informacoes();

#endif //TRABALHOPRATICO_JOGO_H

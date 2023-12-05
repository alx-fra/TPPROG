// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2021-2022
/*
 * Alexandre José Leonardo Ferreira 2021138219
*/

#ifndef TRABALHOPRATICO_LISTA_H
#define TRABALHOPRATICO_LISTA_H

#include <stdio.h>
#include <malloc.h>

#define FICH "jogo.bin"
#define FICHTXT "jogo.txt"
#define N 3

typedef struct tabuleiro jogo, *pjogo;
struct tabuleiro {
    int player;
    int table;
    int play;
    pjogo prox;
};

void mostra_info(pjogo p, int jogadas, int tam);

void preenche(pjogo p, int jogador, int tab, int jogada);

pjogo insere_final(pjogo p, int jogador, int tab, int jogada, int *tam);

void guarda_lista(struct tabuleiro *headptr);

pjogo recupera_lista(char *nomeFicheiro, int *tam);

int altera_galos(pjogo p, char **aux1, char **aux2, char **aux3, char **aux4, char **aux5, char **aux6, char **aux7,
                 char **aux8, char **aux9, int *jogador);

int fich_vazio();


#endif //TRABALHOPRATICO_LISTA_H

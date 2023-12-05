// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2021-2022
/*
 * Alexandre José Leonardo Ferreira 2021138219
*/
#include "lista.h"

void mostra_info(pjogo p, int jogadas, int tam) {
    int count = 0;
    while (p != NULL) {
        //se count maior igual que tam - anteriores printa (printa as ultimas "jogadas")
        if (count >= (tam - jogadas)) {
            if (p->player == 1) {
                printf("Jogador: X\n");
            } else if (p->player == 2) {
                printf("Jogador: O\n");
            }
            printf("Tabuleiro:%d\n", p->table);
            printf("Jogada:%d\n", p->play);
            printf("\n");
        }
        p = p->prox;
        count++;
    }
}

void preenche(pjogo p, int jogador, int tab, int jogada) {
    p->player = jogador;
    p->table = tab;
    p->play = jogada;
    p->prox = NULL;
}

pjogo insere_final(pjogo p, int jogador, int tab, int jogada, int *tam) {
    pjogo novo, aux;
    novo = malloc(sizeof(jogo));
    if (novo == NULL) {
        printf("Erro na alocacao de memoria\n");
        return p;
    }
    preenche(novo, jogador, tab, jogada);
    (*tam)++;

    if (p == NULL)
        p = novo;
    else {
        aux = p;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    return p;
}

void guarda_lista(struct tabuleiro *headptr) {
    FILE *text = fopen(FICH, "wb");
    pjogo aux = headptr;
    if (text == NULL) {
        printf("ERRO ao armazenar lista\n");
        return;
    }
    while (aux != NULL) {
        fwrite(aux, sizeof(jogo), 1, text);
        aux = aux->prox;
    }
    fclose(text);
}

pjogo recupera_lista(char *nomeFicheiro, int *tam) {
    FILE *f;
    pjogo novo, lista = NULL, aux_lista;
    jogo aux;
    if ((f = fopen(nomeFicheiro, "rb")) == NULL) {
        printf("ERRO");
        return NULL;
    }
    while (fread(&aux, sizeof(jogo), 1, f) == 1) {
        aux.prox = NULL;
        novo = malloc(sizeof(jogo));
        if (novo == NULL) {
            printf("ERRO");
            fclose(f);
            return NULL;
        }
        *novo = aux;
        if (lista == NULL) {
            lista = novo;
        } else {
            aux_lista = lista;
            while (aux_lista->prox != NULL) {
                aux_lista = aux_lista->prox;
            }
            aux_lista->prox = novo;
        }
        (*tam)++;
    }
    fclose(f);
    return lista;
}

int altera_galos(pjogo p, char **aux1, char **aux2, char **aux3, char **aux4, char **aux5, char **aux6, char **aux7,
                 char **aux8, char **aux9, int *jogador) {
    //altere a funcao acabados também e ter atencao ao valor i que vai ser preciso no ciclo for, basicamente é o tam da lista
    //ativa uma flag se a flag no cilo for estiver ativa o i=tamlistaposfich
    int tab, jogada;

    while (p != NULL) {
        tab = p->table;

        switch (tab) {
            case 1:
                *jogador = p->player;
                jogada = p->play;
                if (*jogador == 1)
                    aux1[((jogada) - 1) / N][((jogada) - 1) % N] = 'X';
                else
                    aux1[((jogada) - 1) / N][((jogada) - 1) % N] = 'O';
                break;
            case 2:
                *jogador = p->player;
                jogada = p->play;
                if (*jogador == 1)
                    aux2[((jogada) - 1) / N][((jogada) - 1) % N] = 'X';
                else
                    aux2[((jogada) - 1) / N][((jogada) - 1) % N] = 'O';
                break;
            case 3:
                *jogador = p->player;
                jogada = p->play;
                if (*jogador == 1)
                    aux3[((jogada) - 1) / N][((jogada) - 1) % N] = 'X';
                else
                    aux3[((jogada) - 1) / N][((jogada) - 1) % N] = 'O';
                break;
            case 4:
                *jogador = p->player;
                jogada = p->play;
                if (*jogador == 1)
                    aux4[((jogada) - 1) / N][((jogada) - 1) % N] = 'X';
                else
                    aux4[((jogada) - 1) / N][((jogada) - 1) % N] = 'O';
                break;
            case 5:
                *jogador = p->player;
                jogada = p->play;
                if (*jogador == 1)
                    aux5[((jogada) - 1) / N][((jogada) - 1) % N] = 'X';
                else
                    aux5[((jogada) - 1) / N][((jogada) - 1) % N] = 'O';
                break;
            case 6:
                *jogador = p->player;
                jogada = p->play;
                if (*jogador == 1)
                    aux6[((jogada) - 1) / N][((jogada) - 1) % N] = 'X';
                else
                    aux6[((jogada) - 1) / N][((jogada) - 1) % N] = 'O';
                break;
            case 7:
                *jogador = p->player;
                jogada = p->play;
                if (*jogador == 1)
                    aux7[((jogada) - 1) / N][((jogada) - 1) % N] = 'X';
                else
                    aux7[((jogada) - 1) / N][((jogada) - 1) % N] = 'O';
                break;
            case 8:
                *jogador = p->player;
                jogada = p->play;
                if (*jogador == 1)
                    aux8[((jogada) - 1) / N][((jogada) - 1) % N] = 'X';
                else
                    aux8[((jogada) - 1) / N][((jogada) - 1) % N] = 'O';
                break;
            case 9:
                *jogador = p->player;
                jogada = p->play;
                if (*jogador == 1)
                    aux9[((jogada) - 1) / N][((jogada) - 1) % N] = 'X';
                else
                    aux9[((jogada) - 1) / N][((jogada) - 1) % N] = 'O';
                break;
            default:
                break;
        }
        p = p->prox;
    }
    return jogada;

}

int fich_vazio() {
    FILE *f = fopen(FICH, "r");

    if (f == NULL)
        return 0;
    fseek(f, 0, SEEK_END);
    int tam = ftell(f);
    fclose(f);

    return tam;
}

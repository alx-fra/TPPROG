// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2021-2022
/*
 * Alexandre José Leonardo Ferreira 2021138219
*/

#include <stdio.h>
#include "jogo.h"
#include "matdin.h"

#define N 3
#define FICH "jogo.bin"

#include "utils.h"
#include "lista.h"


int main(void) {
    char vencedor = ' ', caracter = ' ', yn, ynFunc;
    int jogador = 1, ganha = 0, posicao = 0, acabado, tipoVencedor = 0, modo = 0, anteriores, tamLista = 0, tamListaPosFich = 0, tab, galo_fim = 0, i = 0;
    int flag = 0, jogadas = 0;
    char **galo1 = criaMat(N, N);
    char **galo2 = criaMat(N, N);
    char **galo3 = criaMat(N, N);
    char **galo4 = criaMat(N, N);
    char **galo5 = criaMat(N, N);
    char **galo6 = criaMat(N, N);
    char **galo7 = criaMat(N, N);
    char **galo8 = criaMat(N, N);
    char **galo9 = criaMat(N, N);
    char **acabados = criaMat(1,
                              10);//matriz com uma linha e com 10 elementos sendo que o primeiro é apenas uma flag e os outros dizem o caracter que ganhou em cada elemento ou E se estiver empatado
    char **confirmaVencedor = criaMat(N,
                                      N);//matriz 3 por 3 guarda o caracter nos tabuleiros acabados, E nos empatados e 0 nos por terminar
    initRandom();
    initTab(galo1);
    initTab(galo2);
    initTab(galo3);
    initTab(galo4);
    initTab(galo5);
    initTab(galo6);
    initTab(galo7);
    initTab(galo8);
    initTab(galo9);

    pjogo lista = NULL;
    pjogo listaPosFich = NULL;

    //inicializar o tabuleiro a 0
    for (int col = 0; col < 10; col++) {
        acabados[0][col] = '0';
    }

    //mostrar como funcionam as posicoes
    printf("-->Quer aceder ao modo de funcionamento? (Y/N)");
    do {
        printf("\n-->");
        while (scanf("%c", &ynFunc) != 1) {
            printf("-->");
            while (getchar() != '\n');
        }
    } while (ynFunc != 'Y' && ynFunc != 'y' && ynFunc != 'N' && ynFunc != 'n');
    if (ynFunc == 'Y' || ynFunc == 'y') {
        informacoes();
        printf("\n");
    }

    //obter modo de jogo com as devidas validacoes
    printf("-->Indique o modo de jogo\n");
    printf("-->'1' -> 1 Jogador\n");
    printf("-->'2' -> 2 Jogadores");
    do {
        printf("\n-->");
        while (scanf("%d", &modo) != 1) {
            printf("-->");
            while (getchar() != '\n');
        }
    } while (modo != 1 && modo != 2);

    //Entra se o ficheiro nao estiver vazio
    if (fich_vazio() != 0) {
        printf("-->Quer recuperar um jogo anteriormente realizado? (Y/N)");
        do {
            printf("\n-->");
            while (scanf("%c", &yn) != 1) {
                printf("\n-->");
                while (getchar() != '\n');
            }
        } while (yn != 'Y' && yn != 'y' && yn != 'N' && yn != 'n');

        if (yn == 'Y' || yn == 'y') {
            listaPosFich = NULL;
            lista = NULL;
            flag = 1;
            listaPosFich = recupera_lista(FICH, &tamListaPosFich);
            posicao = altera_galos(listaPosFich, galo1, galo2, galo3, galo4, galo5, galo6, galo7, galo8, galo9,
                                   &jogador);
            //comeca a jogar o jogador que nao foi o ultimo a jogar no ficheiro guardado
            if (jogador == 2)
                jogador = 0;
            jogador++;

            printTab(galo1, galo2, galo3, galo4, galo5, galo6, galo7, galo8, galo9);
            galo_fim = confere_galo(galo1, &caracter);
            acabado = altera_galo(&galo_fim, galo1, &caracter);
            //se acabar o acabado fica com 1 no index de acabados do nr do tab que acabou
            if (acabado == 1)
                acabados[0][1] = caracter;

            lista = listaPosFich;
            tamLista += tamListaPosFich;

        } else if (yn == 'N' || yn == 'n') {
            fopen(FICH, "w");
            listaPosFich = NULL;
        }
    }

    //ciclo quebra quando alguem vencer ou quando todos os lugares estiverem ocupados
    //ciclo comeca em 0 se comecar a ler do 0 e pergunta o primeiro tabuleiro ou comeca em 1 e continua de onde acabou
    for (i = flag; (i < ((N * N) * 9)) && (ganha == 0); i++) {
        //da primeira vez pergunta o tabuleiro
        //um jogador diz o tabuleiro que querem começar e outro começa a jogar
        if (i == 0 && flag == 0) {
            if (modo == 2) {
                printf("-->Jogador O, indique o tabuleiro a comecar:");
                do {
                    printf("\n-->");
                    while (scanf("%d", &tab) != 1) {
                        printf("-->");
                        while (getchar() != '\n');
                    }
                } while (tab < 1 || tab > 9);

            } else if (modo == 1) {
                tab = intUniformRnd(1, 9);
            }
        } else {
            //caso a posicao remeta a um tabuleiro ja completo
            //  joga se no seguinte tabuleiro por completar
            while (acabados[0][posicao] == 'X' || acabados[0][posicao] == 'O' || acabados[0][posicao] == 'E') {
                do {
                    //caso esteja no ultimo com a intrução que está fora do if (posicao++) , volta ao tabuleiro 1
                    if (posicao == 9) {
                        posicao = 0;
                    }
                    posicao++;
                    tab = posicao;
                } while (acabados[0][posicao] == 'X' || acabados[0][posicao] == 'O' || acabados[0][posicao] == 'E');
            }
            tab = posicao;
            printf("\n-->Tabuleiro em jogo: %i\n", tab);
        }

        //cada caso remete ao tabuleiro onde se vai jogar sendo que todos funcionam de igual forma
        switch (tab) {
            case 1:
                if (((modo == 1 && jogador == 1) || modo == 2 && flag != 1) && jogadas != 0) {
                    printf("-->Quer visualizar entre 1 e 10 jogadas feitas anteriormente? Se sim indique quantas caso contrario digite 0:");
                    do {
                        printf("\n-->");
                        while (scanf("%d", &anteriores) != 1) {
                            printf("-->");
                            while (getchar() != '\n');
                        }
                    } while (anteriores < 0 || anteriores > 10);

                    if (anteriores != 0 && anteriores <= 10 && anteriores > 0) {
                        mostra_info(lista, anteriores, tamLista);
                    }
                }
                jogada(galo1, jogador, &posicao, &modo);
                jogadas++;
                lista = insere_final(lista, jogador, tab, posicao, &tamLista);

                guarda_lista(lista);

                //galofim   ==2 se ocore empate      ==1 se alguem venceu(o caracter)     ==0 se nao acabou o jogo
                galo_fim = confere_galo(galo1, &caracter);
                //acabado ==
                acabado = altera_galo(&galo_fim, galo1, &caracter);
                printTab(galo1, galo2, galo3, galo4, galo5, galo6, galo7, galo8, galo9);

                //se acabar o acabado fica com um no index de acabados do nr do tab que acabou
                if (acabado == 1)
                    acabados[0][1] = caracter;

                break;
            case 2:
                if (((modo == 1 && jogador == 1) || modo == 2 && flag != 1) && jogadas != 0) {
                    printf("-->Quer visualizar entre 1 e 10 jogadas feitas anteriormente? Se sim indique quantas caso contrario digite 0:");
                    do {
                        printf("\n-->");
                        while (scanf("%d", &anteriores) != 1) {
                            printf("-->");
                            while (getchar() != '\n');
                        }
                    } while (anteriores < 0 || anteriores > 10);
                    if (anteriores != 0 && anteriores <= 10 && anteriores > 0) {
                        mostra_info(lista, anteriores, tamLista);
                    }
                }
                jogada(galo2, jogador, &posicao, &modo);
                jogadas++;
                lista = insere_final(lista, jogador, tab, posicao, &tamLista);

                guarda_lista(lista);

                galo_fim = confere_galo(galo2, &caracter);
                acabado = altera_galo(&galo_fim, galo2, &caracter);
                printTab(galo1, galo2, galo3, galo4, galo5, galo6, galo7, galo8, galo9);

                if (acabado == 1)
                    acabados[0][2] = caracter;

                break;
            case 3:
                if (((modo == 1 && jogador == 1) || modo == 2 && flag != 1) && jogadas != 0) {
                    printf("-->Quer visualizar entre 1 e 10 jogadas feitas anteriormente? Se sim indique quantas caso contrario digite 0:");
                    do {
                        printf("\n-->");
                        while (scanf("%d", &anteriores) != 1) {
                            printf("-->");
                            while (getchar() != '\n');
                        }
                    } while (anteriores < 0 || anteriores > 10);
                    if (anteriores != 0 && anteriores <= 10 && anteriores > 0) {
                        mostra_info(lista, anteriores, tamLista);
                    }
                }
                jogada(galo3, jogador, &posicao, &modo);
                jogadas++;
                lista = insere_final(lista, jogador, tab, posicao, &tamLista);

                guarda_lista(lista);

                galo_fim = confere_galo(galo3, &caracter);
                acabado = altera_galo(&galo_fim, galo3, &caracter);
                printTab(galo1, galo2, galo3, galo4, galo5, galo6, galo7, galo8, galo9);

                if (acabado == 1)
                    acabados[0][3] = caracter;

                break;
            case 4:
                if (((modo == 1 && jogador == 1) || modo == 2 && flag != 1) && jogadas != 0) {
                    printf("-->Quer visualizar entre 1 e 10 jogadas feitas anteriormente? Se sim indique quantas caso contrario digite 0:");
                    do {
                        printf("\n-->");
                        while (scanf("%d", &anteriores) != 1) {
                            printf("-->");
                            while (getchar() != '\n');
                        }
                    } while (anteriores < 0 || anteriores > 10);
                    if (anteriores != 0 && anteriores <= 10 && anteriores > 0) {
                        mostra_info(lista, anteriores, tamLista);
                    }
                }
                jogada(galo4, jogador, &posicao, &modo);
                jogadas++;
                lista = insere_final(lista, jogador, tab, posicao, &tamLista);

                guarda_lista(lista);

                galo_fim = confere_galo(galo4, &caracter);
                acabado = altera_galo(&galo_fim, galo4, &caracter);
                printTab(galo1, galo2, galo3, galo4, galo5, galo6, galo7, galo8, galo9);

                if (acabado == 1)
                    acabados[0][4] = caracter;

                break;
            case 5:
                if (((modo == 1 && jogador == 1) || modo == 2 && flag != 1) && jogadas != 0) {
                    printf("-->Quer visualizar entre 1 e 10 jogadas feitas anteriormente? Se sim indique quantas caso contrario digite 0:");
                    do {
                        printf("\n-->");
                        while (scanf("%d", &anteriores) != 1) {
                            printf("-->");
                            while (getchar() != '\n');
                        }
                    } while (anteriores < 0 || anteriores > 10);
                    if (anteriores != 0 && anteriores <= 10 && anteriores > 0) {
                        mostra_info(lista, anteriores, tamLista);
                    }
                }
                jogada(galo5, jogador, &posicao, &modo);
                jogadas++;
                lista = insere_final(lista, jogador, tab, posicao, &tamLista);

                guarda_lista(lista);

                galo_fim = confere_galo(galo5, &caracter);
                acabado = altera_galo(&galo_fim, galo5, &caracter);
                printTab(galo1, galo2, galo3, galo4, galo5, galo6, galo7, galo8, galo9);

                if (acabado == 1)
                    acabados[0][5] = caracter;

                break;
            case 6:
                if (((modo == 1 && jogador == 1) || modo == 2 && flag != 1) && jogadas != 0) {
                    printf("-->Quer visualizar entre 1 e 10 jogadas feitas anteriormente? Se sim indique quantas caso contrario digite 0:");
                    do {
                        printf("\n-->");
                        while (scanf("%d", &anteriores) != 1) {
                            printf("-->");
                            while (getchar() != '\n');
                        }
                    } while (anteriores < 0 || anteriores > 10);
                    if (anteriores != 0 && anteriores <= 10 && anteriores > 0) {
                        mostra_info(lista, anteriores, tamLista);
                    }
                }
                jogada(galo6, jogador, &posicao, &modo);
                jogadas++;
                lista = insere_final(lista, jogador, tab, posicao, &tamLista);

                guarda_lista(lista);

                galo_fim = confere_galo(galo6, &caracter);
                acabado = altera_galo(&galo_fim, galo6, &caracter);
                printTab(galo1, galo2, galo3, galo4, galo5, galo6, galo7, galo8, galo9);

                if (acabado == 1)
                    acabados[0][6] = caracter;

                break;
            case 7:
                if (((modo == 1 && jogador == 1) || modo == 2 && flag != 1) && jogadas != 0) {
                    printf("-->Quer visualizar entre 1 e 10 jogadas feitas anteriormente? Se sim indique quantas caso contrario digite 0:");
                    do {
                        printf("\n-->");
                        while (scanf("%d", &anteriores) != 1) {
                            printf("-->");
                            while (getchar() != '\n');
                        }
                    } while (anteriores < 0 || anteriores > 10);
                    if (anteriores != 0 && anteriores <= 10 && anteriores > 0) {
                        mostra_info(lista, anteriores, tamLista);
                    }
                }
                jogada(galo7, jogador, &posicao, &modo);
                jogadas++;
                lista = insere_final(lista, jogador, tab, posicao, &tamLista);

                guarda_lista(lista);

                galo_fim = confere_galo(galo7, &caracter);
                acabado = altera_galo(&galo_fim, galo7, &caracter);
                printTab(galo1, galo2, galo3, galo4, galo5, galo6, galo7, galo8, galo9);

                if (acabado == 1)
                    acabados[0][7] = caracter;

                break;
            case 8:
                if (((modo == 1 && jogador == 1) || modo == 2 && flag != 1) && jogadas != 0) {
                    printf("-->Quer visualizar entre 1 e 10 jogadas feitas anteriormente? Se sim indique quantas caso contrario digite 0:");
                    do {
                        printf("\n-->");
                        while (scanf("%d", &anteriores) != 1) {
                            printf("-->");
                            while (getchar() != '\n');
                        }
                    } while (anteriores < 0 || anteriores > 10);
                    if (anteriores != 0 && anteriores <= 10 && anteriores > 0) {
                        mostra_info(lista, anteriores, tamLista);
                    }
                }
                jogada(galo8, jogador, &posicao, &modo);
                jogadas++;
                lista = insere_final(lista, jogador, tab, posicao, &tamLista);

                guarda_lista(lista);

                galo_fim = confere_galo(galo8, &caracter);
                acabado = altera_galo(&galo_fim, galo8, &caracter);
                printTab(galo1, galo2, galo3, galo4, galo5, galo6, galo7, galo8, galo9);

                if (acabado == 1)
                    acabados[0][8] = caracter;

                break;
            case 9:
                if (((modo == 1 && jogador == 1) || modo == 2 && flag != 1) && jogadas != 0) {
                    printf("-->Quer visualizar entre 1 e 10 jogadas feitas anteriormente? Se sim indique quantas caso contrario digite 0:");
                    do {
                        printf("\n-->");
                        while (scanf("%d", &anteriores) != 1) {
                            printf("-->");
                            while (getchar() != '\n');
                        }
                    } while (anteriores < 0 || anteriores > 10);
                    if (anteriores != 0 && anteriores <= 10 && anteriores > 0) {
                        mostra_info(lista, anteriores, tamLista);
                    }
                }
                jogada(galo9, jogador, &posicao, &modo);
                jogadas++;
                lista = insere_final(lista, jogador, tab, posicao, &tamLista);

                guarda_lista(lista);

                galo_fim = confere_galo(galo9, &caracter);
                acabado = altera_galo(&galo_fim, galo9, &caracter);
                printTab(galo1, galo2, galo3, galo4, galo5, galo6, galo7, galo8, galo9);

                if (acabado == 1)
                    acabados[0][9] = caracter;

                break;
            default:
                break;
        }

        //converter  matriz acabados (linha) numa matriz 3 por 3 chamada confirmaVencedor para ser aplicada na função confere e reaproveitar o codigo
        // e trocar os '0' por'_' para ser conferida
        converte(acabados, confirmaVencedor);

        //vencedor é um auxiliar para guardar o valor do caracter sem alterar o seu valor
        vencedor = caracter;
        tipoVencedor = confere_galo(confirmaVencedor, &vencedor);

        //apresentar mensagem se acabou o jogo e se sim, ganha==1
        ganha = final(tipoVencedor, vencedor);

        guarda_lista(lista);


        if (jogador == 2)
            jogador = 0;
        jogador++;
        //jogo implementado do ficheiro passa a comportar-se como normal
        flag = 0;
    }
    //guarda lista no fich txt
    char ficheiro[95],ficheiroTxt[100];
    printf("-->Indique o nome do ficheiro texto a guardar as jogadas realizadas:");
    printf("\n-->");
    scanf(" %s\n", &ficheiro);
    sprintf(ficheiroTxt,"%s.txt",ficheiro);
    FILE *f;
    char c;
    f = fopen(ficheiroTxt, "w");
    if (f == NULL)
        exit(-1);
    else {
        while (lista != NULL) {
            if (lista->player == 1) {
                c = 'X';
            } else if (lista->player == 2) {
                c = 'O';
            }
            fprintf(f, "Jogador:%c # Tabuleiro:%d # Jogada:%d\n",
                    c,
                    lista->table, lista->play);
            lista = lista->prox;
        }
        fclose(f);
    }

    //guarda lista no ficheiro bin
    guarda_lista(lista);

    fopen(FICH, "w");
    listaPosFich = NULL;

    libertaMat(galo1, N);
    libertaMat(galo2, N);
    libertaMat(galo3, N);
    libertaMat(galo4, N);
    libertaMat(galo5, N);
    libertaMat(galo6, N);
    libertaMat(galo7, N);
    libertaMat(galo8, N);
    libertaMat(galo9, N);
    libertaMat(acabados, 1);
    libertaMat(confirmaVencedor, N);



    //eliminar lista

}

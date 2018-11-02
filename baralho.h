#include <stdio.h>
#include <stdlib.h>

typedef struct carta {
	char naipe;
	int valor;
} Carta;

typedef struct baralho {
	int tamanho;
	Carta *cartas;
	int posicao;
} Baralho;

// aloca o tamanho correto do baralho
Baralho defineTamanho(int tamanho);

// le os valores das cartas dados pela entrada padrão
void leituraBaralho(Baralho *b);

// retorna a proxima carta do deck
int sorteiaCarta(Baralho *b);

// rouba colocando uma carta de valor dado no topo do deck
// se ela nao existir nao faz nada
void roubaCarta(Baralho *b, int valor);

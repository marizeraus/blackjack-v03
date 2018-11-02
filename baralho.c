#include "baralho.h"


void trocaCarta(Baralho *b, int local){
	Carta aux;
	aux = (b->cartas[b->posicao]);
	b->cartas[b->posicao] = b->cartas[local];
	b->cartas[local] = aux;
}

int valor_carta(char x){ 
    if (x=='A') return 1;
    else if (x=='J'|| x=='K' || x=='Q' || x=='0') return 10;
    return x-48; 
}

// aloca o tamanho correto do baralho
Baralho defineTamanho(int tamanho){
	Baralho deck;
	deck.cartas = (Carta *)malloc(tamanho*sizeof(Carta));
	deck.tamanho = tamanho;
	deck.posicao = 0;
	return deck;
}


// le os valores das cartas dados pela entrada padrão
void leituraBaralho(Baralho *b){
	for(int i=0; i<b->tamanho; i++){
		char nome; char naipe;
		scanf(" %c%c", &nome, &naipe);
		b->cartas[i].valor = valor_carta(nome);
		b->cartas[i].naipe = naipe;
	}
}

// retorna a proxima carta do deck
int sorteiaCarta(Baralho *b){
	int Valor;
	int pos = b->posicao;
	Valor = b->cartas[pos].valor;
	b->posicao++;
	printf("Carta: %d-%c\n", Valor, b->cartas[pos].naipe);
	return Valor;
	}


// rouba colocando uma carta de valor dado no topo do deck
// se ela nao existir nao faz nada
void roubaCarta(Baralho *b, int valor){
	int num = b->posicao;
	for (int i=num; i<b->tamanho;i++){
		if(b->cartas[i].valor == valor){
			trocaCarta(&(*b), i);
			break;
		}

	}
}
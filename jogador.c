#include "jogador.h"

// incializa um jogador, dado o seu nome
Jogador initJogador(char *nome){
	int size = strlen(nome);
	Jogador j;
	j.nome = (char *)malloc(size*sizeof(char));
	strcpy(j.nome, nome);
	j.pont = 0;
	j.aposta = 0;
	j.total = 0;
	return j;
}

// atualiza o valor da aposta e outras variaveis no inicio de uma partida
void initPartida(Jogador *j, int aposta){
	j->pont = 0;
	j->aposta = aposta;
}
// impreme na tela no nome de um jogador
void imprimeJogador(Jogador j){
	printf("aaaaaa");
	printf("%s\n", j.nome);
}

// adiciona o valor de uma carta a pontuacao do jogador
void somaPonto(Jogador *j, int valor){
	j->pont +=valor;
}

// retorna o valor da pontuacao do jogador
int retornaPonto(Jogador j){
	return j.pont;
}

// imprime na tela o valor ganho ou perdido pelo jogador
void imprimeResultado(Jogador j){
	if (j.total<0){
		j.total = - j.total;
		printf("%s, voce perdeu %d reais.\n", j.nome, j.total);
	}
	else{
		printf("%s, voce ganhou %d reais.\n", j.nome, j.total);

	}
}

// atualiza o total de dinheiro do jogador e imprime na tela que ele ganhou
void vitoria(Jogador *j){
	printf("Voce ganhoui!\n");
	j->total += j->aposta;
	return;

}

// atualiza o total de dinheiro do jogador e imprime na tela que ele perdeu
void derrota(Jogador *j){
	printf("Voce perdeu!\n");
	j->total -= j->aposta;
	return;

}

#include "baralho.h"
#include "jogador.h"


int main(){
	Baralho b;
	Jogador j;
	int n;
	char *nome;
	nome = (char *)malloc(40*sizeof(char));

// inicializa o jogador e o baralho
	scanf(" %d", &n);
	b = defineTamanho(n);
	leituraBaralho(&b);
	printf("Digite seu nome:\n");
	scanf(" %s", nome);
	j = initJogador(nome);
	free(nome);

// começa o jogo
	char jogando = 'S';
	while (jogando=='S'){

		int aposta;
		int pontos = 0;
		printf("Digite sua aposta:\n");
		scanf("%d", &aposta);
		initPartida(&j, aposta);

		char continua = 'S';
		char turn = 'P';

		imprimeJogador(j);

		while (continua = 'S'){

			int sorteada;
			sorteada = sorteiaCarta(&b);
			somaPonto(&j, sorteada);
			pontos = retornaPonto(j);

			if (pontos==21){
				turn = 'W';
				continua = 'N';
				break;
			}
			else if (pontos>21){
				turn = 'L';
				continua = 'N';
				break;
			}
			else{
				printf("Deseja continuar (S/N):\n");
				scanf(" %c", &continua);
				if (continua=='N'){
					turn = 'D';
					break;

				}
				else if (continua=='R'){
					int roubada;
					printf("Digite o valor:\n");
					scanf("%d", &roubada);
					roubaCarta(&b, roubada);
					continua = 'S';
				}
			}

		}


		int pontosDealer = 0;
		printf("Dealer\n");

		while (turn == 'D'){

			while (pontosDealer<17){
				pontosDealer+=sorteiaCarta(&b);
			}
			if (pontosDealer==21) turn = 'L';
			else if (pontosDealer>21) turn ='W';
			else{
				if (pontosDealer>retornaPonto(j)) turn = 'L' ;
				else turn = 'W';
			}
		}

		if (turn == 'W') vitoria(&j);
		else if (turn== 'L') derrota(&j);

		printf("Deseja fazer nova aposta (S/N):\n");
		scanf(" %c", &jogando);

		if (jogando=='N') break;


		}

		imprimeResultado(j);


		return 0;
	}





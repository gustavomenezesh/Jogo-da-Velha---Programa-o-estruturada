#include <iostream>
#include <conio.h>
#include "tabuleiro.h"
#include "teclado.h"

int main(int argc, char** argv) {
	printf("Aperte enter para iniciar o jogo:");
	getch();
	
	tabuleiro t;
	aloca_tabuleiro(&t);
	imprime_tabuleiro(&t);
	while(t.acabaJogo!=1){
		int comando = pegar_comando_teclado();
		atualiza_tabuleiro(&t,comando);
		vitoria(&t);
	}
	return 0;
}

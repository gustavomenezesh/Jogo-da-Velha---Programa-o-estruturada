#include <stdio.h>
#include "tabuleiro.h"
#include <conio.h>
#include <stdlib.h>
#include "teclado.h"

void aloca_tabuleiro(tabuleiro *t){
	t->vez = 1;
	t->n = 3;
	t->campo = new int*[t->n];
	
	for(int i = 0;i<t->n;i++){
		t->campo[i] = new int[t->n];
	}
	
	for(int i = 0;i<t->n;i++){
		for(int j = 0;j<t->n;j++){
			t->campo[i][j] = VAZIO;
		}
	}
	t->linhaJogador =0;
	t->colunaJogador = 0;
}

void imprime_tabuleiro(tabuleiro *t){
	system("cls");
	for(int i = 0;i<t->n;i++){
		
		for(int j = 0;j<t->n;j++){
			
			switch(t->campo[i][j]){
				case VAZIO:
					if((t->linhaJogador==i) && (t->colunaJogador==j)){
						printf("[ ]");
					}else{
						
						printf("   ");
					}
					break;
				case JOGADOR_O:
					if((t->linhaJogador==i) && (t->colunaJogador==j)){
						printf("[O]");
					}else{
					
						printf(" O ");
					}
					break;
				case JOGADOR_X:
					if((t->linhaJogador==i) && (t->colunaJogador==j)){
						printf("[X]");
					}else{
					
						printf(" X ");
					}
					break;	
			}
			if(j < t->n-1){
				printf("|");
			}
		}
			printf("\n");
			if(i< t->n-1){
				printf("---+---+---\n");
			}
	}
}

void atualiza_tabuleiro(tabuleiro *t,int comando){
	int lin = t->linhaJogador;
	int col = t->colunaJogador;
	switch(comando){
		case CIMA:
			--lin;
			break;
		case BAIXO:
			++lin;
			break;
		case DIREITA:
			++col;
			break;
		case ESQUERDA:
			--col;
			break;
		case ENTER:
			if(t->campo[t->linhaJogador][t->colunaJogador]==VAZIO){
				if(t->vez%2 == 0){
					t->campo[t->linhaJogador][t->colunaJogador]=JOGADOR_O;	
				}else{
					t->campo[t->linhaJogador][t->colunaJogador]=JOGADOR_X;
				}
				t->vez = t->vez + 1;
			}			
		case DESCONHECIDO:
			break;
	}
	
	if((col<0)||(col>=t->n)||(lin<0)||(lin>=t->n)) {
		return;
	}
	t->linhaJogador = lin;
	t->colunaJogador = col;	
	imprime_tabuleiro(t);
		
	}
	
	void vitoria (tabuleiro *t){
		
		int soma = 0;
		for(int i=0;i<t->n;i++){
			soma = 0;
			for(int j = 0; j<t->n;j++){
				soma = soma + t->campo[i][j];
				if (soma == 3){
					printf("\nJogador_O GANHOU!");
					t->acabaJogo=1;
				}else if(soma == 12){
					printf("\nJogador_X GANHOU!");
					t->acabaJogo=1;
				}
			}	
		}
		
		
		for(int i=0;i<t->n;i++){
			soma = 0;
			for(int j = 0; j<t->n;j++){
				soma = soma + t->campo[j][i];
				if (soma == 3){
					printf("\nJogador_O GANHOU!");
					t->acabaJogo=1;
				}else if(soma == 12){
					printf("\nJogador_X GANHOU!");
					t->acabaJogo=1;
				}
			}	
		}
		
		
		soma = t->campo[0][0] + t->campo[1][1] + t->campo[2][2];
		if (soma == 3){
			printf("\nJogador_O GANHOU!");
			t->acabaJogo=1;
		}else if(soma == 12){
			printf("\nJogador_X GANHOU!");
			t->acabaJogo=1;
		}
		soma = 0;
	
		
		soma = t->campo[0][2] + t->campo[1][1] + t->campo[2][0];
		if (soma == 3){
			printf("\nJogador_O GANHOU!");
			t->acabaJogo=1;
		}else if(soma == 12){
			printf("\nJogador_X GANHOU!");
			t->acabaJogo=1;
		}
		
		
		if(t->acabaJogo!=1){
			int qntVazio = 0;
			for(int i=0;i<t->n;i++){
				for(int j = 0; j<t->n;j++){
					if(t->campo[i][j]!=VAZIO){
						qntVazio = qntVazio + 1;
					}
				}
			}
			if(qntVazio==9){
				printf("\nDEU VELHA!");
				t->acabaJogo = 1;
			}
		}
	}






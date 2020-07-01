#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "teclado.h"

int pegar_comando_teclado () {
	
	int comando = getche();
	switch (comando) {
		
		case 72: return CIMA;
		case 80: return BAIXO;
		case 77: return DIREITA;
		case 75: return ESQUERDA;
		case 13: return ENTER;
		default: return DESCONHECIDO;
	}
	
}


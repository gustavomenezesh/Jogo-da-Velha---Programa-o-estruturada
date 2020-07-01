
#define VAZIO 0
#define JOGADOR_O 1
#define JOGADOR_X 4

struct tabuleiro{
	int n;
	int **campo;
	int linhaJogador;
	int colunaJogador;
	int vez;
	int acabaJogo;
};

void aloca_tabuleiro(tabuleiro *t);

void imprime_tabuleiro(tabuleiro *t);

void atualiza_tabuleiro(tabuleiro *t, int comando);

void vitoria(tabuleiro *t);

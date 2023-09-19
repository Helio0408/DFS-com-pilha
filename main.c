#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pilha.h"

int** alloc(int lin, int col);
void mem_free(int lin, int ***labr);
int scan_labr(int** labirinto, int lin, int col, pilha *p, int x, int y);

int** alloc(int lin, int col) {
	int **p = (int**) malloc(lin * sizeof(int*));
	assert(p != NULL);

	for(int i = 0; i < lin; i++){
		p[i] = (int*) malloc(col * sizeof(int));
		assert(p[i] != NULL);
	}

	return p;
}

int scan_labr(int** labirinto, int lin, int col, pilha *p, int x, int y) {
	int cont = 0;


	if(labirinto[y+1][x] != 0 && y+1 < lin) {
		push(p, criar_item((y+1)*1000 + x));
		cont++;
	}
	fprintf(stderr, "até aqui vai 1234\n");
	
	if(labirinto[y][x-1] != 0 && x-1 >= 0) {
		push(p, criar_item((y)*1000 + x-1));
		cont++;
	}
	
	if(labirinto[y-1][x] != 0 && y-1 >= 0) {
		push(p, criar_item((y-1)*1000 + x));
		cont++;
	}
	
	if(labirinto[y][x+1] != 0 && x+1 < col) {
		push(p, criar_item((y)*1000 + x+1));
		cont++;
	}

	return cont;
}

void mem_free(int lin, int ***labr) {
	for(int i = 0; i < lin; i++)
		free((*labr)[i]);
	
	free(*labr);
}

int main(){

	int linha, coluna, **labirinto, x = 0, y = 0, topo, cont;
	pilha *p;
	item *aux;

	p = criar_pilha();

	scanf("%d %d", &linha, &coluna);
	labirinto = alloc(linha, coluna);

	for(int i = 0; i < linha; i++)
		for(int j = 0; j < coluna; j++)
			scanf("%d", &labirinto[i][j]);


	push(p, criar_item(1001));

	do {
		
		pop(p, &aux);
		topo = get_valor(aux);
		y = topo/1000;
		x = topo%1000;

		printf("(%d, %d)", y, x);

		cont = scan_labr(labirinto, linha, coluna, p, x, y);
	}while(labirinto[y][x] != 2);
	
	destruir_pilha(p);
	mem_free(linha, &labirinto);

	return 0;
}
#include "pilha.h"

struct _pilha {
	int topo;
	item *itens[TAM_PILHA];
};

pilha *criar_pilha() {
	pilha *p;
	p = (pilha *)malloc(sizeof(pilha));
	assert(p != NULL);
	p->topo = -1;
	return p;
}

bool esta_vazia(pilha *p) {
	assert(p != NULL);
	
	if(p->topo == -1)
		return true;
	else
		return false;
}

bool esta_cheia(pilha *p) {
	assert(p != NULL);
	
	if(p->topo == TAM_PILHA-1)
		return true;
	else
		return false;
}

bool push(pilha *p, item *x) {
	if(!esta_cheia(p)) {
		p->topo++;
		p->itens[p->topo] = x;
		return true;
	}
	return false;
}

bool pop(pilha *p, item **x) {
	if(!esta_vazia(p)) {
		*x = p->itens[p->topo];
		p->topo--;
		return true;
	}
	return false;
}

bool top(pilha *p, item **x) {
	if(!esta_vazia(p)) {
		*x = p->itens[p->topo];
		return true;
	}
	return false;
}

void esvaziar(pilha *p) {
	assert(p != NULL);
	p->topo = -1;
}

void destruir_pilha(pilha *p) {
	if(p != NULL)
		free(p);
}
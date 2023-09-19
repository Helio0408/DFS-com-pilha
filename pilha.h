#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "item.h"

#define TAM_PILHA 1000

typedef struct _pilha pilha;

pilha *criar_pilha();
bool esta_vazia(pilha *p);
bool esta_cheia(pilha *p);
bool push(pilha *p, item *x);
bool pop(pilha *p, item **x);
bool top(pilha *p, item **x);
void esvaziar(pilha *p);
void destruir_pilha(pilha *p);
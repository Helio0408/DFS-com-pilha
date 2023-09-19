#include "item.h"

struct _item {
	elem valor;
};

item *criar_item(elem x) {
	item *e = (item *)malloc(sizeof(item));
	assert(e != NULL);
	e->valor = x;
	return e;
}

void set_valor(item *e, elem x) {
	assert(e != NULL);
	e->valor = x;
}

elem get_valor(item *e) {
	assert(e != NULL);
	return e->valor;
}

void destruir_item(item *e) {
	if(e != NULL)
		free(e);
}
 
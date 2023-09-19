#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int elem;
typedef struct _item item;

item *criar_item(elem x);
void set_valor(item *e, elem x);
elem get_valor(item *e);
void destruir_item(item *e);
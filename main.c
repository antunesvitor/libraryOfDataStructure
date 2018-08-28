#include <stdio.h>
#include <stdlib.h>
#include "listStruc.h"

int main(int argc, char const *argv[])
{
    int count = 1;
    p_item aux;
    p_list lista = newList();
    insertHeader(lista, newItem(10));
    insertHeader(lista, newItem(15));
    insertHeader(lista, newItem(20));
    insertTail(lista, newItem(10));
    insertHeader(lista, newItem(10));
    insertHeader(lista, newItem(25));
    insertHeader(lista, newItem(10));
    insertTail(lista, newItem(5));
    insertTail(lista, newItem(0));
    insertTail(lista, newItem(10));
    removeHeader(lista);
    removeTail(lista);
    
    for(aux=lista->first; aux!=NULL; aux= aux->next)
    {
        if(count == 100) return 0;
        printf("No. %d: %d\n", count++, aux->valor);
    }

    removeLastByValue(lista, 10);

    count = 1;
    for(aux=lista->first; aux!=NULL; aux= aux->next)
    {
        if(count == 100) return 0;
        printf("No. %d: %d\n", count++, aux->valor);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "listStruc.h"

int main(int argc, char const *argv[])
{
    int count = 1;
    p_item aux;
    p_list lista1 = newList();
    p_list lista2 = newList();
    p_list lista3;
    insertTail(lista1, newItem(1));
    insertTail(lista1, newItem(3));
    insertTail(lista1, newItem(5));
    insertTail(lista1, newItem(7));
    insertTail(lista1, newItem(9));
    insertTail(lista1, newItem(11));
    insertTail(lista1, newItem(13));
    insertTail(lista1, newItem(15));


    insertTail(lista2, newItem(2));
    insertTail(lista2, newItem(4));
    insertTail(lista2, newItem(6));
    insertTail(lista2, newItem(8));
    insertTail(lista2, newItem(10));
    insertTail(lista2, newItem(12));
    insertTail(lista2, newItem(14)); 

    for(aux=lista1->first; aux!=NULL; aux= aux->next)
    {
        if(count == 100) return 0;
        printf("No. %d: %d\n", count++, aux->valor);
    }

    for(aux=lista2->first, count = 1; aux!=NULL; aux= aux->next)
    {
        if(count == 100) return 0;
        printf("No. %d: %d\n", count++, aux->valor);
    }

    lista3 = merge(lista1, lista2);
        for(aux=lista3->first, count = 1; aux!=NULL; aux= aux->next)
    {
        if(count == 100) return 0;
        printf("No. %d: %d\n", count++, aux->valor);
    }

    return 0;
}

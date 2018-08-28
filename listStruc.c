#include <stdio.h>
#include <stdlib.h>
#include "listStruc.h"

p_list newList()
{
    p_list list = (p_list) malloc(sizeof(struct list));
    if(list == NULL)
    {
        fprintf(stderr, "Could not allocate memory.\n");
        return NULL;
    }
    list->first = NULL;
    list->quant = 0;
    return list;
}

p_item newItem(int value)
{
    p_item newItem = (p_item) malloc(sizeof(struct item));
    if(newItem == NULL)
    {
        printf("Could not allocate memory\n");
        return NULL;
    }
    newItem->valor = value;
    newItem->next = NULL;
    return newItem;
}

void insertHeader(p_list list, p_item item)
{
    item->next = list->first;
    list->first = item;
}

void insertTail(p_list list, p_item item)
{
    p_item aux;
    for(aux = list->first; aux->next!=NULL; aux = aux->next);
    aux->next = item;
}

void removeHeader(p_list list)
{
    p_item aux = list->first->next;
    free(list->first);
    list->first = aux;
}

void removeTail(p_list list)
{
    p_item aux = NULL, ant = NULL;
    for(aux = list->first; aux->next != NULL;aux = aux->next)
    {
        ant = aux;
    }
    ant-> next = NULL;
    free(aux);
}

p_item removeFirstByValue(p_list list, int value)
{
    p_item aux = NULL, ant = NULL;
    for(aux = list->first; aux->valor != value || aux == NULL; aux = aux->next)
    {
        ant = aux;
    }
    if(aux == NULL)
    {
        return NULL;
    }
    ant->next = aux->next;
    return aux;
}

void removeLastByValue(p_list list, int value)
{
    p_item aux = NULL, find = NULL, ant = NULL, antFind = NULL;
    for(aux = list->first; aux->next != NULL; aux = aux->next)
    {
        if(aux->valor == value)
        {
            printf("anterior: %d // num para encontrar:%d\n", ant->valor, value);
            antFind = ant;
            find = aux;
        }
        ant = aux;
    }
    if(aux->valor == value)         //if the last to find is also the last in the list
    {
        antFind = ant;
        find = aux;
    }
    antFind->next = find->next;
    free(find);
}


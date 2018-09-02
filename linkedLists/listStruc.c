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
    p_item aux,ant;
    aux = list->first;
    if(aux == NULL)             //the list is empty
    {
        list->first = item;
        return;
    }
    while(aux->next!=NULL)
    {
        aux = aux->next;
    }
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

void removeRepetitions(p_list list)
{
    p_item aux1, aux2, liberator, ant;
    for(aux1 = list->first; aux1->next != NULL; aux1 = aux1->next)
    {
        for(aux2 = aux1->next; aux2 != NULL;)
        {
            if(aux1->valor == aux2->valor)
            {
                ant->next = aux2->next;
                liberator =  aux2;
                ant = aux2;
                aux2 = aux2->next;
                free(liberator);
            }
            else
            {
                ant = aux2;
                aux2 = aux2->next;
            }
        }
    }
}


p_list merge(p_list L, p_list R)
{
    p_item lowest, p_L, p_R;
    p_list mergedList = newList();
    for(p_L = L->first, p_R = R->first;
        p_L != NULL && p_R != NULL;)
    {
        if(p_L->valor < p_R->valor)
        {
            lowest = newItem(p_L->valor);
            p_L = p_L->next;
        }
        else
        {
            lowest = newItem(p_R->valor);
            p_R = p_R->next;
        }
        insertTail(mergedList, lowest);
    }
    if(p_L == NULL)
    {
        while(p_R !=NULL)
        {
            insertTail(mergedList, p_R);
            p_R = p_R->next;
        }
    }
    if(p_R == NULL)
    {
        while(p_L != NULL)
        {
            insertTail(mergedList, p_L);
            p_L = p_L->next;
        }
    }

    return mergedList;
}

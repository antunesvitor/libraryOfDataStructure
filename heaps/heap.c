#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

p_heap newMaxHeap(int capacity)
{
    p_heap H = malloc(sizeof(struct heap));
    if(H==NULL)
    {
        fprintf(stderr,"It was not possible to allocate memory.\n");
        return NULL;
    }
    /*Default capacity*/
    H->capacity = capacity;
    H->arr = malloc(sizeof(int) * H->capacity);
    H->size = 0;
    H->max = true;
    return  H;    
}

p_heap newMinHeap(int capacity)
{
    p_heap H = malloc(sizeof(struct heap));
    if(H == NULL)
    {
        fprintf(stderr,"It was not possible to allocate memory.\n");
        return NULL;
    }
    /*Default Capacity*/
    H->capacity = capacity;
    H->arr = malloc(sizeof(int) * H->capacity);
    H->size = 0;
    H->max = false;
    return H;
}

void increaseCapacity(p_heap h)
{
    int current = h->capacity;
    int *aux = malloc(sizeof(int) * h->capacity);
    int i;
    for(i = 0; i < h->capacity; i++)
    {
        aux[i] = h->arr[i];
    }
    free(h->arr);
    h->capacity *= 2;
    h->arr = malloc(sizeof(int) * h->capacity);
        for(i = 0; i < h->capacity/2; i++)
    {
        h->arr[i] = aux[i];
    }
}

void swap(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

/*returns the index of a parent of a given index*/ 
int parent(int index) { return (index-1)/2;}

/*returns the index of a right element of a given index*/
int right(int index) { return 2*index + 2; }

/*returns the index of a left element of a given index*/
int left(int index) { return 2*index + 1; }

/*The method below was based on the one written on https://www.geeksforgeeks.org/binary-heap/ */
void insert(p_heap heap, int value)
{
    if(heap->capacity == heap->size)
    {
        printf("Aqui o heap se expande\n");
        increaseCapacity(heap);
    }

    heap->size++;
    int i = heap->size - 1;
    heap->arr[i] = value;

    if(heap->max)
    {
       while(i != 0 && heap->arr[parent(i)] < heap->arr[i])
       {
           swap(&heap->arr[i], &heap->arr[parent(i)]);
           i = parent(i);
       }
    }
    else
    {
       while(i != 0 && heap->arr[parent(i)] > heap->arr[i])
       {
           swap(&heap->arr[i], &heap->arr[parent(i)]);
           i = parent(i);
       }
    }
}

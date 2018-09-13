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
int parent(int index) 
{ return (index-1)/2;}

/*returns the index of a right element of a given index*/
int right(int index) { return 2*index + 2; }

/*returns the index of a left element of a given index*/
int left(int index) { return 2*index + 1; }

/*return true if a index is a leaf, false if it is not*/
boolean isLeaf(p_heap heap, int index) 
{
    if(left(index) > (heap->size - 1) && right(index) > (heap->size - 1) )
    {
        return true;
    }
    else return false;
}

/*returns the index of the smallest child of a given index in a heap*/
int minIndex(p_heap heap,int index)
{
    if(isLeaf(heap, index)) return -1;
    int L = left(index);
    int R = right(index);
    if(L >= heap->size) return R;
    if(R >= heap->size) return L;
    if(L < heap->size && R < heap->size) 
        return (heap->arr[L] < heap->arr[R])? L : R;
}

/*returns the index of the greatest child of a given index on a heap,
    return negative if a node doesn't have any child node*/
int maxIndex(p_heap heap,int index)
{
    if(isLeaf(heap, index)) return -1;   

    int L = left(index);
    int R = right(index);
    /*below are two conditionals in case the node has only one child, probably the first conditional never will happen*/
    if(L >= heap->size) return R;           
    if(R >= heap->size) return L;
    /*below the conditional that the returns the most valuable child in case the given index has two nodes as childs*/
    if(L < heap->size && R < heap->size) 
        return (heap->arr[L] > heap->arr[R])? L : R;
}

void fixMaxHeap( p_heap heap, int index)
{
    int maxChild;
    for( maxChild = maxIndex(heap, index);
            heap->arr[index] < heap->arr[maxChild] && maxChild > 0;
            index = maxChild, maxChild = maxIndex(heap, index))
    {
        swap(&heap->arr[index], &heap->arr[maxChild]); 
    }
}

void fixMinHeap(p_heap heap, int index)
{
    int minChild;
    for( minChild = minIndex(heap, index);
            heap->arr[index] > heap->arr[minChild] && minChild > 0;
            index = minChild, minChild = minIndex(heap, minChild) )
    {
        swap(&heap->arr[index], &heap->arr[minChild]);
    }
}

void fixHeap(p_heap heap, int index)
{
    if(heap->max) fixMaxHeap(heap, index);
    else fixMinHeap(heap, index);
}


/*The method below was based on the one written on https://www.geeksforgeeks.org/binary-heap/ */
void insert(p_heap heap, int value)
{
    if(heap->capacity == heap->size)
    {
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

boolean checkNodeMin(p_heap heap,int index)
{
    if(right(index) < heap->size)
    {
        if(heap->arr[right(index)] < heap->arr[index]) return false;
    }
    if(left(index) < heap->size)
    {
        if(heap->arr[left(index)] < heap->arr[index]) return false;
    }
    if(right(index) > heap->size && left(index) > heap->size)
    {
        return true;
    }
    return (checkNodeMin( heap, right(index)) && checkNodeMin( heap, left(index)));
}

boolean checkNodeMax(p_heap heap,int index)
{
    if(right(index) < heap->size)
    {
        if(heap->arr[right(index)] > heap->arr[index]) return false;
    }
    if(left(index) < heap->size)
    {
        if(heap->arr[left(index)] > heap->arr[index]) return false;
    }
    if(right(index) > heap->size && left(index) > heap->size)
    {
        return true;
    }
    return (checkNodeMax( heap, right(index)) && checkNodeMax( heap, left(index)));
}

boolean isMinHeap(p_heap heap)
{
    return checkNodeMin(heap, 0);
}

boolean isMaxHeap(p_heap heap)
{
    return checkNodeMax(heap, 0);
}

p_heap heapfyArrayToMaxHeap(int* arr)
{
    return NULL;
}

p_heap heapfyArrayToMinHeap(int* arr)
{
    return NULL;
}

void deleteFrom(p_heap heap, int index)
{
    int lastOne = heap->size - 1;

    if(heap->size - 1 != index ){
        swap(&heap->arr[index], &heap->arr[lastOne]);
    }
    heap->size --;
    //else return;
    fixHeap(heap, 0);
}


/*Proximas etapas:
>>>Consertar o problema do fixHeap, não esta consertando em todos os casos 
por exemplo no max Heap baixo:
                        16
                  10           15
              8       9    12       13

Se decidirmos remover o nó 10:
                  temos:                                       deveriamos ter:
                    16                                                16
            10              15                                 13           15
        8       13      12                                  8     10     12
        
    O problema ocorre mesmo que passamos o indice zero no metodo fixHeap,
    que supostamente deveria consertar toda a subarvore do indice
*/
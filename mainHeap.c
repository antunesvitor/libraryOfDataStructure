#include <stdio.h>
#include <stdlib.h>
#include "heaps/heap.h"


int main(int argc, char const *argv[])
{
    int i;
    p_heap minHeap = newMinHeap(5);
    insert(minHeap, 8);
    insert(minHeap, 11);
    insert(minHeap, 12);
    insert(minHeap, 14);
    insert(minHeap, 15);
    insert(minHeap, 16);
    insert(minHeap, 9);

    p_heap maxHeap = newMaxHeap(5);
    insert(maxHeap, 8);
    insert(maxHeap, 11);
    insert(maxHeap, 12);
    insert(maxHeap, 14);
    insert(maxHeap, 15);
    insert(maxHeap, 16);
    insert(maxHeap, 9);

    printf("for minHeap:\n");
    for(i = 0; i < minHeap->size; i++)
    {
        printf("%d ", minHeap->arr[i]);
    }
    printf("\n");
    if(isMinHeap(minHeap)) printf("it is a minimum heap\n");
    if(!isMaxHeap(minHeap)) printf("it isnt a max heap\n");

    printf("\n\nfor maxHeap:\n");
    for(i = 0; i < maxHeap->size; i++)
    {
        printf("%d ", maxHeap->arr[i]);
    }
    printf("\n");
    if(!isMinHeap(maxHeap)) printf("it isnt a minimum heap\n");
    if(isMaxHeap(maxHeap)) printf("it is a max heap\n");
    return 0;
}

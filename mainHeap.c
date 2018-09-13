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
    insert(maxHeap, 16);
    insert(maxHeap, 10);
    insert(maxHeap, 15);
    insert(maxHeap, 8);
    insert(maxHeap, 9);
    insert(maxHeap, 12);
    insert(maxHeap, 13);

    printf("for minHeap:\n");
    for(i = 0; i < minHeap->size; i++)
    {
        printf("%d ", minHeap->arr[i]);
    }
    printf("\n");

    printf("\n\nfor maxHeap:\n");
    for(i = 0; i < maxHeap->size; i++)
    {
        printf("%d ", maxHeap->arr[i]);
    }
    printf("\n");

    deleteFrom(maxHeap, 4);
    for(i = 0; i < maxHeap->size; i++)
    {
        printf("%d ", maxHeap->arr[i]);
    }
    printf("\n");
    deleteFrom(minHeap, 0);
    for(i = 0; i < minHeap->size; i++)
    {
        printf("%d ", minHeap->arr[i]);
    }
    return 0;
}

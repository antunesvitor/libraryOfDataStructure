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



    printf("capacity: %d\n", minHeap->capacity);
    for(i = 0; i < minHeap->size; i++)
    {
        printf("%d ", minHeap->arr[i]);
    }
    return 0;
}

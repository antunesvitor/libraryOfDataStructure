#ifndef heapStructure
#define heapStructure
#define true 1
#define false 0 

typedef int boolean;
typedef struct heap* p_heap;
struct heap 
{
    int capacity;
    int size;
    int *arr;
    boolean max;
};

p_heap newMinHeap(int);
p_heap newMaxHeap(int);
void insert(p_heap, int);
int left(int);
int right(int); 
void swap(int*,int*);
boolean isMinHeap(p_heap);
boolean isMaxHeap(p_heap);
p_heap heapfyArrayToMaxHeap(int*);
p_heap heapfyArrayToMinHeap(int*);
void deleteFrom(p_heap, int);
boolean isLeaf(p_heap, int);
int minIndex(p_heap, int);
int maxIndex(p_heap, int);
void fixHeap(p_heap, int);
#endif
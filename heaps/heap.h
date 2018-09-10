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

#endif
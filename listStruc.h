#ifndef ListStructures
#define ListStructures

typedef struct item* p_item;
typedef struct list *p_list;
struct item{
    int valor;
    p_item next;
};


struct list{
    int quant;
    p_item first;
};
int area(int h, int l);
void sortList();
void insertTail(p_list list, p_item item);
void insertHeader(p_list list, p_item item);
p_list newList();
p_item newItem(int value);
void removeTail(p_list list);
void removeHeader(p_list lista);
p_item removeFirstByValue(p_list lista, int value);
void removeLastByValue(p_list lista, int value);
void removeAllByValue(p_list lista, int value);
p_list extractFromListByValues(int* values);
void removeRepetitions(p_list list);
p_list merge(p_list L, p_list R);
#endif
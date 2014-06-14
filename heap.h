//heap.h
//Potato Industries Inc. (C) 2014-2014
//Implementation of an implicit binary min-heap/max-heap in C
//DISCLAIMER:
//Code is not guaraunteed to work as expected or even compile :>
enum HeapType{
    MIN_HEAP,MAX_HEAP
};
#define HEAP_DATA_TYPE unsigned int
struct HeapNode{
    HEAP_DATA_TYPE data;
    int cost;
}
struct Heap{
    enum HeapType type;
    struct HeapNode* heapData;
    unsigned int num,cap;
}
//private methods:
//void heapSwapNodes(struct Heap* heap,unsigned int aIndex,unsigned int bIndex);
//unsigned int heapSafeCompare(struct Heap* heap,unsigned int curIndex);

//heap methods:
struct Heap* genHeap(enum HeapType type);
void heapInsert(struct Heap* heap,HEAP_DATA_TYPE data,int cost);
void heapRemove(struct Heap* heap);

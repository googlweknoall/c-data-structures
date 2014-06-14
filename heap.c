//heap.c
//Potato Industries Inc. (C) 2014-2014
//Implementation of an implicit binary min-heap/max-heap in C
//DISCLAIMER:
//Code is not guaraunteed to work as expected or even compile :>
enum HeapType{
    MIN_HEAP,MAX_HEAP
};
//the desired key data type in each [key,priority] pair of the heap
#define HEAP_DATA_TYPE unsigned int //put your desired node type here and run this .c file through the preprocessor
struct HeapNode{
    HEAP_DATA_TYPE data;
    int cost;
}
struct Heap{
    enum HeapType type;
    struct HeapNode* heapData;
    unsigned int num,cap;
}
struct Heap* genHeap(enum HeapType type){
    struct Heap* heap=(struct Heap*)malloc(sizeof(struct Heap));
    heap->type=type;
    heap->heapData=NULL;
    heap->num=0;
    heap->cap=0;
}

void heapSwapNodes(struct Heap* heap,unsigned int aIndex,unsigned int bIndex){
    struct HeapNode* a=&(heap->heapData[aIndex]),*b=&(heap->heapData[bIndex]);
    HEAP_DATA_TYPE tempData=a->data;
    int tempCost=a->cost;
    a->data=b->data;
    a->cost=b->cost;
    b->data=tempData;
    b->cost=tempCost;
}

void heapInsert(struct Heap* heap,HEAP_DATA_TYPE data,int cost){
    if(heap->num==heap->cap){
        heap->cap=heap->cap*2+1;
        struct HeapNode* res=(struct HeapNode*)realloc(heap->heapData,sizeof(struct HeapNode)*heap->cap);
        assert(res!=NULL);
        heap->heapData=res;
    }
    res->heapData[heap->num].data=data;
    res->heapData[heap->num].cost=cost;
    if(!heap->num){ //there is only one node in the heap, attempting to compute parent's index will result in unsigned int underflow
        ++heap->num;
        return;
    }
    unsigned int curIndex=heap->num;
    unsigned int parentIndex=(curIndex-1)/2;
    if(heap->type==MIN_HEAP){
        while(curIndex&&heap->heapData[parentIndex].cost<heap->heapData[curIndex].cost){
            heapSwapNodes(heap,curIndex,parentIndex)
            curIndex=parentIndex;
            parentIndex=(curIndex-1)/2;
        }
    }else if(heap->type==MAX_HEAP){
        while(curIndex&&heap->heapData[parentIndex].cost>heap->heapData[curIndex].cost){
            heapSwapNodes(heap,curIndex,parentIndex)
            curIndex=parentIndex;
            parentIndex=(curIndex-1)/2;
        }
    }else{
        fprintf(stderr,"Unknown heap type at heapInsert(), line %u\n",__LINE__);
        assert(heap->type==MIN_HEAP||heap->type==MAX_HEAP);
    }
    ++heap->num;
}

unsigned int heapSafeCompare(struct Heap* heap,unsigned int curIndex){
    //1 2 3
    //0 1 2
    unsigned int leftIndex=curIndex*2+1,rightIndex=leftIndex+1;
    unsigned int curCost=heap->heapData[curIndex],leftCost,rightCost;
    if(heap->num<leftIndex){ //current node does not have any children
        return curIndex; //current node by necessity does not invalidate heap
    }else if(heap->num<=rightIndex){ //current node only has a left child
        if(heap->type==MIN_HEAP){
            if(curCost>leftCost) return leftIndex;
            else return curIndex;
        }else if(heap->type==MAX_HEAP){
            if(curCost<leftCost) return leftIndex;
            else return curIndex;
        }else{
            fprintf(stderr,"Unknown heap type at heapInsert(), line %u\n",__LINE__);
            assert(heap->type==MIN_HEAP||heap->type==MAX_HEAP);
        }
    }else{
        leftCost=heap->heapData[leftIndex];
        rightCost=heap->heapData[rightIndex];
        if(heap->type==MIN_HEAP){
            if(curCost>leftCost||curCost>rightCost){
                if(leftCost<rightCost) return leftIndex;
                else return rightIndex;
            }
            else return curIndex;
        }else if(heap->type==MAX_HEAP){
            if(curCost<leftCost||curCost<rightCost){
                if(leftCost>rightCost) return leftIndex;
                else return rightIndex;
            }
            else return curIndex;
        }else{
            fprintf(stderr,"Unknown heap type at heapInsert(), line %u\n",__LINE__);
            assert(heap->type==MIN_HEAP||heap->type==MAX_HEAP);
        }
    }
}
//Removes the first node in the heap while ensuring that the heap continues to be valid
void heapRemove(struct Heap* heap){
    if(heap->num){
        --heap->num;
        heap->heapData[heap->num].data=(HEAP_DATA_TYPE)0;
        heap->heapData[heap->num].cost=(HEAP_DATA_TYPE)0;
        unsigned int curIndex=0,swapIndex=heapSafeCompare(heap,curIndex);
        while(curIndex!=swapIndex){
            heapSwapNodes(heap,curIndex,swapIndex)
            swapIndex=curIndex;
        }
    }else{
        fprintf(stderr,"Attempt to pop element off empty heap at heapRemove(), line %u\n",__LINE__);
        assert(heap->num>0);
    }
}

void destroyHeap(struct Heap* heap){
    free(heap->heapData);
    free(heap);
}

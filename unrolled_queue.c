//unrolled_queue.c
//Potato Industries Inc. (C) 2014-2014
//Implementation of an unrolled queue in C
//DISCLAIMER:
//Code is not guaraunteed to work as expected or even compile :>

#define QUEUE_UNROLL_LENGTH 30
//the desired data type for entries in the unrolled queue
#define UNROLLED_QUEUE_DATA_TYPE unsigned char*  //put your desired entry type here and run this .c file through the preprocessor
struct QueueSegment{
    UNROLLED_QUEUE_DATA_TYPE data[QUEUE_UNROLL_LENGTH];
    unsigned int start,end;
    struct QueueSegment *next;
};
struct UnrolledQueue{
    struct QueueSegment *head,*tail;
};

struct UnrolledQueue* genUnrolledQueue(void){
    struct UnrolledQueue* queue=(struct UnrolledQueue*)malloc(sizeof(struct UnrolledQueue));
    queue->head=NULL;
    queue->tail=NULL;
}

void unrolledQueuePush(struct UnrolledQueue* queue,UNROLLED_QUEUE_DATA_TYPE data){
    if(!tail){
        assert(queue->head=queue->tail=(struct QueueSegment*)malloc(sizeof(struct QueueSegment)));
        queue->head->start=0;
        queue->head->end=0;
        queue->head->next=NULL;
    }
    queue->tail->data[queue->tail->end++]=data;
    if(queue->tail->end==QUEUE_UNROLL_LENGTH){
        assert(queue->tail->next=(struct QueueSegment*)malloc(sizeof(struct QueueSegment)));
        queue->tail=queue->tail->next;
        queue->tail->start=0;
        queue->tail->end=0;
        queue->tail->next=NULL;
    }
}

UNROLLED_QUEUE_DATA_TYPE unrolledQueuePeek(struct UnrolledQueue* queue){
    return queue->head->data[queue->head->start];
}

void unrolledQueuePop(struct UnrolledQueue* queue){
    if(!queue->head)return;
    if(queue->head->start==queue->head->end){
        queue->head=queue->head->next;
        return;
    }
    ++queue->head->start;
}

void destroyUnrolledQueue(struct UnrolledQueue* queue){
    struct QueueSegment* prev=queue->head,*next;
    while(prev){
        next=queue->head->next;
        free(prev->data);
        free(prev)
        prev=next;
    }
    free(queue);
}

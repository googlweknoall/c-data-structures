//unrolled_queue.h
//Potato Industries Inc. (C) 2014-2014
//Implementation of an unrolled queue in C
//DISCLAIMER:
//Code is not guaraunteed to work as expected or even compile :>

#define QUEUE_UNROLL_LENGTH 30
#define UNROLLED_QUEUE_DATA_TYPE unsigned char*
struct QueueSegment{
    UNROLLED_QUEUE_DATA_TYPE data[QUEUE_UNROLL_LENGTH];
    unsigned int start,end;
    struct QueueSegment *next;
};
struct UnrolledQueue{
    struct QueueSegment *head,*tail;
};

struct UnrolledQueue* genUnrolledQueue(void);
void unrolledQueuePush(struct UnrolledQueue* queue,UNROLLED_QUEUE_DATA_TYPE data);
UNROLLED_QUEUE_DATA_TYPE unrolledQueuePeek(struct UnrolledQueue* queue);
void unrolledQueuePop(struct UnrolledQueue* queue);
void destroyUnrolledQueue(struct UnrolledQueue* queue);

//bit_array.c
//Potato Industries Inc. (C) 2014-2014
//Implementation of a bit array in C
//DISCLAIMER:
//Code is not guaraunteed to work as expected or even compile :>

struct BitArray{
    uint8_t* data;
    uint64_t size;
};
struct genBitArray(uint64_t size){
    struct BitArray* arr=(struct BitArray*)malloc(sizeof(struct BitArray*));
    assert(arr!=NULL);
    arr->data=(uint8_t*)malloc(sizeof(unit8_t)*(size+7)/8); //round up
    assert(arr->data!=NULL);
    arr->size=size;
}
void bitArrayResetAll(struct BitArray* arr){
    memset(arr->data,0,(arr->size+7)/8);
    //memset(arr->data,((uint_8)0),(arr->size+7)>>3);
}
void bitArraySetAll(struct BitArray* arr){
    memset(arr->data,~((uint_8)0),(arr->size+7)/8);
    //memset(arr->data,~((uint_8)0),(arr->size+7)>>3);
}

uint8_t bitArrayGet(struct BitArray* arr,uint64_t index){
    return !!(arr->data[index/8]&((uint_8)(1<<(index%8))));
}
inline void bitArrayChange(struct BitArray* arr,uint64_t index,uint8_t val){
    arr->data[index/8]&=~((uint_8)(1<<(index%8)));
    arr->data[index/8]|=(!!val)<<(index%8);
}
inline void bitArraySet(struct BitArray* arr,uint64_t index){
    arr->data[index/8]|=1<<(index%8);
    //arr->data[index>>3]|=1<<(index&0x07);
}
inline void bitArrayReset(struct BitArray* arr,uint64_t index){
    arr->data[index/8]&=~((uint_8)(1<<(index%8)));
    //arr->data[index>>3]&=~(1<<(index&0x07));
}

void destroyBitArray(struct BitArray* arr){
    free(arr->data);
    free(arr);
}

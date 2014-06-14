//bit_array.h
//Potato Industries Inc. (C) 2014-2014
//Implementation of a bit array in C
//DISCLAIMER:
//Code is not guaraunteed to work as expected or even compile :>

struct BitArray{
    uint8_t* data;
    uint64_t size;
};
struct genBitArray(uint64_t size);
void bitArrayResetAll(struct BitArray* arr);
void bitArraySetAll(struct BitArray* arr);
uint8_t bitArrayGet(struct BitArray* arr,uint64_t index);
inline void bitArrayChange(struct BitArray* arr,uint64_t index,uint8_t val);
inline void bitArraySet(struct BitArray* arr,uint64_t index);
inline void bitArrayReset(struct BitArray* arr,uint64_t index);
void destroyBitArray(struct BitArray* arr);

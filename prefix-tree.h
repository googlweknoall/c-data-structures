//prefix-tree.h
//Potato Industries Inc. (C) 2014-2014
//Implementation of a prefix tree in C
//DISCLAIMER:
//Code is not guaraunteed to work as expected or even compile :>

#define PREFIX_TREE_NODE_TYPE unsigned char
#define PREFIX_TREE_PAYLOAD_TYPE unsigned int
struct PrefixTree{
    PREFIX_TREE_NODE_TYPE identifier;
    struct PrefixTree* children;
    unsigned int num,cap;
    
    unsigned int leaf:1;
    PREFIX_TREE_PAYLOAD_TYPE payload;
};
struct PrefixTree* genPrefixTree(void);
void prefixTreeInsert(struct PrefixTree* tree,const PREFIX_TREE_NODE_TYPE arr[],PREFIX_TREE_PAYLOAD_TYPE payload);
unsigned char prefixTreeExists(struct PrefixTree* tree,const PREFIX_TREE_NODE_TYPE arr[]);
PREFIX_TREE_PAYLOAD_TYPE prefixTreeIndex(struct PrefixTree* tree,const PREFIX_TREE_NODE_TYPE arr[]);
//TO BE IMPLEMENTED: void prefixTreeRemove(struct PrefixTree* tree,const PREFIX_TREE_NODE_TYPE arr[]);

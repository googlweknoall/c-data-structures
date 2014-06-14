//prefix-tree.c
//Potato Industries Inc. (C) 2014-2014
//Implementation of a prefix tree in C
//DISCLAIMER:
//Code is not guaraunteed to work as expected or even compile :>

//the desired key data type in each digit of the string composed from the simple path from the root of the prefix tree to any node in the prefix tree
#define PREFIX_TREE_NODE_TYPE unsigned char //put your desired node type here and run this .c file through the preprocessor
//the desired value data type for indexing the prefix tree with a string composed of a PREFIX_TREE_NODE_TYPE array of nodes
#define PREFIX_TREE_PAYLOAD_TYPE unsigned int //put your desired node type here and run this .c file through the preprocessor
struct PrefixTree{
    PREFIX_TREE_NODE_TYPE identifier;
    struct PrefixTree* children;
    unsigned int num,cap;
    
    unsigned int leaf:1;
    PREFIX_TREE_PAYLOAD_TYPE payload;
};
struct PrefixTree* genPrefixTree(void){
    struct PrefixTree* tree=(struct PrefixTree*)malloc(sizeof(struct PrefixTree));
    tree->identifier=0;
    tree->children=NULL;
    tree->num=0;
    tree->cap=0;
    tree->leaf=0;
    tree->payload=0;
    return tree;
}
//Insert an element indexed by an array of PREFIX_TREE_NODE_TYPE
//The end of the array should be indicated with a NULL
void prefixTreeInsert(struct PrefixTree* tree,const PREFIX_TREE_NODE_TYPE arr[],PREFIX_TREE_PAYLOAD_TYPE payload){
    while(*arr){
        unsigned int i,flag=1;
        for(i=0;i<tree->num;++i){
            if(tree->children[i].identifier==*arr){
                tree=&(tree->children[i]);
                ++arr;
                break;
            }
        }
        if(flag){
            if(tree->num==tree->cap){
                tree->cap+=5;
                struct PrefixTree* res=(struct PrefixTree*)realloc(tree->children,sizeof(struct PrefixTree)*tree->cap);
                assert(res!=NULL);
                tree->children=res;
            }
            struct PrefixTree* child=&(tree->children[tree->num]);
            child.identifier=*arr;
            child.children=NULL;
            child.num=0;
            child.cap=0;
            child.leaf=0;
            child.payload=0;
            ++tree->num;
            tree=child;
            ++arr;
        }
    }
    tree->leaf=1;
    tree->payload=payload;
}

//Index an element of type PREFIX_TREE_PAYLOAD_TYPE from the prefix tree using the key formed by an array of PREFIX_TREE_NODE_TYPE
//Returns if the element exists
unsigned char prefixTreeExists(struct PrefixTree* tree,const PREFIX_TREE_NODE_TYPE arr[]){
    while(*arr){
        unsigned int i,flag=1;
        for(i=0;i<tree->num;++i){
            if(tree->children[i].identifier==*arr){
                tree=&(tree->children[i]);
                ++arr;
                break;
            }
        }
        if(flag) return 0; //there is no such element in the prefix tree
    }
    return 1;
}

//Index an element of type PREFIX_TREE_PAYLOAD_TYPE from the prefix tree using the key formed by an array of PREFIX_TREE_NODE_TYPE
PREFIX_TREE_PAYLOAD_TYPE prefixTreeIndex(struct PrefixTree* tree,const PREFIX_TREE_NODE_TYPE arr[]){
    while(*arr){
        unsigned int i,flag=1;
        for(i=0;i<tree->num;++i){
            if(tree->children[i].identifier==*arr){
                tree=&(tree->children[i]);
                ++arr;
                break;
            }
        }
        if(flag){ //there is no such element in the prefix tree
            return NULL;
        }
    }
    return tree->payload;
}

//TO BE IMPLEMENTED: void prefixTreeRemove(struct PrefixTree* tree,const PREFIX_TREE_NODE_TYPE arr[]);

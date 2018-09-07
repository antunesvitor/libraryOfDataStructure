#ifndef treesStructures
#define treesStructures
#define true 1
#define false 0;

typedef int boolean;

typedef struct node* p_node;
struct node {
    int value;
    p_node parent;
    p_node right;
    p_node left;
};

typedef struct tree* p_tree;
struct tree{
    p_node root;
    int height;
};

p_tree newBST();
p_node newNode(int value);
boolean isLeaf(p_node);
void insertTree(p_tree, p_node);
void removeFromTree(p_tree, p_node);
p_tree toSearchingTree(p_tree);
void rightRotate(p_tree,p_node);
void leftRotate(p_tree,p_node);
void fixTree(p_tree);
boolean isAVL(p_tree);
void printTree(p_tree);

#endif
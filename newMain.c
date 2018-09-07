#include <stdio.h>
#include <stdlib.h>
#include "trees/tree.h"

int main(int argc, char const *argv[])
{

    /*printf("Current height of my tree is: %d\n", myTree->height);
    printf("Current height of my heap is: %d\n", myHeap->height);
    printf("\n ================================ \n\n");
    p_node node = newNode(10);
    printf("The value of the node is %d\n", node->value);
    printf("The node is a leaf? %d\n", isLeaf(node));
    p_node node2 = newNode(1);
    printf("The node2 is a leaf? %d\n", isLeaf(node));
    node->right = node2;
    printf("The node is a leaf? %d\n", isLeaf(node));

    printf("\n ================================ \n\n");*/



    p_tree myTree = newBST();
    insertTree(myTree, newNode(5));
    insertTree(myTree, newNode(7));
    insertTree(myTree, newNode(3));
    insertTree(myTree, newNode(4));
    insertTree(myTree, newNode(2));
    insertTree(myTree, newNode(6));
    insertTree(myTree, newNode(8));
    insertTree(myTree, newNode(9));

    printTree(myTree);
    return 0;
}

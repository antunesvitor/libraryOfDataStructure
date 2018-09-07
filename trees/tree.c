#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#define count 5


int  max(int a, int b)
{
    if(a > b){
        return a;
    }
    else return b;
}

int getHeight(p_node node)
{
    if (node == NULL)
    {
        return -1;
    }
    return 1 + max(getHeight(node->right), getHeight(node->left));
}

p_tree newBST()
{
    p_tree T = malloc(sizeof(struct tree));
    if (T == NULL)
    {
        fprintf(stderr, "It was not possible to allocate memory.");
        return NULL;
    }

    T->root = NULL;
    T->height = 0;
    printf("BST successfully created!\n");
    return T;
}

p_node newNode(int value)
{
    p_node node = malloc (sizeof(struct node));
    if( node == NULL)
    {
        fprintf(stderr, "Could not allocate memory.\n");
        return NULL;
    }
    node->value = value;
    node->parent = NULL;
    node->right = NULL;
    node->left = NULL;
    return node;
}

void insertTree(p_tree t, p_node node)
{
    p_node aux, ant;
    if(t->root == NULL)
    {
        t->root = node;
        return;
    }

    for(aux = t->root; aux != NULL;)
    {
        ant = aux;
        if(aux->value > node->value)
        {
            aux =  aux->left;
        }
        else
        {
            aux = aux->right;
        }
    }
    if (ant->value > node->value)
    {
        ant->left = node;
    }
    else
    {
        ant->right = node;
    }
    node->parent = ant;
    t->height = getHeight(t->root);
    return;
}


boolean isLeaf(p_node node)
{
    if(node->left == NULL && node->right == NULL)
    {
        return true;
    }
    else return false;
}


void printNode(p_node node, int space)
{
    int i;
    space += count;
    if(node == NULL){
        for(i = count; i < space; i++) printf(" ");
        printf("NULL");
        return;
    }

    printNode(node->right, space);

    printf("\n");
    for(i = count; i < space; i++) printf(" ");
    printf("%d\n", node->value);

    printNode(node->left, space);

}

void printTree(p_tree t)
{
    if(t->root != NULL) 
        printNode(t->root, 0);
    else
    {
        printf("The tree is not valid.\n");
    }
}


/*Toaca Andreia - 311CC*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
typedef struct Tree {
    struct Tree *bloc1;
    struct Tree *bloc2;
    struct Tree *bloc3;
    struct Tree *bloc4;
    unsigned char r;
    unsigned char g;
    unsigned char b;
    int nivel;
    int blocsize;
    int x, y;
} Tree;

typedef struct Queue {
    struct Queue *next;
    struct Queue *prev;
    Tree *info;
} Queue;

void add(Queue** queue, Tree*  tree);
Tree* extract(Queue** queue);
int verify(unsigned char **pixel, Tree *tree, int factor);
void solve_c1(FILE *output, unsigned char **pixel, int size, int factor);
Tree* create_celula();
void freePixels(unsigned char **pixeli, int size);
void freeTree(Tree *tree1);
void solve_c2(FILE *output, unsigned char **pixel, int size, int factor);

/*Toaca Andreia - 311CC*/
#include "utilities.h"

void add(Queue** queue, Tree* tree) {
    if ( *queue == NULL) {
        Queue* new = calloc (1, sizeof(Queue));
        new->next = new;
        new->prev = new;
        new->info = tree;
        *queue = new;
    } else {
        Queue* new = calloc (1, sizeof(Queue));
        new->next = *queue;
        new->prev = (*queue)->prev;
        new->info = tree;
        (*queue)->prev->next = new;
        (*queue)->prev = new;
    }
}  /* function for ading the tree in queue */ 

Tree* extract(Queue** queue) {
    Tree* tree = (*queue)->info; 
    if ( (*queue)->next == *queue) {
        free(*queue);
        *queue = NULL;
    } else {
        Queue* copy = *queue;
        (*queue)->next->prev = (*queue)->prev;
        (*queue)->prev->next = (*queue)->next;
        (*queue) = (*queue)->next;
        free(copy);
    }
    return tree;
}  /* function for extracting the tree from queue */

int verify(unsigned char **pixel, Tree *tree, int factor) {
    unsigned long long red = 0;
    unsigned long long green = 0;
    unsigned long long blue = 0;
    for ( int i = tree->x; i < tree->x+tree->blocsize; i++) {
        for ( int j = tree->y; j < tree->y+tree->blocsize; j++) {
            red = red + pixel[i][j*3];
            green = green + pixel[i][j*3+1];
            blue = blue + pixel[i][j*3+2];
        }
    }
    red = red/(tree->blocsize*tree->blocsize);
    green = green/(tree->blocsize*tree->blocsize);
    blue = blue/(tree->blocsize*tree->blocsize);
    unsigned long long mean = 0;
    for ( int i = tree->x; i < tree->x+tree->blocsize; i++) {
        for ( int j = tree->y; j < tree->y+tree->blocsize; j++) {
            mean = mean + (red - pixel[i][j*3]) * (red - pixel[i][j*3]);
            mean = mean + (green - pixel[i][j*3+1]) * (green - pixel[i][j*3+1]);
            mean = mean + (blue - pixel[i][j*3+2]) * (blue - pixel[i][j*3+2]);
        }
    }
    mean = mean/(tree->blocsize * tree->blocsize * 3);
    if ( mean <= factor) {
        tree->r = (unsigned char) red;
        tree->g = (unsigned char) green;
        tree->b = (unsigned char) blue;
        return 1;
    }
    return 0;
} /* function that calculates the arithmetic mean of 
     the values in the matrix of pixels corresponding to 
     a block, according to the formula */

void freeTree(Tree *tree1) {
    Queue* queue1 = NULL;
    add(&queue1, tree1);
    while (queue1 != NULL) {
        Tree *tree = extract(&queue1); 
        if (tree->bloc1) {
            add(&queue1, tree->bloc1);
            add(&queue1, tree->bloc2);
            add(&queue1, tree->bloc3);
            add(&queue1, tree->bloc4);
        }
        free(tree);
    }
}  /* function to free dynamically allocated memory for the tree */

void freePixels(unsigned char **pixeli, int size) {
    for (int i = 0; i < size; i++) {
            free(pixeli[i]);
    }
    free(pixeli);
}  /* function to free dynamically allocated memory for the matrix*/

Tree* create_celula() {
    Tree* tree = calloc(1, sizeof(Tree));
    tree->bloc1 = NULL;
    tree->bloc2 = NULL;
    tree->bloc3 = NULL;
    tree->bloc4 = NULL;
    return tree;
}  /* function for creating new node in the tree */

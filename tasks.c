/*Toaca Andreia - 311CC*/
#include "utilities.h"

void solve_c1(FILE *output, unsigned char **pixel, int size, int factor) {
    Tree *tree1 = create_celula();
    Queue* queue1 = NULL;  // for traversing the tree
    tree1->nivel = 1;
    tree1->blocsize = size;
    tree1->x = 0;  // line
    tree1->y = 0;  // column
    add(&queue1, tree1);
    int niv_max = 0;
    int nr_bloc = 0;
    int max_size = 0;
    while (queue1 != NULL) {
        Tree *tree = extract(&queue1); 
        if (niv_max < tree->nivel) {
            niv_max = tree->nivel;
        }
        int aux = verify(pixel, tree, factor);  // check the mean
        if ( aux == 0) {  // for each block need to get the position
            tree->bloc1 = create_celula();
            tree->bloc1->blocsize = tree->blocsize/2;
            tree->bloc1->x = tree->x;
            tree->bloc1->y = tree->y;
            tree->bloc1->nivel = tree->nivel+1;
            add(&queue1, tree->bloc1);
            tree->bloc2 = create_celula();
            tree->bloc2->blocsize = tree->blocsize/2;
            tree->bloc2->x = tree->x;
            tree->bloc2->y = tree->y + tree->bloc2->blocsize;
            tree->bloc2->nivel = tree->nivel+1;
            add(&queue1, tree->bloc2);
            tree->bloc3 = create_celula();
            tree->bloc3->blocsize = tree->blocsize/2;
            tree->bloc3->x = tree->x + tree->bloc3->blocsize;
            tree->bloc3->y = tree->y +tree->bloc3->blocsize;
            tree->bloc3->nivel = tree->nivel+1;
            add(&queue1, tree->bloc3);
            tree->bloc4 = create_celula();
            tree->bloc4->blocsize = tree->blocsize/2;
            tree->bloc4->x = tree->x + tree->bloc4->blocsize;
            tree->bloc4->y = tree->y;
            tree->bloc4->nivel = tree->nivel+1;
            add(&queue1, tree->bloc4);
        } else {
            nr_bloc++;
            if (max_size < tree->blocsize) {
                max_size = tree->blocsize;
            }  // the tree has leaf nodes
        }
    }
    fprintf(output, "%d\n", niv_max);
    fprintf(output, "%d\n", nr_bloc);
    fprintf(output, "%d\n", max_size);
    freeTree(tree1);
}

void solve_c2(FILE *output, unsigned char **pixel, int size, int factor) {
    Tree *tree1 = create_celula();
    tree1->blocsize = size;
    tree1->x = 0;
    tree1->y = 0;
    Queue* queue1 = NULL;
    add(&queue1, tree1);
    fwrite(&size, sizeof(unsigned int), 1, output); // initial size
    while (queue1 != NULL) {
        Tree *tree = extract(&queue1);
        int aux = verify(pixel, tree, factor);
        unsigned char type = 0;
        if ( aux == 0) {
            type = 0;  // division into 4 parts (4 different colors)
            fwrite(&type, sizeof(unsigned char), 1, output);
            tree->bloc1 = create_celula();
            tree->bloc1->blocsize = tree->blocsize/2;
            tree->bloc1->x = tree->x;
            tree->bloc1->y = tree->y;
            add(&queue1, tree->bloc1);
            tree->bloc2 = create_celula();
            tree->bloc2->blocsize = tree->blocsize/2;
            tree->bloc2->x = tree->x;
            tree->bloc2->y = tree->y + tree->bloc2->blocsize;
            add(&queue1, tree->bloc2);
            tree->bloc3 = create_celula();
            tree->bloc3->blocsize = tree->blocsize/2;
            tree->bloc3->x = tree->x + tree->bloc3->blocsize;
            tree->bloc3->y = tree->y +tree->bloc3->blocsize;
            add(&queue1, tree->bloc3);
            tree->bloc4 = create_celula();
            tree->bloc4->blocsize = tree->blocsize/2;
            tree->bloc4->x = tree->x + tree->bloc4->blocsize;
            tree->bloc4->y = tree->y;
            add(&queue1, tree->bloc4);
        } else {
            type = 1;  // one color
            fwrite(&type, sizeof(unsigned char), 1, output);
            fwrite(&tree->r, sizeof(unsigned char), 1, output);
            fwrite(&tree->g, sizeof(unsigned char), 1, output);
            fwrite(&tree->b, sizeof(unsigned char), 1, output);
        }  // print the RGB values
    }
    freeTree(tree1);
}

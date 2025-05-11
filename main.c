/*Toaca Andreia - 311CC*/
#include "utilities.h"

int main(int argc, char const *argv[]) {
    FILE *input;
    FILE *output;
    char p6[2], new_line;
    int size;
    int maxim;
    if (!strcmp(argv[1],"-c1")) {  // for task 1
        input = fopen(argv[3], "rb");
        output = fopen(argv[4], "wt");
        fscanf(input, "%s", p6);
        fscanf(input, "%d", &size);
        fscanf(input, "%d", &size);
        fscanf(input, "%d", &maxim);
        fscanf(input, "%c", &new_line);
        unsigned char **pixeli = calloc(size, sizeof(unsigned char*));
        for (int i = 0; i < size; i++) {
            pixeli[i] = calloc(size*3, sizeof(unsigned char));
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                fread(&pixeli[i][j*3], sizeof(unsigned char), 1, input);
                fread(&pixeli[i][j*3+1], sizeof(unsigned char), 1, input);
                fread(&pixeli[i][j*3+2], sizeof(unsigned char), 1, input);
            }
        }
        int factor = atoi(argv[2]);  // conert char value in integer
        solve_c1(output, pixeli, size, factor);
        freePixels(pixeli, size);
    }
    if (!strcmp(argv[1],"-c2")) {  // for task 2
        input = fopen(argv[3], "rb");
        output = fopen(argv[4], "wb");
        fscanf(input, "%s", p6);
        fscanf(input, "%d", &size);
        fscanf(input, "%d", &size);
        fscanf(input, "%d", &maxim);
        fscanf(input, "%c", &new_line);
        unsigned char **pixeli = calloc(size, sizeof(unsigned char*));
        for (int i = 0; i < size; i++) {
            pixeli[i] = calloc(size*3, sizeof(unsigned char));
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {  // read the values
                fread(&pixeli[i][j*3], sizeof(unsigned char), 1, input);
                fread(&pixeli[i][j*3+1], sizeof(unsigned char), 1, input);
                fread(&pixeli[i][j*3+2], sizeof(unsigned char), 1, input);
            }
        }
        int factor = atoi(argv[2]);
        solve_c2(output, pixeli, size, factor);
        freePixels(pixeli, size);
    }
    if (!strcmp(argv[1],"-d")){
        input = fopen(argv[2], "rb");
        output = fopen(argv[3], "wb");
    }
    fclose(input);
    fclose(output);
    return 0;
}

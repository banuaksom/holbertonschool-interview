#ifndef MENGER_H
#define MENGER_H
#include <math.h>
#include <stdio.h>

void menger(int level);
int **alloc_array(int size);
void free_array(int **a, int size);
void print_array(int **a, int size);
void fill_array(int **a, int size, char c);
void prepare_start_copy_positions(int *x, int *y, int cur_n);
#endif

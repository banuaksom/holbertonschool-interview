#include "menger.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * menger - draws a 2D Menger Sponge
 * @level: level of the Menger Sponge to draw
 * Return: void
 */
void menger(int level)
{
	int i, j, size, cur_n, startI, pos, startJ, start_pos_x[8], start_pos_y[8];
	int **a, **b;

	if (level < 0)
		return;
	size = pow(3, level);
	a = alloc_array(size);
	b = alloc_array(size);
	if (a == NULL || b == NULL)
		return;
	a[0][0] = '#';
	for (cur_n = 1; cur_n < size; cur_n *= 3)
	{
		for (i = 0; i < size; i++)
			for (j = 0; j < size; j++)
				b[i][j] = ' ';
		prepare_start_copy_positions(start_pos_x, start_pos_y, cur_n);
		for (pos = 0; pos < 8; pos++)
		{
			startI = start_pos_x[pos];
			startJ = start_pos_y[pos];
			for (i = 0; i < cur_n; i++)
				for (j = 0; j < cur_n; j++)
					b[startI + i][startJ + j] = a[i][j];
		}
		for (i = 0; i < size; i++)
			for (j = 0; j < size; j++)
				a[i][j] = b[i][j];
	}
	print_array(a, size);
	free_array(a, size);
	free_array(b, size);
}

/**
 * prepare_start_copy_positions - prepare start positions
 * @x: Array for x positions
 * @y: Array for y positions
 * @cur_n: current size
 */
void prepare_start_copy_positions(int *x, int *y, int cur_n)
{
	int pos, i, j;

	pos = 0;
	for (i = 0; i <= 2 * cur_n; i += cur_n)
	{
		for (j = 0; j <= 2 * cur_n; j += cur_n)
		{
			if (i == cur_n && j == cur_n)
				continue;
			x[pos] = i;
			y[pos] = j;
			pos++;
		}
	}
}

/**
 * print_array - prints 2d array of size
 * @a: Array to print
 * @size: Size of the array
 */
void print_array(int **a, int size)
{
	int i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			printf("%c", a[i][j]);
		printf("\n");
	}
}


/**
 * alloc_array - creates a 2d array of size
 * @size: Size of the array
 * Return: pointer to allocated array
 */
int **alloc_array(int size)
{
	int i, j, **a;

	a = malloc(sizeof(int *) * size);
	if (a == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		a[i] = malloc(sizeof(int) * size);
		if (a[i] == NULL)
		{
			free(a);
			for (j = 0; j <= i; j++)
				free(a[j]);
			return (NULL);
		}
	}
	return (a);
}

/**
 * free_array - Frees the allocated array
 * @a: Array to free
 * @size: Size of the array
 */
void free_array(int **a, int size)
{
	int i;

	for (i = 0; i < size; i++)
		free(a[i]);
	free(a);
}

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
	int i, j, size, cur_n, startI, startJ;
	int **a;

	if (level < 0)
		return;

	size = pow(3, level);
	a = alloc_array(size);
	if (a == NULL)
		return;

	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
			a[i][j] = ' ';
	a[0][0] = '#';
	for (cur_n = 1; cur_n < size; cur_n *= 3)
	{
		for (startI = 0; startI <= 2 * cur_n; startI += cur_n)
		{
			for (startJ = 0; startJ <= 2 * cur_n; startJ += cur_n)
			{
				if (startI == startJ && (startI == 0 || startI == cur_n))
					continue;
				for (i = 0; i < cur_n; i++)
					for (j = 0; j < cur_n; j++)
						a[startI + i][startJ + j] = a[i][j];
			}
		}
	}
	print_array(a, size);
	free_array(a, size);
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

#include "menger.h"
#include <math.h>
#include <stdio.h>
/**
 * menger - draws a 2D Menger Sponge
 * @level: level of the Menger Sponge to draw
 * Return: void
 */
void menger(int level)
{
	int i, j, size, cur_n, startI, pos, startJ, start_pos_x[8];
	int start_pos_y[8], a[729][729], b[729][729];


	if (level < 0)
		return;
	size = pow(3, level);
	a[0][0] = '#';
	for (cur_n = 1; cur_n < size; cur_n *= 3)
	{
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
				b[i][j] = ' ';
		}
		pos = 0;
		for (i = 0; i <= 2 * cur_n; i += cur_n)
		{
			for (j = 0; j <= 2 * cur_n; j += cur_n)
			{
				if (i == cur_n && j == cur_n)
					continue;
				start_pos_x[pos] = i;
				start_pos_y[pos] = j;
				pos++;
			}
		}
		for (pos = 0; pos < 8; pos++)
		{
			startI = start_pos_x[pos];
			startJ = start_pos_y[pos];
			for (i = 0; i < cur_n; i++)
			{
				for (j = 0; j < cur_n; j++)
					b[startI + i][startJ + j] = a[i][j];
			}
		}
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
				a[i][j] = b[i][j];
		}
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				if (j == size - 1)
					printf("%c", a[i][j]);
				else
					printf("%c ", a[i][j]);
			}
		}
		printf("\n");
	}
}

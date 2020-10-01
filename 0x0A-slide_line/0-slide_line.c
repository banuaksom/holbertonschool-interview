#include "slide_line.h"
/**
 * slide_line - slides and merges an array of integers
 * @line: an array of integers
 * @size: size of array
 * @direction: left or right slide direction
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
    if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
        return (0);
    if (direction == SLIDE_LEFT)
        slide_left(line, size);
    else
        slide_right(line, size);
    return (1);
}

/**
 * slide_left - slides a line to the left
 * @line: array to slide
 * @size: size of array
 */
void slide_left(int *line, size_t size)
{
    size_t i = 0, j = 1;
    int cur = line[0];

    for (; j < size; j++)
    {
        if (line[j])
        {
            if (!cur)
                cur = line[j];
            else if (cur == line[j])
            {
                line[i++] = cur * 2;
                cur = 0;
            }
            else
            {
                line[i++] = cur;
                cur = line[j];
            }
        }
    }

    if (cur)
        line[i++] = cur;

    for (; i < size; i++)
        line[i] = 0;
}

/**
 * slide_right - slides a line to the right
 * @line: array to slide
 * @size: size of array
 */
void slide_right(int *line, size_t size)
{
    int i = size - 1, j = size - 2;
    int cur = line[i];

    for (; j >= 0; j--)
    {
        if (line[j])
        {
            if (!cur)
                cur = line[j];
            else if (cur == line[j])
            {
                line[i--] = cur * 2;
                cur = 0;
            }
            else
            {
                line[i--] = cur;
                cur = line[j];
            }
        }
    }

    if (cur)
        line[i--] = cur;

    for (; i >= 0; i--)
        line[i] = 0;
}

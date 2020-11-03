#include "binary_trees.h"

/**
 * to_avl_helper - builds an AVL tree from a sorted array
 * @array: pointer to the array
 * @parent: pointer to the parent node
 * @start: start index
 * @end: end index
 *
 * Return: Pointer to the new AVL tree
 */
avl_t *to_avl_helper(int *array, avl_t *parent, int start, int end)
{
	int mid = (start + end) / 2;
	avl_t *new;

	if (!array || start > end)
		return (NULL);

	new = malloc(sizeof(avl_t));
	if (!new)
		return (NULL);

	new->n = array[mid];
	new->parent = parent;
	new->left = to_avl_helper(array, new, start, mid - 1);
	new->right = to_avl_helper(array, new, mid + 1, end);

	return (new);
}

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @array: pointer to the array
 * @size: size of the array
 * Return: pointer to the new AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (to_avl_helper(array, NULL, 0, size - 1));
}

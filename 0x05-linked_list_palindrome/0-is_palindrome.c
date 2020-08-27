#include "lists.h"

/**
 * isPalindromeUtil - checks if sublists are palindrome
 * @left: sublist
 * @right: sublist
 * Return: 1 if Palindrome, otherwise 0
 */
int isPalindromeUtil(listint_t **left, listint_t *right)
{
	int isp, isp1;

	if (right == NULL)
		return (1);
	isp = isPalindromeUtil(left, right->next);
	if (isp == 0)
		return (0);
	isp1 = (right->n == (*left)->n);
	*left = (*left)->next;
	return (isp1);
}

/**
 * is_palindrome - checks if singly linked list is palindrome
 * @head: pointer to first node of list
 * Return: 1 if list is palindrome, otherwise 0
 */

int is_palindrome(listint_t **head)
{
	return (isPalindromeUtil(head, *head));
}

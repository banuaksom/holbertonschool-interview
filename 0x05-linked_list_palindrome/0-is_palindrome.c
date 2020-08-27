#include "lists.h"


int isPalindromeUtil(listint_t **left, listint_t *right) 
{ 
    int isp, isp1;
    
    if (right == NULL) 
        return 1; 
  
    
    isp = isPalindromeUtil(left, right->next); 
    
    if (isp == 0) 
        return 0; 
  
    isp1 = (right->n == (*left)->n); 
  
    *left = (*left)->next; 
  
    return (isp1); 
} 
  
int is_palindrome(listint_t **head) 
{ 
    isPalindromeUtil(head, *head); 
}

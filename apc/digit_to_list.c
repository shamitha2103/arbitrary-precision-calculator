#include "apc.h"
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
void digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[])
{
    //using insert at last function to store the digits in the list
    int i;
    for (i = 0; argv[1][i] != '\0'; i++) // Storing first number
    {
        insert_last(head1, tail1, argv[1][i] - '0');
    }
    for (i = 0; argv[3][i] != '\0'; i++) // Storing second number
    {
        insert_last(head2, tail2, argv[3][i] - '0');
    }
}
void insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if (new == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
    if (*head == NULL)
    {
        *head = new;
        *tail = new;
    }
    else
    {
        (*tail)->next = new;
        new->prev = *tail;
        *tail = new;
    }
}

#include "apc.h"
#include <stdio.h>

void print_list(Dlist *head)
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    Dlist *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

#include "apc.h"
#include <stdlib.h>

void insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new=malloc(sizeof(Dlist));
    if(new==NULL)
    {
        //printf("Memory allocation failed\n");
        return;
    }
    new->data=data;
    new->prev=NULL;
    new->next=NULL;
    if(*head==NULL)
    {
        *head=*tail=new;
        
    }
    else
    {
        new->next=*head;
        (*head)->prev=new;
        *head=new;
        
    }
}
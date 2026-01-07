#include "apc.h"
#include <stdlib.h>
#include <stdio.h>

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    // Calculate lengths
    int len1 = 0, len2 = 0;
    Dlist *temp1 = *head1, *temp2 = *head2;
    while (temp1) 
    {
        len1++; temp1 = temp1->next; 
    }
    while (temp2) 
    {
        len2++; 
        temp2 = temp2->next; 
    }
    int negative=0;
    // Compare lengths
    if (len1 < len2) 
    {
        // Second number is greater
        negative = 1;
    } 
    else if (len1 == len2) 
    {
        // Lengths are equal
        temp1 = *head1;
        temp2 = *head2;
        while (temp1 && temp2) 
        {
            if (temp1->data < temp2->data) 
            {
                // Second number is greater
               
                negative = 1;
                break;
            } 
            else if (temp1->data > temp2->data) 
            {
                negative = 0;  // Ensure negative is set to 0 when num1 > num2
                break;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    if (negative) 
    {
        Dlist *temp;
        temp = *head1; *head1 = *head2; *head2 = temp;
        temp = *tail1; *tail1 = *tail2; *tail2 = temp;
    }
    
    temp1 = *tail1;
    temp2 = *tail2;
    int borrow = 0, data;

    // Iterate through linked lists
    while (temp1 || temp2) 
    {
        int val1 = temp1 ? temp1->data : 0;
        int val2 = temp2 ? temp2->data : 0;

        if (val1 < val2 + borrow) 
        {
            data = val1 + 10 - val2 - borrow;
            borrow = 1;
        } 
        else 
        {
            data = val1 - val2 - borrow;
            borrow = 0;
        }

        // Insert result into the result linked list
        insert_first(headR, tailR, data);

        if (temp1) temp1 = temp1->prev;
        if (temp2) temp2 = temp2->prev;
    }

    
    while ((*headR) && (*headR)->data == 0 && (*headR)->next) 
    {
        *headR = (*headR)->next;
        free((*headR)->prev);
        (*headR)->prev = NULL;
    }

    // Print negative sign if necessary
    if (negative) 
    {
        (*headR)->data *= -1;
    }
    return SUCCESS;
}

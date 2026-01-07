#include "apc.h"
#include<stdio.h>
#include<stdlib.h>

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
    if (*head1 == NULL || *head2 == NULL)
        return FAILURE;

    Dlist *temp2 = *tail2;
    int count = 0;
    Dlist *headR1 = NULL, *tailR1 = NULL;
    Dlist *headR2 = NULL, *tailR2 = NULL;

    while (temp2)
    {
        Dlist *temp1 = *tail1;
        int carry = 0;

        // Insert zeros for place value
        for (int i = 0; i < count; i++)
        {
            insert_first(&headR2, &tailR2, 0);
        }

        while (temp1)
        {
            int res = (temp1->data * temp2->data) + carry;
            carry = res / 10;
            insert_first(&headR2, &tailR2, res % 10);
            temp1 = temp1->prev;
        }
        if (carry)
        {
            insert_first(&headR2, &tailR2, carry);
        }

        if (count == 0)
        {
            headR1 = headR2;
            tailR1 = tailR2;
        }
        else
        {
            Dlist *headFR = NULL, *tailFR = NULL;
            addition(&headR1, &tailR1, &headR2, &tailR2, &headFR, &tailFR);
            headR1 = headFR;
            tailR1 = tailFR;
        }

        headR2 = NULL;
        tailR2 = NULL;
        temp2 = temp2->prev;
        count++;
    }

    while (headR1 && headR1->data == 0 && headR1->next)
    {
        headR1 = headR1->next;
        free(headR1->prev);
        headR1->prev = NULL;
    }

    *headR = headR1;
    *tailR = tailR1;
    return SUCCESS;
}

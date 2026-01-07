#include "apc.h"


int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    if (*head1 == NULL || *head2 == NULL)
        return FAILURE;
    
    // Check for division by zero
    if ((*head2)->data == 0 && (*head2)->next == NULL)
    {
        printf("Error: Division by zero  not possible.\n");
        return FAILURE;
    }
    
    int count = 0;
    Dlist *rHead = *head1;
    Dlist *rTail = *tail1;
    
    while (compare(rHead, *head2) >= 0)
    {
        Dlist *qHead = NULL, *qTail = NULL;
        subtraction(&rHead, &rTail, head2, tail2, &qHead, &qTail);
        rHead = qHead;
        rTail = qTail;
        count++;
    }
    
    // Store the result (quotient) in the list
    if (count == 0)
    {
        insert_first(headR, tailR, 0);
    }
    else
    {
        while (count > 0)
        {
            insert_first(headR, tailR, count % 10);
            count /= 10;
        }
    }
    
    
    return SUCCESS;
} 
int compare(Dlist *head1,Dlist *head2)
{
	int len1 = 0, len2 = 0;
    Dlist *temp1 = head1, *temp2 = head2;
    
    // Calculate lengths
    while (temp1) { len1++; temp1 = temp1->next; }
    while (temp2) { len2++; temp2 = temp2->next; }
    
    if (len1 > len2) return 1;
    if (len1 < len2) return -1;
    
    // If lengths are equal, compare digit by digit
    temp1 = head1;
    temp2 = head2;
    while (temp1 && temp2)
    {
        if (temp1->data > temp2->data) return 1;
        if (temp1->data < temp2->data) return -1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

	return 0;
}

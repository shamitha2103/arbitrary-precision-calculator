#include "apc.h"
#include <stddef.h>

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
	//validation
	if(*head1==NULL || *head2==NULL)
	{
		return FAILURE;
	}
	/* Definition goes here */
	Dlist *t1=*tail1;
	Dlist *t2=*tail2;
	int res,carry=0;
	while(t1!=NULL || t2!=NULL)
	{
		if(t1==NULL && t2!=NULL)
		{
			res=t2->data+carry;
            t2 = t2->prev;
		}
		else if(t2==NULL && t1!=NULL)
		{
			res=t1->data+carry;
			t1 = t1->prev;
            
		}
		else
		{
			res=t1->data+t2->data+carry;
			t1 = t1->prev;
            t2 = t2->prev;
		}
		if(res>9)  //to check the carry
		{
			carry=1;
			res=res%10;
		}
		else
		{
			carry=0;
		}
		insert_first(headR, tailR, res); // Insert result at the front
		
	}
	// If carry left, insert it at the front
	if(carry==1)
	{
		insert_first(headR, tailR, carry); // Insert carry at the front
	}
	return SUCCESS;
}

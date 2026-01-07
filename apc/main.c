#include "apc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
	/* Validate input arguments */
    if (argc != 4)  // Expecting: ./output <num1> <operator> <num2>
    {
        printf("Usage: ./output <num1> <operator> <num2>\n");
        return FAILURE;
    }
	if (strchr(argv[1], '.') != NULL || strchr(argv[3], '.') != NULL) 
    {
        printf("Error: only integers are supported.\n");
        return FAILURE;
    }
	//if character is given invalid
	for (int i = 0; i < strlen(argv[1]); i++)
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
		{
			printf("Error: Invalid character '%c' in number '%s'.\n", argv[1][i], argv[1]);
			return FAILURE;
		}
	}
	for (int i = 0; i < strlen(argv[3]); i++)
	{
		if (argv[3][i] < '0' || argv[3][i] > '9')
		{
			printf("Error: Invalid character '%c' in number '%s'.\n", argv[3][i], argv[3]);
			return FAILURE;
		}
	}
	
	
      
	
	//Validation
	char operator=argv[2][0];
	if (!(operator == '+' || operator == '-' || operator == 'x' || operator == '/'))
    {
        printf("Error: Invalid operator '%c'. Supported operators: +, -, x, /\n", operator);
        return FAILURE;
    }
	/* Declare the pointers */
	Dlist *head1=NULL, *tail1=NULL;
    Dlist *head2=NULL, *tail2=NULL; 
    Dlist *headR=NULL,*tailR=NULL;
	digit_to_list(&head1,&tail1,&head2,&tail2,argv);
	

	switch (operator)
	{
		case '+':
                            
			/* call the function to perform the addition operation */
            addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
			printf("Result: ");
        	print_list(headR);
			break;
		case '-':	
			/* call the function to perform the subtraction operation */
			subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
			printf("Result: ");
			print_list(headR);
			break;
		case 'x':	
			/* call the function to perform the multiplication operation */
			multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
			printf("Result: ");
			print_list(headR);
			break;
		case '/':	
			/* call the function to perform the division operation */
			division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
			printf("Result: ");
			print_list(headR);
			break;
		default:
			printf("Invalid Input:-(\n Try again...\n");
			return FAILURE;
	}
	return 0;
}

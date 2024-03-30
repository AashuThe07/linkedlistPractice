#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int number;
	struct node *next;
} node;

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Usage: ./Filename NUMBERS");
		return 1;
	}
	node *list = NULL;

	for (int i = 1; i <= argc; i++)
	{
		int number = atoi(argv[i]);
		node *n = malloc(sizeof(node));
    	if (n == NULL)
    	{
        	printf("Error while allocating memory");
        	return 1;
    	}
		n->number = number;
		n->next = list;
		list = n;

	}
	printf("List Updated...");
	printf("Printing Results");
	node *ptr = list;
	while (ptr != NULL)
	{
		printf("%i\n", ptr->number);
		ptr = ptr->next;
	}

	node *toFree = list;
	if (toFree == NULL)
	{
		printf("List is NULL");
		return 1;
	}

	while (toFree != NULL)
	{
		list = toFree;
		toFree = list->next;
		free(list);
	}
	
	return 0;
}

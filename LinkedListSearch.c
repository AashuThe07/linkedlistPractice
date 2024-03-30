#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
	int number;
	struct node *next;
} node;

bool search(int num, node *ptr);
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Usage: ./Filename NUMBERS");
		return 1;
	}
	// Node List = NULL
	node *list = NULL;

	for (int i = 1; i < argc; i++)
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

	node *ptr = list;
	while (ptr != NULL)
	{
		printf("%i\n", ptr->number);
		ptr = ptr->next;
	}

	int num;
	printf("\nEnter a number: ");
	scanf("%d", &num);
	search(num, list);

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

bool search(int num, node *ptr)
{
	node *tmp = ptr;
	do
	{
		if (tmp->number == num)
		{
			printf("\n<----------------->\n");
			printf("Number Found\n");
			printf("Number: %i\n", tmp->number);
			printf("Location: %p", tmp->next);
			printf("\n<----------------->");
			return true;
		}
		tmp = tmp->next;
	} while (tmp != NULL);
	printf("\n<Number not found>\n");
	return false;
}

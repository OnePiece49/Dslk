#include "List.h"

int main()
{
	int number_node = -1;
	list mylist;

	InitList(&mylist);
	printf("Enter number node: ");
	do  {
		scanf("%d", &number_node);
	} while (number_node < 0);
	
	AddNodeintoList(&mylist, number_node);

	PrintList(mylist);
	ChangeNode(mylist, 1);
	PrintList(mylist);
	DeleteNode(&mylist, 8);
	DeleteNode(&mylist, 1);
	DeleteNode(&mylist, 3);
	PrintList(mylist);
	AddNodeintoList(&mylist, 2);
	DeleteNode(&mylist, 4);
	PrintList(mylist);

	return 0;

}
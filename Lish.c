#include "List.h"

NODE *InitNode(NODE n)
{
	NODE *p = (NODE *)malloc(1 * sizeof(NODE));
	if (p == NULL)
	{
		printf("Cap phat bo nho ERROR");
		return NULL;
	}
	else
	{
		strcpy(p->Ten, n.Ten);
		p->Age = n.Age;
		strcpy(p->number, n.number);
		p->pTiep = NULL;
		return p;
	}
}

void InitList(list *list1)
{
	list1->pHead = NULL;
	list1->pTail = NULL;
}

void AddNodeintoList(list *list1, NODE *node)
{
	if (list1->pHead == NULL)
	{
		list1->pHead = list1->pTail = node;
	}
	else
	{
		list1->pTail->pTiep = node;
		list1->pTail = node;
	}
}

void EnterDataNode(NODE *n)
{
	printf("***Enter name : ");
	fflush(stdin);
	gets(n->Ten);
	fflush(stdin);
	printf("***Enter Age : ");
	fflush(stdin);
	scanf("%d", &n->Age);
	fflush(stdin);
	printf("***Enter number : ");
	fflush(stdin);
	scanf("%s", &n->number);
	fflush(stdin);
}

void PrintNode(NODE *n)
{
	printf("Name: %s\n", n->Ten);
	printf("Age: %d\n", n->Age);
	printf("Number: %s\n", n->number);
}


void PrintList(list list1)
{
	for (NODE *k = list1.pHead; k != NULL; k = k->pTiep)
	{
		PrintNode(k);
	}
}

void FindList(list list1, char Ten[])
{
	int i = 1, j = 0;
	for (NODE *k = list1.pHead; k != NULL; k = k->pTiep)
	{
		i = strcmp(Ten, k->Ten);
		if(i == 0)
		{
			if(j == 0)
			{
				j = 1;
				printf("-Thong Tin nguoi ban tim kiem :\n");
			}
			i = 1;
			PrintNode(k);
		}
	}
}

void ChangeNode(list list1, char Ten[])
{
	int i = 1;
	for(NODE *k = list1.pHead; k != NULL; k = k->pTiep )
	{
		i = strcmp(Ten, k->Ten);
		if(i == 0)
		{
			EnterDataNode(k);
			i = 1;
		}
	}
}

void DeleteNode(list* list1, char Ten[], NODE node1)
{
	NODE* nodechange;
	int i = 1, NodeNumber = 0, vitriNode = 0;
	int a = 0;
	for(NODE *k = list1->pHead; k != NULL; k= k->pTiep)
	{
		NodeNumber++;
	}
	if(NodeNumber == 0)
	{
		printf("\n ko co Node nao de xoa");
	}
	else if(NodeNumber == 1)
	{
		for(NODE *k = list1->pHead; k != NULL; k = k->pTiep)
		{
			i = strcmp(Ten, k->Ten);
			if(i == 0)
			{
				list1->pHead = list1->pTail = NULL;
			}
		}
	}
	else
	{
	for(NODE *k = list1->pHead; k != NULL; k = k->pTiep)
	{
		i = strcmp(Ten, k->Ten);
		vitriNode++;
		if(i == 0)
		{
			if(vitriNode == 1)
			{
				list1->pHead = k->pTiep;
				i = 1;
			}
			else if(vitriNode == NodeNumber)
			{
				for(NODE *h = list1->pHead; h != NULL; h = h->pTiep)
				{
					if(h->pTiep == k)
					{
						h->pTiep = NULL;
						break;
					}
				}	
			}
			else
			{
				for(NODE *h = list1->pHead; h != NULL; h = h->pTiep){
					if(h->pTiep == k)
					{
						h->pTiep = k->pTiep;
						k->pTiep = NULL;
						break;
					}
				}
	
		}
	 }
	}
}
}
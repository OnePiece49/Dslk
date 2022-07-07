#ifndef _LISH_H
#define _LISH_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node node;
typedef struct list list;

static char ID_list[100] = {0};
static int number_id = 0;

struct node
{
	int id;
	char Name[30];
	int Age;
	node *pTiep;
};

struct list
{
	node *pHead;
	node *pTail;
};

node *InitNode();  
void InitList(list *list1);  
static void AddNode(list *mylist, node *mynode); 
void AddNodeintoList(list *mylist , int number_node);
static int EnterDataNode(node *n);	
static void PrintNode(const node *n);		
void PrintList(const list mylist);		
int FindList(const list mylist, int id); 
int ChangeNode(list list1, int id);	
int DeleteNode(list *list1, int id);		

static void ClearBuffer();
#endif
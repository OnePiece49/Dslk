#ifndef _LISH_H
#define _LISH_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node NODE ;
struct node
{
	char Ten[30];
	int Age;
	char number[30];
	NODE *pTiep;
};


typedef struct LIST list;
struct LIST
{
	NODE *pHead;
	NODE *pTail;
};
NODE *InitNode(NODE n);  //Khoi tao 1 node
void InitList(list *list1);  //Khao tao 1 list
void AddNodeintoList(list *list1, NODE *node);  //Them node vao trong list
void EnterDataNode(NODE *n);	//Nhap du lieu vao node
void PrintNode(NODE *n);		//In Node
void PrintList(list list1);		//Thong ke toan bo 1 list
void FindList(list list1, char Ten[]);		//Tim ten 
void ChangeNode(list list1, char Ten[]);	//Thay doi
void DeleteNode(list* list1, char Ten[], NODE node1);		//Xoa node
#endif
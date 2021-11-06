#include "List.h"

int main()
{
	NODE node;
	list list1;
	InitList(&list1);
	int n;
	printf("-Number Node of List1: ");
	scanf("%d", &n);
	fflush(stdin);
	for (int i = 0; i < n; i++)
	{
		printf("Enter data for Node[%d] \n", i);
		;
		EnterDataNode(&node);
		NODE *p = InitNode(node);
		AddNodeintoList(&list1, p);
	}
	printf("-Danh sach lien ket don cua ban la :\n");
	PrintList(list1);
	FindList(list1, "Viet dz");
    printf("-Thay doi data nguoi ban muon: \n");
	ChangeNode(list1, "Viet dz");
    printf("-Danh sach lien ket don cua ban sau khi thay doi la :\n");
	PrintList(list1);
    printf("-Nguoi ban muon xoa: ");
	DeleteNode(&list1, "Viet dz", node);
	printf("-Danh sach lien ket don cua ban sau khi thay doi la :\n");
	PrintList(list1);
	return 0;
}
#include "list.h"

static void ClearBuffer() {
    while(getchar() != '\n');
}

void InitList(list *list_init) {
    list_init->pHead = NULL;
    list_init->pTail = NULL;
}

node *InitNode() {
    node *n = (node *) malloc(sizeof(node));
    if (n == NULL) {
        printf("Allocate memory fail for Node\n");
    } 
    return n;
}

static int EnterDataNode(node *data_node) {
    int id;
    printf("\n*****New Node*****\n");
    printf("Enter Id for Node: ");
    scanf("%d", &id);
    for (int i = 0; i < number_id; i++) {
        if (id == ID_list[i]) {
            printf("Id is exist\n");
            return 1;
        }
    }
    data_node->id = id;
    ID_list[number_id++] = id;
    ClearBuffer();

    printf("Enter Name for: ");
    gets(data_node->Name);
    printf("Enter Age for Node: ");
    scanf("%d", &data_node->Age);
    ClearBuffer();
    data_node->pTiep = NULL;
}

void AddNodeintoList(list *mylist , int number_node) {
    for (int i = 0; i < number_node; i++) {
		node *temp_node = InitNode();
		if ( EnterDataNode(temp_node) == 1) {
            free(temp_node);
            continue;
        }
		AddNode(mylist, temp_node);
	}
}

static void AddNode(list *mylist, node *mynode) {
    if (mylist->pHead == NULL) {
        mylist->pHead = mynode;
        mylist->pTail = mynode;
    } else {
        mylist->pTail->pTiep= mynode;
        mylist->pTail = mynode;
    }
}

static void PrintNode(const node *n) {
    printf("ID:   %d\n", n->id);
    printf("Name: %s\n", n->Name);
    printf("Age:  %d\n\n", n->Age);
}

void PrintList(const list mylist) {
    if (mylist.pHead == NULL) {
        printf("Node is not Init\n");
        return;
    }
    int i = 1;
    printf("\n");
    for (node *n = mylist.pHead; n != NULL; n = n->pTiep) {
        printf("****** Node %d: ******\n", i++);
        PrintNode(n);
    }
}

int FindList(const list mylist, int id) {
    if (mylist.pHead == NULL) {
        printf("Node is not Init\n");
        return 0;
    }
    for (node *n = mylist.pHead; n != NULL; n = n->pTiep) {
        if (n->id == id) {
            printf(" ****** Found List: ******\n");
            PrintNode(n);
            return 0;
        }
    }

    printf("Not exist ID in list\n");
    return 1;
}

int ChangeNode(list mylist, int id) {
    int index_id = 0;
    int id_temp;
    if (mylist.pHead == NULL) {
        printf("Node is not Init\n");
    }

    if (FindList(mylist, id) == 0) {
        printf("  ******  Starting Change Node  ******\n");
        for (node *n = mylist.pHead; n != NULL; n = n->pTiep) {
            if (n->id == id) {
                printf("Enter Id for Node: ");
                scanf("%d", &id_temp);
                for (int i = 0; i < number_id; i++) {
                    if (id != id_temp) {
                        if (id_temp == ID_list[i]) {
                            printf("Id is exist\n");
                            exit(1);
                        }
                    }
                }
                n->id = id_temp;
                ID_list[index_id] = id_temp;
                ClearBuffer();

                printf("Enter Name: ");
                gets(n->Name);
                printf("Enter Age: ");
                scanf("%d", &n->Age);
                ClearBuffer();  
                return 0;          
            }   
            index_id++;
        }
    
    } else {
        return 1;
    }
}

int DeleteNode(list *mylist, int id) {
    int number_temp = 0;
    if (mylist->pHead == NULL) {
        printf("Node is not Init\n");
        return 1;
    }

    if (FindList(*mylist, id) == 0) {
        if (number_id == 1) {
            mylist->pHead = NULL;
            mylist->pTail = NULL;
            memset(ID_list, 0, sizeof(ID_list));
            return 0;
        }

        node *n = mylist->pHead;
        if (n->id == id) {
            mylist->pHead = mylist->pHead->pTiep;
            printf("Find ID if id = 1\n");
            ID_list[0] = 0;
            return 0;
            // free(n); chua giai phong dia chi
        }

        for (node *n = mylist->pHead; n != NULL; n = n->pTiep) {
            if (n->pTiep->id == id) {
                printf("Find ID\n");
                n->pTiep = n->pTiep->pTiep;
                ID_list[number_temp] = 0; 
                if (n->pTiep == NULL) {
                    mylist->pTail = n;
                }
                return 0;
            }   
            number_temp++;
        }
        
    } else {
        return 1;
    }

}


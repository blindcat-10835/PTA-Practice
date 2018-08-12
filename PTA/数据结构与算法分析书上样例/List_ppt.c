#define _CRT_SECURE_NO_WARNINGS
#define MaxDegree 100
#include <stdio.h>
#include <stdlib.h>
typedef  struct  list_node  *list_ptr;
struct  list_node
{
	char		*data;
	list_ptr    next;
};
typedef  struct  node  *node_ptr;
typedef  struct  node
{
	node_ptr  llink;
	float    item;
	node_ptr  rlink;
};
typedef struct
{
	int     CoeffArray[MaxDegree + 1];
	int     HighPower;
}  *Polynomial;

list_ptr   ptr;
list_ptr   N1, N2;

int List_ppt(int argc, char const *argv[])
{
	N1 = (list_ptr)malloc(sizeof(struct list_node));
	N2 = (list_ptr)malloc(sizeof(struct list_node));
	N1->data = (char*)"ZHAO";
	N2->data = (char*)"QIAN";
	//printf("%s", N1->data);
	N1->next = N2;
	N2->next = NULL;
	ptr = N1;
	return 0;
}
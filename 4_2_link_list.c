#include <stdio.h>
#include <stdlib.h>
/*
struct node{
	int data;
	struct node *next;
};
typedef struct node Node;
*/
typedef struct node
{
    int data;
    struct node *next;
} Node;

int main(int argc, char *argv[])
{
    Node a, b, c;
    Node *ptr = &a;

    a.data = 12;
    a.next = &b;
    b.data = 30;
    b.next = &c;
    c.data = 64;
    c.next = NULL;

    printf("\n");
    while (ptr != NULL)
    {
        printf("address=%p, ", ptr);    //印出節點的位址
        printf("data=%d ", ptr->data);  //印出節點的資料
        printf("next=%p\n", ptr->next); //印出下一個節點位址
        ptr = ptr->next;                //將ptr指向下一個節點
    }

    return 0;
}
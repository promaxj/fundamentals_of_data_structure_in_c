#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node Node;

Node *createList(int *, int);     //串列建立函數
Node printList(Node *);           //串列列印函數
void freeList(Node *);            //釋放串列記憶空間函數
Node *searchNode(Node *, int);    //搜尋節點函數
void *insertNode(Node *, int);    //插入節點函數
Node *deleteNode(Node *, Node *); //刪除節點函數

int main(int argc, char *argv[])
{

    Node *first, *node;
    int arr[] = {12, 38, 57};
    first = createList(arr, 3);
    printList(first);

    node = searchNode(first, 38);    //找出節點值為38的位址
    first = deleteNode(first, node); //刪除節點38
    printList(first);

    first = deleteNode(first, first); //刪除地一個節點
    printList(first);

    first = deleteNode(first, first); //刪除地一個節點
    printList(first);
    freeList(first);

    return 0;
}

//串列建立函數
Node *createList(int *arr, int len)
{
    int i;
    Node *first, *current, *previous;
    for (i = 0; i < len; i++)
    {
        current = (Node *)malloc(sizeof(Node)); //建立新節點
        current->data = arr[i];                 //設定節點的資料成員
        if (i == 0)
        {
            first = current; //如果是第一個成員把指標frist指向目前的節點
        }
        else
        {
            previous->next = current; //把前一個的next指向目前的節點
        }
        current->next = NULL; //把目前的節點的next指向NULL
        previous = current;   //把前一個節點設成目前的節點
    }
    return first;
}

//串列列印函數
Node printList(Node *first)
{
    Node *node = first; //將node指向第一個節點
    if (first == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        while (node != NULL)
        {
            printf("%3d", node->data);
            node = node->next;
        }
        printf("\n");
    }
}

//釋放串列記憶空間函數
void freeList(Node *first)
{
    Node *current, *tmp;
    current = first;
    while (current != NULL)
    {
        tmp = current;
        current = current->next;
        free(tmp);
    }
}

//搜尋節點函數
Node *searchNode(Node *first, int item)
{
    Node *node = first;
    while (node != NULL)
    {
        if (node->data == item)
        {                //如果node的data等於item
            return node; //傳回node為該節點的位址
        }
        else
        {
            node = node->next; //否則將指標指向下一個節點
        }
    }
    return NULL; //如果找不到符合的節點，則傳回NULL
}

//插入節點函數
void *insertNode(Node *node, int item)
{
    Node *newnode;
    newnode = (Node *)malloc(sizeof(Node));
    newnode->data = item;
    newnode->next = node->next;
    node->next = newnode;
}

//刪除節點函數
Node *deleteNode(Node *first, Node *node)
{
    Node *ptr = first;
    if (first == NULL)
    { //如果串列是空的，則印出Nothing to delete! */
        printf("Nothing to delete!\n");
        return NULL;
    }
    if (node == first)
    {                        //如果刪除的是第一個節點
        first = first->next; //把first指向下一個節點(NULL)
    }
    else
    {
        while (ptr->next != node)
        { //找到要刪除之節點的前一個節點
            ptr = ptr->next;
        }
        ptr->next = node->next; //重新設定ptr的next成員
    }
    free(node);
    return first;
}
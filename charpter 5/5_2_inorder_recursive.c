#include <stdio.h>
#include <stdlib.h>
#define NUM 15

typedef struct treenode *tnode;
struct treenode
{
    int item;
    tnode l;
    tnode r;
};


void visit(tnode x)
{
    printf("%i ", x->item);
}

tnode createTree(int S, int N)
{
    tnode t;

    if (S > N)
        return NULL;

    t = malloc(sizeof(*t));
    t->item = S;
    t->l = createTree(S * 2, N);
    t->r = createTree(S * 2 + 1, N);

    return t;
}

void traverseTree(tnode h, void (*visit)(tnode))
{

    if (h->l != NULL)
        traverseTree(h->l, visit);

    // In-order Traversal
    (*visit)(h);

    if (h->r != NULL)
        traverseTree(h->r, visit);
}

int main(void)
{
    tnode head = createTree(1, NUM);
    traverseTree(head, visit);
    printf("\n");
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define SWAP(x, y, t) ((t)=(x), (x) = (y), (y) = (t))
#define COMPARE(x, y) ((x) < (y) ? (-1) : ((x)==(y)) ? 0 : 1)
#define LIST_LEN 10
#define LIST_MAX_NUM 100
void sort(int list[], int n) {
    int i, j, min, temp;
    for(i = 0; i < (n-1); i++) {
        min = i;
        for (j = i+1; j < n; j++) {
            if(list[j] < list[min]) {
                min = j;
            }
        }
        SWAP(list[i], list[min], temp);
    }
}
int binsearch(int list[], int searchnum, int left, int right)
{
    int middle;
    while(left <= right) {
        middle = (left + right)/2;
        switch(COMPARE(list[middle], searchnum)) {
            case -1:
                left = middle + 1;
                break;
            case 0:
                //return middle;
                return printf("target num is on the list No.%d\n", middle+1);
            case 1:
                right = middle - 1;
        }
    }
    return printf("there is no this number!!!\n");
}
void main(void) 
{
    int i, j, n;
    int list[LIST_LEN];
    printf("list num range is 0 ~ %d, and list length is %d, witch number you want to search?\n", LIST_MAX_NUM, LIST_LEN);
    scanf("%d", &n);
    if (n < 1) {
        fprintf(stderr, "Improper value of n\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < LIST_LEN; i++) {
        list[i] = (rand() % LIST_MAX_NUM) + 1;
        
        for(j = 0 ; j < i ; j++) {
            if(list[i] == list[j]) {
                i--;
                break;
            }
        }
    }
    sort(list, LIST_LEN);
    printf("\nSorted array:\n");
    for(i = 0; i < LIST_LEN; i++) {
        printf("%d*", list[i]);
    }
    printf("\n");
    binsearch(list, n, 0, LIST_MAX_NUM);
}
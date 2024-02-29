#include<stdio.h>
struct node {
    int data;
    struct node *next;
};

int main(){

    struct node *head;
    head=(struct node*)malloc(sizeof(struct node));

    printf("this is node 1 %d ",head->data);

    return 0;
}

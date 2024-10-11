#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next, prev;
};

struct Node* head = (struct Node*)malloc(sizeof(struct Node));
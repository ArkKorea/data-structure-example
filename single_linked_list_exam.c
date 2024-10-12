#include<stdio.h>
#include<stdlib.h>


/*
SLL : Single Linked List
C���� �����غ���
*/

typedef struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

int find(int elem){
    if(head == NULL) return -1; // SLL�� ����� ��
    struct Node* curNode = head;
    while(curNode != NULL) {
        if(curNode->data == elem){
            return curNode->data;
        }
        curNode = curNode->next;
    }
    return -1; // �ش� ���� ���� ��
}

// �� �ڿ� ������ ��
void insert(int elem){
    struct Node* addNode = (struct Node*)malloc(sizeof(struct Node));
    addNode->data = elem;
    if(head == NULL) {
        head = addNode;
    }
    else{
        struct Node* curNode = head;
        while(curNode->next != NULL) {
            curNode = curNode->next;
        }
        curNode->next = addNode;
        addNode->next = NULL;
    }
}

// �� �տ� Ȥ�� �߰��� ������ ��
void insert(int elem, int location){
    struct Node* addNode = (struct Node*)malloc(sizeof(struct Node));
    addNode->data = elem;
    if(head == NULL) {
        head = addNode;
    }
    else if(location == 0){
        addNode->next = head;
        head = addNode;
    }
    else{
        struct Node* curNode = head;
        int idx = 1;
        while(curNode->next != NULL){
            if(idx == location-1){
                addNode->next = curNode->next;
                curNode->next = addNode;
            }
            curNode = curNode->next;
        }
    }
}

// ���ϴ� ���� ������ ��
void delete(int elem){
    struct Node* curNode = head;
    while(curNode->next->next != NULL){
        if(curNode->next->data == elem){
            struct Node* delNode = curNode->next;
            curNode->next = delNode->next;
            free(delNode);
        }
    }
}

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

int find(int elem){
    struct Node* curNode = head;
    while(curNode->next != NULL){
        if(curNode->data == elem){ // 찾았을 때
            return curNode->data;
        }
        curNode = curNode->next;
    }
    return -1; // 못 찾았을 때
}

// 맨 앞에 삽입
void insert(int elem){
    struct Node* addNode = (struct Node*)malloc(sizeof(struct Node));
    if(head == NULL){
        head = addNode;
    }
    else{
       addNode->next = head;
       addNode->prev = NULL;
       head->prev = addNode;
       head = addNode;
    }
}

// 맨 앞이 아닌 위치 삽입
void insert(int elem, int location){
    struct Node* addNode = (struct Node*)malloc(sizeof(struct Node));
    if(head == NULL){
        head = addNode;
    }
    else{
        int idx = 1;
        struct Node* curNode = head;
        while(idx < location-1){
        	curNode = curNode->next;
            idx++;
        }
        addNode->next = curNode->next;
        curNode->next->prev = addNode;
        addNode->prev = curNode;
        curNode->next = addNode;
    }

}
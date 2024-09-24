#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

// 데이터가 삽입될 노드 구조체
struct Node{
    int data;
    Node* parent;
    Node* leftChild;
    Node* rightChild;
};

// BST 클래스 생성
class binarySearchTree{
private:
    Node* root;
public:
    // 생성자, 처음은 아무것도 없으므로 root가 nullptr
    binarySearchTree(){
        Node* root = nullptr;
    }
    void insert(int elem);
    Node* find(int elem);
    void swap(Node* a, Node* b);
    void erase(int elem);
    void erase(Node* node);
    void print(Node* node);
    Node* getRoot();
};

// 원하는 값의 노드를 삽입하는 함수
void binarySearchTree :: insert(int elem){
    Node* addNode = new Node;
    // BST에 아무것도 없다면 root로 지정
    if(root == nullptr){
        addNode->data = elem;
        addNode->parent = nullptr;
        addNode->leftChild = nullptr;
        addNode->rightChild = nullptr;
        root = addNode;
        return;
    }
    // root에 값이 있다면 root를 현재 노드로 지정
    Node* curNode = root;
    while(1){
        // elem이 현재 노드의 값보다 작다면
        while(curNode->data > elem){
            // 왼쪽 자식이 없다면
            if(curNode->leftChild == nullptr){
                addNode->data = elem;
                addNode->parent = curNode;
                addNode->leftChild = nullptr;
                addNode->rightChild = nullptr;
                curNode->leftChild = addNode;
                return;
            } // 왼쪽 자식이 있다면
            else{ curNode = curNode->leftChild; }
        }
        // elem이 현재 노드의 값보다 크다면
        while(curNode->data < elem){
            // 오른쪽 자식이 없다면
            if(curNode->rightChild == nullptr){
                addNode->data = elem;
                addNode->leftChild = nullptr;
                addNode->rightChild = nullptr;
                addNode->parent = curNode;
                return;
            } // 오른쪽 자식이 있다면
            else{ curNode = curNode->rightChild; }
        }
    }
}
// 원하는 값을 가진 노드의 포인터 반환, 없으면 nullptr
Node* binarySearchTree :: find(int elem){
    Node* curNode = root;
    // 트리가 비어있다면 nullptr 반환
    if(curNode == nullptr) return nullptr;
    while(1){
        // 찾는 값이 curNode의 값보다 작다면
        while(curNode->data > elem){
            curNode = curNode->leftChild;
        }
        // 찾는 값이 curNode의 값보다 크다면
        while(curNode->data <= elem){
            if(curNode->data == elem) return curNode;
            curNode = curNode->rightChild;
        }
        // 찾는 값이 없다면 nullptr 반환
        if(curNode == nullptr) return nullptr;
    }
}
// 두 개의 노드를 바꾸는 함수
void binarySearchTree :: swap(Node* a, Node* b){
    Node* temp = new Node;
    if(a->parent->leftChild == a)
        a->parent->leftChild = b;
    else
        a->parent->leftChild = b;
    
    if(b->parent->leftChild == b)
        b->parent->leftChild = a;
    else
        b->parent->rightChild = a;
    // 각 노드의 포인터들 교환
    temp->data = a->data;
    a->data = b->data;
    b->data = temp->data;
    
    temp->parent = a->parent;
    a->parent = b->parent;
    b->parent = temp->parent;
    
    temp->leftChild = a->leftChild;
    a->leftChild = b->leftChild;
    b->leftChild = temp->leftChild;
    
    temp->rightChild = a->rightChild;
    a->rightChild = b->rightChild;
    b->rightChild = temp->rightChild;
    
    delete temp;
}
// 노드 삭제
void binarySearchTree :: erase(int elem){
    Node* delNode = find(elem);
    // 해당 데이터가 없을 때
    if(delNode == nullptr) return;
    // 해당 노드가 리프 노드일 때
    if(delNode->rightChild == nullptr && delNode->leftChild == nullptr){
        if(delNode->parent->leftChild == delNode)
            delNode->parent->leftChild = nullptr;
        else
            delNode->parent->rightChild = nullptr;
    }
    // 왼쪽 자식만 있을 때
    else if(delNode->rightChild == nullptr){
        if(delNode->parent->leftChild == delNode)
            delNode->parent->leftChild = delNode->leftChild;
        else
            delNode->parent->rightChild = delNode->leftChild;
        delNode->leftChild->parent = delNode->parent;
    }
    // 오른쪽 자식만 있을 때
    else if(delNode->leftChild == nullptr){
        if(delNode->parent->leftChild == delNode)
            delNode->parent->leftChild = delNode->rightChild;
        else
            delNode->parent->rightChild = delNode->rightChild;
    }
    // 자식이 둘 다 있을 때
    else{
        //자신의 오른쪽 자식 중에 가장 작은 값을 찾아냄
        Node* curNode = delNode->rightChild;
        while(curNode->leftChild != nullptr){
            curNode = curNode->leftChild;
        }
        swap(delNode, curNode);
        if(delNode->parent->leftChild == delNode) delNode->parent->leftChild = nullptr;
        else delNode->parent->rightChild = nullptr;
    }
    delete delNode;
}
// 노드 삭제
void binarySearchTree :: erase(Node* node){
    //위와 다르게 포인터가 들어왔으므로 값이 없는 경우는 없다
    //찾으려는 노드가 리프노드일 때
    if(node->leftChild == nullptr && node->rightChild == nullptr){
        if(node->parent->leftChild == node) node->parent->leftChild = nullptr;
        else node->parent->rightChild = nullptr;
    }
    // 오른쪽 자식만 있을 때
    else if(node->leftChild == nullptr){
        if(node->parent->leftChild == node) node->parent->leftChild = node->rightChild;
        else node->parent->rightChild = node->rightChild;
        node->rightChild->parent = node->parent;
    }
    // 왼쪽 자식만 있을 떄
    else if(node->rightChild == nullptr){
        if(node->parent->leftChild == node) node->parent->leftChild = node->leftChild;
        else node->parent->rightChild = node->leftChild;
        node->leftChild->parent = node->parent;
    }
    // 자식이 둘 다 있을 때
    else{
        Node* curNode = node->rightChild;
        // 삭제할 노드보다 큰 값 중 가장 작은 값을 찾을 때까지
        while(curNode->leftChild != nullptr){
            curNode = curNode->leftChild;
        }
        swap(node, curNode);
        if(node->parent->leftChild == node) node->parent->leftChild == nullptr;
        else node->parent->rightChild = nullptr;
    }
    delete node;
}
// 모든 원소의 출력, 중위 순회 방식
void binarySearchTree :: print(Node* node){
    if(node == nullptr) return;
    print(node->leftChild);
    cout << node->data;
    print(node->rightChild);
}
// 루트 반환
Node* binarySearchTree :: getRoot(){
    return root;
}

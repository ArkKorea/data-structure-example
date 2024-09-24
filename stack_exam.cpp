#include<iostream>
#include<vector>

using namespace std;

template <typename T>
class Stack{
private:
    T* arr;
    int sp;

public:
    Stack(){
        arr = new T[10000];
        sp = 0;
    }
    ~Stack(){
        delete[] arr;
    }
    void push(T data){
        if(sp < 10000) {
            arr[sp++] = data;
        }
        else cout << "Stack Overflow" << endl;
    }
    void pop(){
        if(sp > 0){
            arr[--sp] = 0;
        }
        else cout << "Stack Underflow" << endl;
    }
    int size(){
        return sp;
    }
    bool isEmpty(){
        return sp == 0 ? true : false;
    }
    T top(){
        return arr[sp-1];
    }
    int getSp(){
        return sp;
    }
};
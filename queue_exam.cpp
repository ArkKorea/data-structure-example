#include<iostream>
using namespace std;
// back, front, push, pop, size, empty, emplace, swap

template<typename T>
class queue{
private:
    T* arr;
    int fp;
    int bp;
    int q_size;
public:
    queue(){
        arr = new T[10000];
        fp = 0;
        bp = 0;
        q_size = 0;
    }
    T back(){
        return arr[bp-1];
    }
    T front(){
        return arr[fp];
    }
    void push(T data){
        if(q_size < 10000){
            arr[bp++] = data;
            q_size++;
        }
        else
           std::cout << "Queue Overflow" << std::endl;
    }
    void pop(){
        if(bp > fp){
            bp--;
            q_size --;
        }
    }
    int size(){
        return q_size;
    }
    bool empty(){
        return q_size == 0 ? true : false; 
    }
    void swap(int idx1, int idx2){
        T temp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = temp;
    }
};
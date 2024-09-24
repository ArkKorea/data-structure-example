#include<iostream>
#include<algorithm>
#include<vector>
/*
삽입
맨 마지막에 넣는다.
부모와 비교하며 부모보다 크면 값을 바꾼다.
삽입하려는 값보다 큰 값이 나오지 않을때까지 반복
루트보다 크면 루트 노드에 저장

삭제
맨 오른쪽 아래 노드를 루트로 위치
*/

//템플릿 정의는 cppreference.com 참고
template<class T,
         class Container = std::vector<T>,
         class Compare = std::less<typename Container::value_type>>

class priority_queue{
private:
    Container container;
    int num;
    Compare compare;

public:
    priority_queue(){
        num = 0;
        container.push_back(0);
    }

    bool empty(){
        return num ? false : true;
    }

    int size(){
        return num;
    }

    typename Container::value_type top(){
        return container[1];
    }

    void push(const typename Container::value_type& data){
        container.push_back(data);
        if(empty()){ // 처음에 아무것도 없을 때
            num++;
            return;
        }

        int idx = container.size() - 1, parent=0, child=0;
        while(idx > 1){
            child = idx;
            parent = idx / 2;
            if(container[parent] < container[child]){ // 부모가 자식보다 작을 때
                std::swap(container[parent], container[child]);
                idx = parent;
            }
            else break;
        }
        num++;
    }
    void heapify(const int& idx){
        int curIdx = idx;
        int left = idx * 2;
        int right = idx * 2 + 1;
        if(left <= container.size()-1 && container[curIdx] <= container[left]){
            curIdx = left;
        }
        if(right <= container.size()-1 && container[curIdx] <= container[right]){
            curIdx = right;
        }
        if(idx != curIdx){
            std::swap(container[idx], container[curIdx]);
            heapify(curIdx);
        }
    }

    void pop(){
        if(empty()){
            std::cout << "empty" << std::endl;
            return;
        }
        std::swap(container[1], container[num]);
        container.pop_back();
        heapify(1);
        num--;
    }
    void print(){
        for(int i = 1; i < container.size(); i++){
            std::cout << container[i] << " ";
        }
        std::cout << '\n';
    }
};

int main(){
    priority_queue<int> pq;

	pq.push(1);
	pq.push(2);
	pq.push(3);
	pq.push(4);
	pq.push(5);
	std::cout << pq.top()<<'\n';

	pq.print();

	pq.pop();
	std::cout << pq.top()<<'\n';
	pq.pop();
	std::cout << pq.top() << '\n';
	pq.pop();
	std::cout << pq.top() << '\n';

	pq.print();
}
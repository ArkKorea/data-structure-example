#include<iostream>
#include<vector>
#include<random>
using namespace std;

vector<int> vec = {30,80,90,70,50,20,60,10,40};

int partition(vector<int> vec, int left, int right){
    int pivot = vec[left];
    int low = left + 1;
    int high = right;
    while(low <= high){
        while(low <= right && vec[low] < pivot)
            low++;
        while(right >= low && vec[high] > pivot)
            high++;
        if(low < high)
            swap(vec[low], vec[high]);
        low++;
        high++;
    }
    swap(vec[left],vec[high]);
    return high;
}

void quickSort(vector<int> vec, int left, int right){
    if(left < right){
        int p = partition(vec, left, right);
        quickSort(vec, left, p - 1);
        quickSort(vec, p + 1, right);
    
    }
}

int main(){

    return 0;
}
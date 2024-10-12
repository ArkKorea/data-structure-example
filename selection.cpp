#include<iostream>
#include<vector>
#include<random>
#include<ctime>
using namespace std;
// n개 숫자에서 k번째 작은 수 찾기

int partition(vector<int> vec, int left, int right){
    srand(static_cast<unsigned int> (time(0)));
    int pivot = left + rand() % (right - left + 1);
    cout << pivot << endl;
    if(pivot != left) swap(vec[left], vec[pivot]);
    int l = left+1  , r = right;
    while(true) {
        while(vec[l] < vec[left] && l < right)
            l++;
        while(vec[r] > vec[left] && r > left)
            r--;
        if(l >= r) break;
        swap(vec[l], vec[r]);
        l++;
        r--;
    }
    swap(vec[left], vec[r]);
    return r;
}

int selection(vector<int> vec, int left, int right, int k){
    int p = partition(vec, left, right);
    int s = p - left;
    if(k < s) selection(vec, left, p-1,k);
    else if(k == s) return vec[p];
    else selection(vec, p+1, right, k-s-1);
}

int main(){
    vector<int> vec = {26,5,37,1,61,11,59,15,48,19,3,7,8};
    int k = 7;
    int result = selection(vec, 0, vec.size()-1, k-1);
    cout << result << endl;

}
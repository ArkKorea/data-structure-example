#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 여러 함수에 쓰이므로 전역변수로 선언
vector<int> vec = {3,2,5,7,4,8,6,9,1};

// 병합
void Merge(int low, int middle, int high) {
	vector<int> sortedVec(vec.size());
	int i = low;
	int j = middle + 1;
	int k = low;

	// 분할 벡터 합병
	while (i <= middle && j <= high) {
		if(vec[i] <= vec[j]){
			sortedVec[k++] = vec[i++];
		}
		else
			sortedVec[k++] = vec[j++];
	}

	// 뒷쪽 벡터의 값이 남았을 때
	if(i > middle){
		for(int idx = j; idx <= high; idx++)
			sortedVec[k++] = vec[idx];
	}
	// 앞 벡터의 값이 남았을 때
	else{ 
		for(int idx = i; idx <= middle; idx++)
			sortedVec[k++] = vec[idx];
	}

	// 기존 배열에 다시 넣어 재사용
	copy(sortedVec.begin()+low, sortedVec.begin()+high+1, vec.begin()+low);
}

void MS(int low, int high) {
	if (high <= low) return;
	int middle = (low + high) / 2;
	MS(low, middle);
	MS(middle + 1, high);
	Merge(low, middle, high);
}

int main() {
	int low = 0;
	int high = vec.size() - 1;
	cout << "before: ";
	for (int i : vec) // 정렬 전 배열 출력
		cout << i << " ";
	MS(low, high);
	cout << "\nafter: ";
	for (int i : vec) // 정렬 후 배열 출력
		cout << i << " ";

	return 0;
}
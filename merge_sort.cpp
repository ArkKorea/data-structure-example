#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ���� �Լ��� ���̹Ƿ� ���������� ����
vector<int> vec = {3,2,5,7,4,8,6,9,1};

// ����
void Merge(int low, int middle, int high) {
	vector<int> sortedVec(vec.size());
	int i = low;
	int j = middle + 1;
	int k = low;

	// ���� ���� �պ�
	while (i <= middle && j <= high) {
		if(vec[i] <= vec[j]){
			sortedVec[k++] = vec[i++];
		}
		else
			sortedVec[k++] = vec[j++];
	}

	// ���� ������ ���� ������ ��
	if(i > middle){
		for(int idx = j; idx <= high; idx++)
			sortedVec[k++] = vec[idx];
	}
	// �� ������ ���� ������ ��
	else{ 
		for(int idx = i; idx <= middle; idx++)
			sortedVec[k++] = vec[idx];
	}

	// ���� �迭�� �ٽ� �־� ����
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
	for (int i : vec) // ���� �� �迭 ���
		cout << i << " ";
	MS(low, high);
	cout << "\nafter: ";
	for (int i : vec) // ���� �� �迭 ���
		cout << i << " ";

	return 0;
}
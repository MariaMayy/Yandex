#include <iostream>
#include <vector>

using namespace std;

int Parent(int i) {
	return (i - 1) / 2;
}

int LeftChild(int i) {
	return 2 * i + 1;
}

int RightChild(int i) {
	return 2 * i + 2;
}

void Insert(int iNum, vector<int>& vHeap) {
	vHeap.push_back(iNum);
	int iPos = vHeap.size() - 1;

	// throwing an element up
	while (iPos > 0 && vHeap[iPos] < vHeap[Parent(iPos)]) {
		int tmp = vHeap[Parent(iPos)];
		vHeap[Parent(iPos)] = vHeap[iPos];
		vHeap[iPos] = tmp;

		iPos = Parent(iPos);
	}
}

int Extract(vector<int>& vHeap) {
	int iNum;
	iNum = vHeap.front(); // save root of heap
	vHeap.front() = vHeap.back(); // copy last right child to root
	vHeap.pop_back(); // delete last right child to root

	int i = 0;
	while (LeftChild(i) < vHeap.size()) {
		int iMinChild = LeftChild(i);

		if (RightChild(i) < vHeap.size() && vHeap[RightChild(i)] < vHeap[iMinChild]) {
			iMinChild = RightChild(i);
		}
		if (vHeap[i] <= vHeap[iMinChild]) break; // stop swapping

		int tmp = vHeap[iMinChild];
		vHeap[iMinChild] = vHeap[i];
		vHeap[i] = tmp;

		i = iMinChild;
	}

	return iNum;
}



int main()
{
	int N;
	cin >> N;
	vector<int> heap;

	for (int i = 0; i < N; i++) {
		int iNum;
		cin >> iNum;
		Insert(iNum, heap);
	}

	while (heap.size() > 0) cout << Extract(heap) << " ";
	
	return 0;
}

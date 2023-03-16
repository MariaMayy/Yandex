#include <iostream>
#include <vector>

using namespace std;


class Heap {
public:
	void Insert(int iNum);
	int Extract(); // heap of max (root is max element)
	
private:
	vector<int> vHeap;
	int Parent(int i);
	int LeftChild(int i);
	int RightChild(int i);
};


int Heap::Parent(int i) {
	return (i - 1) / 2;
}

int Heap::LeftChild(int i) {
	return 2 * i + 1;
}

int Heap::RightChild(int i) {
	return 2 * i + 2;
}

void Heap::Insert(int iNum) {
	vHeap.push_back(iNum);
	int iPos = vHeap.size() - 1;

	// throwing an element up
	while (iPos > 0 && vHeap[iPos] > vHeap[Parent(iPos)]) {
		int tmp = vHeap[Parent(iPos)];
		vHeap[Parent(iPos)] = vHeap[iPos];
		vHeap[iPos] = tmp;

		iPos = Parent(iPos);
	}
}

int Heap::Extract() {
	int iNum;
	iNum = vHeap.front(); // save root of heap
	vHeap.front() = vHeap.back(); // copy last right child to root
	vHeap.pop_back(); // delete last right child to root

	int i = 0;
	while (LeftChild(i) < vHeap.size()) {
		int iMaxChild = LeftChild(i);

		if (RightChild(i) < vHeap.size() && vHeap[RightChild(i)] > vHeap[iMaxChild]) {
			iMaxChild = RightChild(i);
		}
		if (vHeap[i] >= vHeap[iMaxChild]) break; // stop swapping

		int tmp = vHeap[iMaxChild];
		vHeap[iMaxChild] = vHeap[i];
		vHeap[i] =tmp;

		i = iMaxChild;
	}

	return iNum;
}



int main()
{
	int N;
	cin >> N;
	Heap heap;

	for (int i = 0; i < N; i++) {
		int cmd;
		cin >> cmd;
		if (cmd == 0) {
			int iNum;
			cin >> iNum;
			heap.Insert(iNum);
		}
		else if (cmd == 1) {
			cout << heap.Extract() << endl;
		}
	}

	return 0;
}

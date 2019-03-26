
//大顶堆的实现
//make_heap实现

#include<iostream>
#include<vector>
#include<ctime>
#include<assert.h>
#include<cstring>
#include<cstdlib>

using namespace std;

template<class Item>
class MaxHeap
{
public:
	MaxHeap(int capacity) {
		data = new Item[capacity + 1];
		count = 0;
		this->capacity = capacity;
	}
	MaxHeap(Item a[], int n) {
		data = new Item(n + 1);
		capacity = n;
		for (int i = count / 2; i >= 1; i--)
			shiftDown(i);
	}
	~MaxHeap() {
		delete[] data;
	}
	void insert(Item item) {
		assert(count + 1 <= capacity);
		data[++count] = item;
		shiftUP(count);
	};
	Item getMax() {
		assert(count > 0);
		Item item = data[1];
		swap(data[1], data[count]);
		--count;
		shiftDown(1);
		return item;
	}
	void heapSort(Item *out_array) { //堆排序，排序完的结果放入out_array中，且堆的size变为0（已不为堆）；
		int len = count;			//纯粹为了练手，这种写法有点多余，使用memcpy速度更快
		while (!isEmpty())
			getMax();
		memcpy(out_array, &data[1], len*sizeof(data[1]));
	}
	void printData() {
		cout << "heap's size:" << count<<endl;
		for (int i = 1; i <= count; i++)
			cout << data[i] << " ";
		cout << endl;
	/*	while (!isEmpty()) {
			cout << getMax() << " ";
		}*/
	}
	
	int size() {
		return this->count;
	}
	bool isEmpty() {
		return this->count == 0;
	}
private:
	Item* data;
	int count;
	int capacity;
	void shiftUP(int k) {   //向上调整
		while (k > 1 && data[k] > data[k / 2]) {
			swap(data[k], data[k / 2]);
			k /= 2;
		}
	}
	void shiftDown(int k) { //向下调整
		while (2 * k <= count) {
			int j = 2 * k;
			if (j + 1 <= count && data[j] < data[j + 1])
				++j;
			if (data[k] > data[j])
				break;
			swap(data[k], data[j]);
			k = j;
		}
	}

};

int main() {
	MaxHeap<int> maxheap = MaxHeap<int>(100);
	srand(time(NULL));
	for (int i = 0; i < 16; i++)
		maxheap.insert(rand() % 100);
	int a[16];
	maxheap.printData();
	maxheap.heapSort(a);
	for (int i = 0; i < 16; i++)
		cout << a[i] << " ";
}



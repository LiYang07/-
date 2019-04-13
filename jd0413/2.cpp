#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int main() {
	vector<int> iv;
	int size;
	cin >> size;
	for (int i = 0; i < size; i++) {
		int n;
		cin >> n;
		iv.push_back(n);
	}
	if (iv.size() <= 1) {
		cout << 0;
		return 0;
	}
	int count = 0;
	while (1) {
		if (iv[0] != 1 && iv[0]!=size) {
			int temp = iv[0];
			int i = 0;
			while (iv[++i] - temp !=- 1) {}

			if (i == 1) {
				count++;
				swap(iv[0], iv[1]);
				continue;
			}
				for (int j = 0; j <= i - 2; j++)
						iv[j] = iv[j + 1];
				iv[i-1] = temp;
				count++;
		}
		else if (iv[0] == size) {
			int i = 0;
			while (size-iv[++i] != 1) {}
				if (i == 1) {
					count++;
					swap(iv[0], iv[1]);
					continue;
				}
				for (int j = 0; j <= i - 1; j++)
					iv[j] = iv[j + 1];
				iv[i] = size;
				count++;
			}
		else {
			int k = 0;
			for (; k < size; k++)
				if (iv[k] != k + 1)
					break;
			if (k == size) {
				cout << count;
				break;
			}
			else {
				int min = size + 1, pos = k;;
				for (int p = k; p < size; p++)
					if (iv[p] < min) {
						min = iv[p];
						pos = p;
					}
				for (int j = 0; j <= pos - 2; j++)
					iv[j] = iv[j + 1];
				iv[pos - 1] = 1;
				count++;
			}

		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}
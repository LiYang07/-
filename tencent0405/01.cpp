#include<iostream>
#include<vector>
#include<set>

using namespace std;
//第一个版本仅考虑了例图输入中的特殊情况
//未考虑当curmax满足要求时是否能连续建设的问题

// int main() {

// 	int T;
// 	cin >> T;
// 	vector<vector<int> > data;
// 	for (int i = 0; i < T; i++) {
// 		int n;
// 		cin >> n;
// 		int s;
// 		vector<int > iv;
// 		for (int j = 0; j < n; j++) {
// 			cin >> s;
// 			iv.push_back(s);
// 		}
// 		data.push_back(iv);
// 	}
// 	for (int i = 0; i < T; i++) {
// 		int curmax = data[i].size(),count=1;
// 		for (int j = 0; j < data[i].size(); j++) {
// 			if (data[i][j] == curmax) {
// 				int out = curmax;
// 				for (int k = 1; k <= count; k++) {
// 					cout << out;
// 					cout << " ";
// 					--out;
// 				}
// 				cout << endl;
// 				curmax-=count;
// 				count=1;
// 			}
// 			else {
// 				count++;
// 				cout << endl;
// 			}
				
// 			}
// 		cout << endl;

// 		}

// }

int main() {

	//输入不变
	int T;
	cin >> T;
	vector<vector<int> > data;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		int s;
		vector<int > iv;
		for (int j = 0; j < n; j++) {
			cin >> s;
			iv.push_back(s);
		}
		data.push_back(iv);
	}
	//用set来管理目前等待建设的模块
	set<int> wating_set;
	for (int i = 0; i < T; i++) {
		int curmax = data[i].size();
		for (int j = 0; j < data[i].size(); j++) {
			if (data[i][j] == curmax) { //如果可以修，则输出，并从set中找还能不能继续修建
				cout << curmax << " ";
				while (wating_set.find(--curmax) != wating_set.end())
				{
					cout << curmax << " ";
				}
				if (curmax != 0) //修改了这里
					cout << endl;
			}
			else { //如果不能修（更下面的还没修）,则将其放入set中
				wating_set.insert(data[i][j]);
				cout << endl;
			}

		}
	}

}
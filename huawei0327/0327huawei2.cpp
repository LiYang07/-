//蜂群要离开蜂巢采蜜，连续采集五片花丛A B C D E后归巢
//为蜂群规划最短的路径
//输入例子：200 0 200 10 200 50 200 30 200 25，输出 456（整数，舍去运算结果所有小数位）
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	vector<pair<int, int> > points;
	int x, y;
	points.push_back(make_pair(0, 0));
	while (cin >> x && cin >> y)
	{
		points.push_back(make_pair(x, y));
	}
	for (auto item : points)
		cout << item.first << " " << item.second << endl;
	double a[6][6]; //图的邻接矩阵
	for(int i=0;i<6;i++)
		for (int j = 0; j < 6; j++) {
			if (i == j) {
				a[i][j] = 0;
				continue;
			}
			a[i][j] = sqrt(pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2));
		}
	int answer = INT32_MAX;
    //暴力搜索法，将所有以原点开始的环遍历一遍
	for (int i = 1; i < 6; i++)
	{
		for (int j = 1; j < 6; j++) {
			if (j == i)continue;
			for (int k = 1; k < 6; k++) {
				if (k == i || k == j)continue;
				for (int l = 1; l < 6; l++) {
					if (l == i || l == j || l == k)continue;
					for (int m = 1; m < 6; m++) {
						if (m == i || m == j || m == k||m==l)continue;
						answer = min(answer, int(a[0][i] + a[i][j] + a[j][k] + a[k][l] + a[l][m] + a[m][0]));
					}
						
						
				}
					
			}
				
		}
			
	}		
	cout << answer << endl;
}

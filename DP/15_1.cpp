//算法导论15.1钢条分割问题
//长度i     1  2  3  4  5  6  7  8  9  10
//价格Pi    1  5  8  9  10 17 17 20 24 30
//给定一个长度的钢条，获取最高售价的分割

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int  memoized_cut_rod_aux(vector<int>& p, int n, vector<int>& r);
//自顶向下递归实现
int memoized_cut_rod(vector<int>& p, int n) {
	vector<int> r(n+1, -1);            //存储各子问题最优解
	return memoized_cut_rod_aux(p, n, r);


}

int  memoized_cut_rod_aux(vector<int>& p, int n, vector<int>& r) {
	if (r[n] > 0)
		return r[n];
	int q;
	if (n == 0)
		q = 0;
	else {
		q = -1;
		for (int i = 1; i <= n; i++)
			q = max(q, p[i-1] + memoized_cut_rod_aux(p, n - i, r));

	}
	r[n] = q;
	return q;
}

//自底向上实现
int bottonm_up_cut_rod(const vector<int> &p,int n){
    vector<int> r;
    r.push_back(0);
    for(int j=1;j<=n;j++){
        int q=-1;
        for(int i=1;i<=j;i++)
            q=max(q,p[i-1]+r[j-i]); //根据r[0]得到r[1],根据r[1]，r[0]得到r[2]
        r.push_back(q);
    }
    return r[n];
}


int main() {
	vector<int> p = { 1,5,8,9,10,17,17,20,24,30 };
	for (int i = 1; i <= 10; i++){
        cout << memoized_cut_rod(p,i) << endl;
        cout << bottonm_up_cut_rod(p,i) << endl;
    }
	return 0;
}
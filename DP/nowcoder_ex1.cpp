// 给你六种面额1、5、10、20、50、100元的纸币，假设每种币值的数量都足够多，编写程序求组成N员（N为0-10000的非负整数）的不同组合的个数。
// 输入描述:
// 输入为一个数字N，即需要拼凑的面额
// 输出描述:
// 输出也是一个数字，为组成N的组合个数。


//解法：
//构建dp表格
// dp表格
//           	    0	1	2	3	4	5	6	7	8	9	10

// 1元	          1	1	1	1	1	1	1	1	1	1	1
// 1元,5元	       1	1	1	1	1	2	2	2	2	2	3
// 1,元，5元，10元 1	1	1	1	1	2	2	2	2	2	4
// 1,5,10，20元	 	 	 	 	 	 	 	 	 	 	 
// ,1,5,10,20，50元	 	 	 	 	 	 	 	 	 	 	 
// ,1,5,10,20，50，100元	 	 	 	 	 	 	 	 	 	 	 
//dp[2,5]=dp[1,5]+dp[2,5-5]
//dp[3,10]=dp[2,10]+dp[3,10-10],dp[]

//参考python代码：
#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n+1, 0);
	a[0] = 1;
	vector<int> money = { 1,5,10,20,50,100 };
	for (int i = 0; i < money.size(); i++) {
		for (int j = 0; j <= n; j++)
			if (j >= money[i]) {
				a[j] =a[j]+a[j - money[i]];
			}
	}
   cout<<a[n];

}
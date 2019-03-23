// 题目来源：《剑指offer》
// HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
// 今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
// 但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
// 例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。你会不会被他忽悠住？(子向量的长度至少是1)

//思路：设F(i)为以array[i]结尾的最大子串,那么F(i)=max(array[i],F(i-1)+array[i])

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//这种写法不行：

// long get_max_sub_aux(const vector<int>& nums,int i, vector<long>& r);

// long get_max_sub(const vector<int>& nums){
//     vector<long > r;
//     get_max_sub_aux(nums,nums.size()-1,r);
//     for(auto i:r)
//         cout<<i<<endl;
//     return(*max(r.begin(),r.end()));
// }

// long get_max_sub_aux(const vector<int>& nums,int i, vector<long>& r){
//     long q;
//     if(i==0)
//         q=nums[i];
//     else{
//         q=max(long(nums[i]),nums[i]+get_max_sub_aux(nums,--i,r));
//     }
//     r.push_back(q);
//     return r[i];
    
// }

int main(){
    vector<int> nums={6,-3,-2,7,-15,1,2,2};
  //  cout<<get_max_sub(nums);
  get_max_sub(nums);
}


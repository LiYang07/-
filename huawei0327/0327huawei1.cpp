#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
int n;
cin>>n;
string code;
cin>>code;
vector<string> out;
for(int i=0;i<n;i++){
if(code[9*i]=='1')
out.push_back(code.substr(9*i+1,8));
else
{
string substr=code.substr(9*i+1,8);
reverse(substr.begin(),substr.end());
out.push_back(substr);
}
}
for(auto i:out)

cout<<i<<" ";
}
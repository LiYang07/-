//C和指针第七章递归的例子
//教科书中常用的递归例子，求阶乘和斐波那契列是不好的例子，尤其是后者效率极低，f(n)=f(n-1)+f(n-2)将导致大量的重复计算

//例子：将一个整数转换为字符并打印它，利用递归的主要优势是可以按高位到低位的顺序清楚打印出
//用C++改写为将整形转换为字符串的函数

#include<iostream>
#include<string>

using namespace std;

void int_to_str( int n, string &output_string ){
    if(n<0){
        output_string.push_back('-');
        n = -n;
    }
    int quotient;
    quotient = n / 10;
    if(quotient != 0)
        int_to_str(quotient,output_string);
    output_string.push_back('0'+n%10);
}

int main(){
    string s("");
    int_to_str(-10248,s);
    cout<<s<<endl;
}
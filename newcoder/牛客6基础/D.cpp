#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[100005],b[100005],c[100005];
int main(){
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];
    sort(a+1 , a+n+1);
    sort(b+1 , b+n+1);
    //第k大的值肯定在
    for(int i = n-k+1;i <= n;i++) c[i-(n-k+1)] = a[i] + b[n-(i-(n-k+1))];
    sort(c,c+k);
    cout << c[0];
}


    //双指针好像不可以
    //新的n个数列的第k个要是最大的
    //两个指针可不可以得到全部的数列？？
    //好像可以
    //双指针的话，一个保持不变，一个++，超过就回到第一个，
    //1 2 3
    //p   ->
    //1 2 3
    //    p
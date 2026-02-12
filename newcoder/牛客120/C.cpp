#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    int n,m;
    cin >> n >>m;
    //只能分类讨论了
     if (n == 1 || m == 1)  cout << 1 << endl;
     //只可以往一个方向跳到不可以跳
    else if (n == 2)    cout << (m - 1) / 2 + 1 << endl;
    else if (m == 2) cout << (n - 1) / 2 + 1 << endl;
    else if (n == 3 && m == 3)  cout << 8 << endl;
    //棋盘大了哪里都可以跳
    else cout << n * m << endl;
}
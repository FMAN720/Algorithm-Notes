#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long//这里记得加long long
const int MOD=1e9+7;
int quick(int x,int y){
    int result=1;
    while(y!=0){
    if(y&1)result=((result%MOD)*x)%MOD;
    x=(x*x)%MOD;//这里也要取模，真该死啊啊啊啊啊啊啊啊
    y>>=1;
    }
    return result%MOD;
}
void solve(){
int n;
cin>>n;
cout<<quick(2,n/2)%MOD<<endl;
}
signed main(){
    int t=1;
    while(t--)solve();
}
//https://ac.nowcoder.com/acm/contest/126120/E
//这里的公式就是i~j的mex
//例如：
//p1,[p1,p2] [p1,p2,p3]
//p2 [p2,p3]
//p3
/*暴力出奇迹，打表找规律
  0 1 2 3 4 
  根据之前的规律：0放到中间是最优的，当0放到中间的时候可以让最多的排列接触到0，就不至于mex的结果是0
  0放完之后就是1，要让足够多的排列接触到1。
  1完就是2，2完就是3，，，，，，
  5 3 1 0 2 4---->这个就是最优秀的解的答案，把这个答案求出来，之后打表找规律
*/
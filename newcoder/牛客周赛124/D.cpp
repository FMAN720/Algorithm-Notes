#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve(){
int n,ans=0;
cin>>n;
int a[n+1]={0};
for(int i=1;i<=n-1;i++){
    int x,y;
    cin>>x>>y;
    a[x]++;
    a[y]++;
}
for(int i=1;i<=n;i++){
    if(a[i]==1)ans++;
}
cout<<(ans+1)/2<<endl;
}
signed main(){
    int t=1;
    while(t--)solve();
}
//https://ac.nowcoder.com/acm/contest/126120/D
/*题解如下
        o
      /   \
     o    o
    / \
    o
     \
     o
按照题目的意思就是：要让这个树是连通的，就是不可以出现一个叶子。
叶子的意思就是只有一个度，也就是没有额外连别的东西，这种叶子一定要消失，不然任意去掉一个线，
如果去掉的就是这个叶子的那个线，那么这个图像就不联通了，
所以有几个叶子，叶子的数量除以2，向上取整就可以。
*/
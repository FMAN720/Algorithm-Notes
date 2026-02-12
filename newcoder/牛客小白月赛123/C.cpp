#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,m;
vector<int>a;
bool check(int x){
    int t=0,sum=0;
    for(int i=1;i<n;i++){
       if(a[i]>a[i-1])continue;
       else{
         t=a[i-1]+1-a[i];
         sum+=(t+x-1)/x;
       }
    }
    return sum<=m;
}
void solve(){
    //int n,m;
    cin>>n>>m;
    a.assign(n,0);
    //vector<int>a(n);
    //a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];
    bool find=false;
    for(int i=1;i<n;i++){
        if(a[i-1]>=a[i]){
        find=true;
        break;}
    }
    if(!find){
        cout<<"0"<<endl;
        return ;
    }
    //这里不可以把这个m==0的特判放到a.ssign(n,0)后面，
    //因为就算m==0，当他本来就是严格递增的时候，因该输出的是0
    if(m==0){
    cout<<"-1"<<endl;
    return ;}
    int l=1,r=2e9,ans=-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;
}
signed main(){
int t;
cin>>t;
while(t--)solve();
}
//思路解析：
/*这里用二分是本来就可以想到的，但是没有完全想到
这里的思路就是，当位置为i的数字小于位置i-1的时候，最少要加到a[i-1]+1
所以要加的次数就是(a[i-1]+1-a[i]+x-1)/x
这里的+x-1是向上取整的意思，这个很容易理解


这里的加意思是，从位置i到结尾都加上这么多次的x，避免了回头看，就是前面本来比后面小的数，加着加着就
比后面大了，所以就大家一起加，保持i后面的情况不变，让i之前变成严格递增，一点一点推进

贪心


这里有一点前缀和的味道，
，分析 2 2 1 3 2这个例子
2要大于2，至少加上一个2，后面所有的数字都加上一个2
1要大于2至少加上一个2，，后面所有的数字再加一个2，前面已经有了一个1，所以是1+1
后面的2要大于3，至少还是一个2，但是前面已经有了1+1了，所以1+1+1，满足条件
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    //后面和前面都要扫一遍
    //1 2 3 _ 5 6 7--->如果只前扫的话，就只有pre[2]=3 pre[3]=1,
    //再从后扫一遍就有back[3]=3这样就可以前后相加
    vector<int>pre(n+1,1);
    for(int i=1;i<n;i++){
        if(a[i]-a[i-1]==1)pre[i]=pre[i-1]+1;
    }
    vector<int>back(n+1,1);
    for(int i=n-2;i>0;i--){
        if(a[i+1]-a[i]==1)back[i]=back[i+1]+1;
    }
    for(int i=0;i<n;i++){
        if(pre[i]>=m-1||back[i]>=m-1){cout<<"YES"<<endl;return ;}
        else if(a[i+1]-a[i]==2&&pre[i]+back[i+1]>=m-1){cout<<"YES"<<endl;return;}
    }
    cout<<"NO"<<endl;
}
signed main(){
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
using ll=long long;
typedef unsigned long long ull;
//就是有几个点是直角三角形
void solve(){
   int n,ans=0;
   cin>>n;
   vector<vector<int>>point(n,vector<int>(2));
   vector<int>cnt1(n+1);//y为1的点
   vector<int>cnt0(n+1);//y为0的点
   for(int x=0;x<n;x++){
    for(int y=0;y<=1;y++){
        cin>>point[x][y];
    }
   }
   for(int i=0;i<n;i++){
    if(point[i][1]==0)cnt0[point[i][0]]++;
    else cnt1[point[i][0]]++;
   }
   for(int i=0;i<=n;i++){
    if(cnt1[i]&&cnt0[i])ans+=n-2;
    if(i-2>=0&&cnt1[i]&&cnt1[i-2]&&cnt0[i-1])ans++;
    if(i-2>=0&&cnt0[i]&&cnt0[i-2]&&cnt1[i-1])ans++;
   }
   cout<<ans<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}

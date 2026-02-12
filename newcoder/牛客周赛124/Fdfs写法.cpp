#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n';
const int op=510;
int dp[op][op];
int a[op];
int n;
string ac;
int dfs(int l,int r){
    if(l>r)return 0;
    if((r-l+1)&1)return 1e18;
    if(dp[l][r]!=-1)return dp[l][r];
    dp[l][r]=1e18;
    for(int i=l+1;i<=r;i++){
        if(ac[i]==ac[l]){
            dp[l][r]=min(dp[l][r],a[l]*a[i]+dfs(l+1,i-1)+dfs(i+1,r));
        }
    }
    return dp[l][r];
}
inline void solve(){
    cin>>n;
    cin>>ac;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=dfs(0,n-1);
    if(ans>=1e18)ans=-1;
    cout<<ans<<endl;
}
signed main(){
    int t;cin>>t;
    while(t--)solve();
}
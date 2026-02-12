#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
void solve(){
int n,ans=0;
cin>>n;
vector<int>cnt(n+2);
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    if(cnt[x]>=cnt[x-1])ans++;
    if(cnt[x+1]>cnt[x])ans--;
    cnt[x]++;
    cout<<ans<<" ";
}
}
//不用过多解释，理解了就很简单，，，，，
//思维题啊
signed main(){
    int t=1;
    while(t--)solve();
}

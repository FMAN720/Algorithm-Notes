#include<bits/stdc++.h>
using namespace std;
void solve(){
    int ans=0,n;
    cin >> n;
    vector<bool> vis(n+2,false);
    for (int i=1;i<=n;i++) {
        int t;
        cin >> t;
        if (vis[t+1] && vis[t-1]) ans--;
        if (!vis[t+1] && !vis[t-1]) ans++;
        vis[t]=true;
        cout<<ans<<" ";
    }
    cout<<endl;
}
signed main(){
int t=1;
while(t--)solve();
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD=998244353;
const int MAX=2e5+10;
void solve(){
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    sort(a.begin(),a.end(),greater<int>());
    int w=0;
    for(int i=0,j=0;i<n&&j<n;){
        if(a[i]>b[j]){
            w++;
            i++;
        }else{
            j++;
        }
    }
    int ans=1;
    for(int i=1;i<=w;i++){
        ans=(ans*i)%MOD;
    }
    for(int i=1;i<=n-w;i++){
       ans=(ans*i)%MOD;
    }
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)solve();
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int maxx=max(a[0]+k,a[n-1]+k);
    for(int i=1;i<n;i++){
        maxx=max(maxx,a[i-1]+a[i]);
    }
    cout<<maxx<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}
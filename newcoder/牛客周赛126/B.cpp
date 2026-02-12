#include<bits/stdc++.h>
using namespace std;
#define int long long
using ll=long long;
void solve(){
int n,k;
cin>>n>>k;
vector<string>a(n+1);
for(int i=1;i<=n;i++)cin>>a[i];
sort(a.begin(),a.end());
if(a[k]==a[k+1])cout<<"-1"<<endl;
else cout<<a[k]<<endl;
}
signed main(){
int t=1;
while(t--)solve();
}
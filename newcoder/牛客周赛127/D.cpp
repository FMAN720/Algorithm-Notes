#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
using ll=long long;
typedef unsigned long long ull;
const int mod=998244353;
void solve(){
int n;
cin>>n;
vector<int>a(n),num(n+1);
for(int i=0;i<n;i++){
    cin>>a[i];
    num[a[i]]++;
}
int y=1,x=0;
for(int i=1;i<=n;i++){
   y*=num[i]*(num[i]-1)/2%mod;
   y=y%mod;
   x=(x+y)%mod;
}
cout<<x<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}
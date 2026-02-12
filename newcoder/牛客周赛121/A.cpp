#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve(){
int a,b,c,n,ans=0;
cin>>a>>b>>c>>n;
ans+=a*n;
if(n<=b)ans-=c;
cout<<ans<<endl;
}
signed main(){
    int t=1;
    while(t--)solve();
}
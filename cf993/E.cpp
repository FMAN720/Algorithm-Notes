#include<bits/stdc++.h>
using namespace std;
#define int long long
using ll=long long;
typedef unsigned long long ull;
void solve(){
        ll k,l1,r1,l2,r2;
        cin>>k>>l1>>r1>>l2>>r2;
        ll kn=1,ans=0;
        for(int n=0;r2/kn>=l1;n++)
        {
            ans+=max(0ll,min(r2/kn,r1)-max((l2-1)/kn+1,l1)+1ll);
            //luogu题解很清楚，推公式而已，要注意的就是向上取整和向下取整
            //取两集合之间的交集，相减加一
            kn*=k;
        }
        cout<<ans<<'\n';
    }
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}
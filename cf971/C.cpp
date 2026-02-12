#include<bits/stdc++.h>
using namespace std;
#define int long long
using ll=long long;
typedef unsigned long long ull;
void solve(){
   int x,y,k;
   cin>>x>>y>>k;
   int x_time=(x+k-1)/k;
   int y_time=(y+k-1)/k;
   //don't use the fucking ceil
   //int x_time=ceil(x/k);
   //int y_time=ceil(y/k);
   if(x_time>y_time)cout<<x_time*2-1<<endl;
   else cout<<y_time*2<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}

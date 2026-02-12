#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
int a,b,c;
cin>>a>>b>>c;
if(c!=a+b&&c!=a-b&&c!=a*b&&(c!=a/b||a%b!=0))cout<<"No"<<endl;
else cout<<"Yes"<<endl;
}
signed main(){
int t=1;
while(t--)solve();
}
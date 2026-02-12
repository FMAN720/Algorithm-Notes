#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
void solve(){
int a[14],b[14],cnt=0;
for(int i=1;i<=13;i++)cin>>a[i];
for(int i=1;i<=13;i++){
cin>>b[i];
if(a[i]+b[i]>4)cnt+=a[i]+b[i]-4;
}
cout<<cnt<<endl;
}
signed main(){
int t=1;
while(t--)solve();
}
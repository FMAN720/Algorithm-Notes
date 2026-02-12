#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
void solve(){
int n1,n2;char c1,c2;
cin>>n1>>c1;
cin>>n2>>c2;
if(n1>n2)cout<<"Yes"<<endl;
else if(n1<n2)cout<<"No"<<endl;
else{
    if(c1<c2)cout<<"Yes"<<endl;
    else{
        cout<<"No"<<endl;
    }
}
}
signed main(){
int t=1;
while(t--)solve();
}
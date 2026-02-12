#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll=long long;
void solve(){
ll n,sum=0;
cin>>n;
ll min_num=1e9+19;
vector<ll>a(n+1);
for(int i=1;i<=n;i++)cin>>a[i];
for(int i=1;i<=n;i++){
    if(a[i]!=0)min_num=min(min_num,a[i]);
    else{
    if(min_num!=1e9+19){
    sum+=min_num;
    min_num=1e9+19;
    }
    } 
}
if(a[n]!=0)sum+=min_num;
cout<<sum<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}
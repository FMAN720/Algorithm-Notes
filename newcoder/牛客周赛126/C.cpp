#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
using ll=long long;
int QuickSum(int x,int y){
    int temp=1;
    while(y!=0){
        if(y&1)temp*=x;
        x*=x;
        y>>=1;
    }
    return temp;
}
void solve(){
    int n,k,start=1;
    cin>>n>>k;
    if((n-k)%2!=0){cout<<"-1"<<endl;return ;}
    for(int i=1;i<=n-k;i++)cout<<start<<" ";
    for(int i=1;i<=k;i++)cout<<++start<<" ";
    cout<<endl;
}
signed main(){
int t=1;
while(t--)solve();
}


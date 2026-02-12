#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve(){
    int n;
    cin>>n;
    if(n==1){
        cout<<"YES"<<endl;
        cout<<"1"<<endl;
    }
    else if(n==3){
        cout<<"YES"<<endl;
        cout<<"1 2 3"<<endl;
    }
    else cout<<"NO"<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}
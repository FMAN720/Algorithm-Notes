#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve(){
int n,q;
cin>>n>>q;
//vector<int>a(n);
int a[n];
for(int i=0;i<n;i++)cin>>a[i];
sort(a,a+n);
while(q--){
    int k,x;
    cin>>k>>x;
    if(lower_bound(a,a+n,x)-a>=k){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
}
}
signed main(){
int t=1;
//cin>>t;
while(t--)solve();
}
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
//3 1 4 5 2
void solve(){
    int n;
    cin>>n;
    vector<int>a;
    int x1;
    cin>>x1;
    a.push_back(x1);
    for(int i=1;i<n;i++){
        int x2;
        cin>>x2;
        if(x2<a.back())continue;
        else a.push_back(x2);
    }
    cout<<n-a.size()<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}
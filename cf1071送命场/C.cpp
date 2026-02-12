#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr.begin(),arr.end());
    cout<<max(arr[0],arr[1]-arr[0])<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}
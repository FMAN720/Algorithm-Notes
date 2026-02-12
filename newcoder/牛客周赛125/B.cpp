#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define endl '\n'
void solve(){
int n;
cin>>n;
vector<int>a(n);
for(int i=0;i<n;i++)cin>>a[i];
for(int i=1;i<n-1;i++){
    if(a[i]>a[i-1]&&a[i]>a[i+1])a[i]=max(a[i-1],a[i+1]);
}
for(int i=0;i<n;i++)cout<<a[i]<<" ";
cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
using ll=long long;
typedef unsigned long long ull;
void solve(){
string a,b;
cin>>a>>b;
if(stoi(a)==stoi(b)&&a.length()>b.length())cout<<"Yes"<<endl;
else if(stoi(a)>stoi(b))cout<<"Yes"<<endl;
else cout<<"No"<<endl;
}
signed main(){
    int t=1;
    cin>>t;
    while(t--)solve();
}
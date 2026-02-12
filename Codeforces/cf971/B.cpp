#include<bits/stdc++.h>
using namespace std;
#define int long long
using ll=long long;
typedef unsigned long long ull;
void solve(){
   int n;
   cin>>n;
   vector<string>s(n+1);
   for(int i=1;i<=n;i++)cin>>s[i];
   for(int i=n;i>=1;i--){
    int k=s[i].length();
    for(int j=0;j<k;j++){
        if(s[i][j]=='#')cout<<j+1<<" ";
    }
   }
   cout<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}

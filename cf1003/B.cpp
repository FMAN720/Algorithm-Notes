#include<bits/stdc++.h>
using namespace std;
#define int long long
#define enld '\n'
void solve(){
    string s;
    bool find=false;
    cin>>s;
    int n=s.length();
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){cout<<"1"<<endl;
        find=true;
        break;}
    }
    if(!find)cout<<n<<endl;
}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
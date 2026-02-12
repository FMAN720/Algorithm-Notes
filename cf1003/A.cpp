#include<bits/stdc++.h>
using namespace std;
#define int long long
#define enld '\n'
void solve(){
string s;
cin>>s;
int n=s.length();
if(s[n-2]=='u'&&s[n-1]=='s'){
    s[n-2]='i';
    s.resize(n-1);
}
cout<<s<<endl;
}
signed main(){
int t=1;
cin>>t;
while(t--)solve();
}
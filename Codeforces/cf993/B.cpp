#include<bits/stdc++.h>
using namespace std;
using ll=long long;
typedef unsigned long long ull;
#define endl '\n'
void solve(){
string s;
cin>>s;
for(int i=s.length()-1;i>=0;i--){
    if(s[i]=='w')cout<<s[i];
    else if(s[i]=='q')cout<<char(s[i]-1);
    else cout<<char(s[i]+1);
}
cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}
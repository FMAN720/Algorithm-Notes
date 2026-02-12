#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    string s;
    cin>>s;
    string ts=s;
    reverse(ts.begin(),ts.end());
    if(ts>s)cout<<"right"<<endl;
    else if(ts<s)cout<<"left"<<endl;
    else cout<<"equal"<<endl; 
}
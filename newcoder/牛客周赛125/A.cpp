#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll=long long;
void solve(){
    string s;
    cin>>s;
    string s2="ABC";
    if(s==s2)cout<<"4"<<endl;
    else if(s2.find(s)!=string::npos)cout<<"2"<<endl;
    else cout<<"0"<<endl;
}
int main(){
    int t=1;
    while(t--)solve();
}
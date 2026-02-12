#include<bits/stdc++.h>
using namespace std;
using ll=long long;
typedef unsigned long long ull;
#define endl '\n'
void solve(){
int m,a,b,c;
cin>>m>>a>>b>>c;
int monk1=min(m,a);
int monk2=min(m,b);
int monk3=min(2*m-monk1-monk2,c);
cout<<monk1+monk2+monk3<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x==1||x==2||x==4||x==5)cout<<"Kato_Shoko"<<endl;
        else{cout<<"koishiYun"<<endl;}
    }
}
signed main(){
    int t=1;
    while(t--)solve();
}
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt=0,max_n=-1;
    for(int i=0;i<n;i++){
        if(s[i]=='0')cnt++;
        else {max_n=max(max_n,cnt);cnt=0;}
    }
    for(int i=0;i<n;i++){
        if(s[i]=='0')cnt++;
        else {max_n=max(max_n,cnt);cnt=0;}
    }
    cout<<max_n<<endl;
}//再遍历一遍数组是为了解决头尾0的问题
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}
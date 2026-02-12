#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int change(int x){
    string s=to_string(x);
    reverse(s.begin(),s.end());
    return stoll(s);
}
void solve(){
    int l,r;
    cin>>l>>r;
    int maxx=change(r);
    int start=1;
    for(int i=1;i<=16;i++){
        start*=10;
        int cur=r/start*start-1;
        if(cur<l)break;
        if(cur>=l&&cur<=r){
            maxx=max(maxx,change(cur));
        }
    }
    cout<<maxx<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}
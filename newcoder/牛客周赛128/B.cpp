#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct cake{
    int x;
    int y;
    int idex;
};
void solve(){
    cake a[4];
    for(int i=1;i<=3;i++){
        cin>>a[i].x>>a[i].y;
        a[i].idex=i;
    }
    sort(a+1,a+4,[](cake a,cake b){
        if(a.x!=b.x)return a.x>b.x;
        return a.y>b.y;
    });
    cout<<a[2].idex<<endl;
}
signed main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
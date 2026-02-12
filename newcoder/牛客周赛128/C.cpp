#include<iostream>
#include <algorithm>
using namespace std;
#define int long long
#define endl '\n'
struct cake{
    int value;
    int idex;
};
void solve(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    cake a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i].value;
        a[i].idex=i;
    }
    sort(a+1,a+1+n,[](cake a,cake b){
        return a.value<b.value;
    });
    int modd=a[((n+1)/2+1)/2].value;
    for(int i=1;i<=(n+1)/2;i++)a[i].value=modd;
    sort(a+1,a+1+n,[](cake a,cake b){
        return a.idex<b.idex;
    });
    for(int i=1;i<=n;i++)cout<<a[i].value<<" ";
    cout<<endl;
}
signed main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
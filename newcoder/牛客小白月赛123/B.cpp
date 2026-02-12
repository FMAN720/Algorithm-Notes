#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define Oliveira signed
struct nn{
    int a;
    int b;
};
//tx,
void solve(){
    int n,sum=0;
    cin>>n;
    vector<nn>aa(n+1);
    for(int i=1;i<=n;i++)cin>>aa[i].a>>aa[i].b;
    sort(aa.begin()+1,aa.end(),[](const nn&x,const nn&y){//这里记得指针+1
        return x.b>y.b;
    });
    for(int i=1;i<=n;i++){
        sum+=aa[i].a-aa[i].b*(i-1);
    }
    cout<<sum<<endl;
}
Oliveira main(){
    int t;
    cin>>t;
    while(t--)solve();
}
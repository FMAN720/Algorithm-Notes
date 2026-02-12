#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n+1);
        int maxx=-1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]>=maxx){
                maxx=a[i];
            }
        }
        if(n==1)cout<<a[1]<<endl;
        else{
            cout<<a[1]+a[n]+(n-2)*maxx<<endl;
        }
    }
}
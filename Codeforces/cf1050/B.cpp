#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,x,y,cnt=0;
        cin>>n>>m>>x>>y;
        for(int i=0;i<n;i++){
            int yy;
            cin>>yy;
            if(yy<y)cnt++;
        }
        for(int i=0;i<m;i++){
            int xx;
            cin>>xx;
            if(xx<x)cnt++;
        }
        cout<<cnt<<endl;
    }
}
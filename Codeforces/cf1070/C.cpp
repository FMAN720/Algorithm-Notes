#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve(){
    int n;
    cin>>n;
    vector<int>goal(2*n+1,0);
    vector<bool>c(2*n+1,false);
    vector<vector<int>>a(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(goal[i+j]==0){goal[i+j]=a[i][j];c[a[i][j]]=true;}
        }
    }
    for(int i=1;i<=2*n;i++)if(!c[i])goal[1]=i;
    for(int i=1;i<=2*n;i++)cout<<goal[i]<<" ";
    cout<<endl;
}
signed main(){
     int t;
     cin>>t;
     while(t--)solve();
}
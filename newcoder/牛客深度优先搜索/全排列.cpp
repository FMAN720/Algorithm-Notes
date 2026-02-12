#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int maxx=10;
int n,vis[maxx],a[maxx];
void dfs(int cnt){
    if(cnt>n){
        for(int i=1;i<cnt;i++){
            cout<<a[i]<<" \n"[i==n];
        }
        return ;
    }
    else{
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                vis[i]=1;
                a[cnt]=i;
                dfs(cnt+1);
                vis[i]=0;
            }
        }
    }
}
signed main(){
    cin>>n;
    dfs(1);
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int maxx=2e5+10;
vector<int>a[maxx];
int value[maxx],record[maxx];
void dfs(int start,int ba){
    value[start]=1;
    record[start]=ba;//记录父节点
    for(int v:a[start]){
        if(v==ba)continue;
        dfs(v,start);//再一次
        value[start]+=value[v];
    }
}
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)a[i].clear();
    for(int i=1;i<=n-1;i++){
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    if(n==1)cout<<"1"<<endl;
    else{
        dfs(1,0);
        int ans=0;
        for(int i=1;i<=n;i++){
            bool find=true;
            for(int k:a[i]){
                int ttry=0;
                if(k!=record[i])ttry=value[k];
                else{ttry=n-value[i];}
                if(ttry%2==0){
                    find=false;
                    break;
                }
            }
            if(find)ans++;
        }
        cout<<ans<<endl;
    }
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
vector<int> g[100010];
ll ans=0;
ll qsm(ll a,ll b){
    ll r=1;
    while(b){
        if(b&1) r=r*a%mod;
        a=a*a%mod;
        b>>=1;
    } 
    return r; 
}
//u当前节点，fa其父亲节点，p表示到达当前节点的概率
void dfs(int u,int fa,ll p){
    ans=(ans+p)%mod;//这里是相加，搞不懂可以看一下题目
    int d=g[u].size();
    ll inv=qsm(d,mod-2);
    for(int v:g[u])if(v!=fa)dfs(v,u,p*inv%mod);
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }//建树
    dfs(1,0,1);
    cout<<ans<<endl;
}
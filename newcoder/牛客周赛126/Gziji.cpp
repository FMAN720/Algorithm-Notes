#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
using ll=long long;
typedef unsigned long long ull;
const int N=1e5;
int cnt[N+1],ss[N+1][2];
int idx; 
int m;
string S;
void insert(string &s){
    int p=0;
    for(auto c:s){
        int k=c-'0';
        if(!ss[p][k])ss[p][k]=++idx;
        p=ss[p][k];
    }
    cnt[p]++;
}
void dfs(int p,int cur){
    if(cur==m){
        cout<<S<<endl;
        exit(0);
    }
    for(int i=0;i<2;i++){
        if(ss[p][i]){
        S+=char(i+'0');
        dfs(ss[p][i],cur+cnt[ss[p][i]]);
        S.pop_back();//回溯
       }
    }
}
void solve(){
int n;
cin>>n>>m;
S="";



for(int i=0;i<idx;i++){
    cnt[i]=0;
    for(int j=0;j<2;j++){
        ss[i][j]=0;
    }
}
idx=0;
//多组数据的时候建议手动清除，不要用memset(ss,0,sizeof(ss));


for(int i=0;i<n;i++){
    string s;
    cin>>s;
    insert(s);
}
dfs(0,0);
cout<<"-1"<<endl;
}
signed main(){
    int t=1;
    while(t--)solve();
}
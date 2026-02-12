#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    map<int,int>sum;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a;
            cin>>a;
            if(a!=0)sum[a]++;
        }
    }
    int op=0,coin=0;
    for(auto it=sum.begin();it!=sum.end();it++){
        int fi=it->first;//数字
        int sec=it->second;//次数
        if(sec>=2){
        op+=sec/2;
        if(fi+1>=k)coin+=sec/2;
        sum[fi+1]+=sec/2;
        }
    }
    cout<<op<<" "<<coin<<endl;
}
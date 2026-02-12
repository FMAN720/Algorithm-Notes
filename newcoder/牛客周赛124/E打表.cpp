#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n;
void solve(){
    deque<int>q;
    for(int i=0;i<n;i++){
        if(i%2)q.push_front(i);
        else q.push_back(i);
    }//求出最优队列

    //求最优队列的数值
    int m=0;
    for(int i=0;i<n;i++){
        vector<int>visit(n);
        int mex=0;
        for(int r=i;r<n;r++){
            visit[q[r]]++;
            while(mex<n&&visit[mex]){
                mex++;
            }
            m+=mex;
        }
    }
    //cout<<m<<endl;
    vector<int>p(n);
    iota(p.begin(),p.end(),(int)0);//第一个到第二个0~n-1，等差数列
    do{
    int s=0;
    for(int i=0;i<n;i++){
        vector<int>nvisit(n);
        int mmex=0;
        for(int r=i;r<n;r++){
            nvisit[p[r]]++;
            while(mmex<n&&nvisit[mmex]){
                mmex++;
            }
            s+=mmex;
        }
    }
    if(s==m){
        for(int i=0;i<n;i++){
            cout<<p[i]<<" ";
        }
        cout<<endl;
    }
}while(next_permutation(p.begin(),p.end()));//会自动给出全排列
}
signed main(){
    cin>>n;
    int t=1;
    while(t--){
        solve();
    }
}
/*
1->1
2->2
3->2
4->4
5->4
........
8->16
ans=2^(n/2)
*/
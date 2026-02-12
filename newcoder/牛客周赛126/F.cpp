#include<bits/stdc++.h>
using namespace std;
const int m=2e5+10;
vector<vector<int>> v(m);
int dp[m];
void dfs(int x){
    for(int i:v[x]){
        if(dp[i]==0){
            dp[i]=3-dp[x];
            dfs(i);
        }
    }
}
//树是二分图，只要是二分图就可以用两种颜色涂完，并且相邻的不是相同的颜色
//先把这个基环树当成树dfs之后，如果有违背题目要求的地方，就把一个点换掉
//也就是第三种颜色
int main(){
    int n,x,y;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dp[1]=1;
    dfs(1);
    for(int i=1;i<=n;i++){
        for(int j:v[i]){
            if(dp[j]==dp[i]){
                dp[i]=3;
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<dp[i]<<" ";
    return 0;  
}
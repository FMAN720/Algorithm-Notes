#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
bool find=false,visited[101][101]={false};
char path[101][101];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n,m;
bool dfs(int x,int y){
    visited[x][y]=true;
    if(x==n&&y==m)return true;
    else{
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<1||nx>n||ny<1||ny>m)continue;
            if(path[nx][ny]=='#')continue;
            if(!visited[nx][ny]){
                visited[nx][ny]=true;
                if(dfs(nx,ny))return true;
            }
        }
    }
    return false; 
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>path[i][j];
        }
    }
    //visited[1][1]=true;
    if(dfs(1,1))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
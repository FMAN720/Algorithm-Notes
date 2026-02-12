#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,m,vis[101][101],cnt=0;
char path[101][101];
int dx[]={0,1,0,-1,1,-1,1,-1};
int dy[]={1,0,-1,0,1,-1,-1,1};
void dfs(int x,int y){
    vis[x][y]=1;
    for(int i=0;i<8;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<=0||nx>n||ny>m||ny<=0)continue;
        else{
            if(!vis[nx][ny]&&path[nx][ny]=='W')dfs(nx,ny);
        }
    }
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>path[i][j];
        }
    }
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(path[i][j]=='W'&&!vis[i][j]){
                cnt++;
                dfs(i,j);//dfs的时候i，j自己会动
            }
        }
    }
    cout<<cnt<<endl;
} 
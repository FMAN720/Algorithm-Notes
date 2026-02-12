#include<bits/stdc++.h>
using namespace std;
#define int long long
using ll=long long;
typedef unsigned long long ull;
void solve(){
int a[4][4];
for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
        cin>>a[i][j];
    }
}
for(int i=0;i<4;i++){
    vector<int>vis(5);
    for(int j=0;j<4;j++){
       vis[a[i][j]]++;
    }
    for(int k=1;k<=4;k++){
        if(vis[k]!=1){cout<<"NO"<<endl;
        return ;}
    }
}
for(int j=0;j<4;j++){
    vector<int>vis(5);
    for(int i=0;i<4;i++){
       vis[a[i][j]]++;
    }
    for(int k=1;k<=4;k++){
        if(vis[k]!=1){cout<<"NO"<<endl;
        return ;}
    }
}
for(int i=0;i+1<4;i+=2){
    for(int j=0;j+1<4;j+=2){
        vector<int>vis(5);    
        for(int x=i;x<=i+1;x++){
            for(int y=j;y<=j+1;y++){
                vis[a[x][y]]++;
            }
        }
        for(int k=1;k<=4;k++){
        if(vis[k]!=1){
            cout<<"NO"<<endl;
            return ;
        }
      }
    }
}
cout<<"YES"<<endl;
}
signed main(){
int t;
cin>>t;
while(t--)solve();
}
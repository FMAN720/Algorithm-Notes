#include<bits/stdc++.h>
using namespace std;
#define int long long
using ll=long long;
typedef unsigned long long ull;
void solve(){
int n,k,sum=0,sum1=0;
cin>>n>>k;
vector<int>a(n),visit(k);
for(int i=0;i<n;i++){cin>>a[i];visit[a[i]%k]++;}
for(int i=0;i<k;i++){
    if(visit[i]%2!=0&&visit[i]!=0){cout<<"No"<<endl;return ;}
}
cout<<"Yes"<<endl;
}
signed main(){
int t=1;
while(t--)solve();
}
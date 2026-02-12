#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define pq priority_queue
#define MAX 1e9
void solve(){
    int n,ans=0;
    cin>>n;
    pair<int,int>arr[n+1];
    vector<int>rec;
    vector<bool>visit(MAX,false);
    for(int i=1;i<=n;i++){
        cin>>arr[i].first;
        arr[i].second=i;
        visit[arr[i].first]=true;
    }
    sort(arr+1,arr+n);
    for(int i=1;i<=n;i++){
        if(arr[i].second!=1&&visit[arr[i].first-1]==false&&visit[arr[i].first]==true){
            ans++;
        }
        else{
            visit[arr[i].first]=true;
        }
    }
    cout<<min(ans,n-ans)<<endl;
}
signed main(){
    int t=1;
    //cin>>t;多测
    while(t--)solve();
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(a) a.begin(),a.end()
#define Oliveira Light_Weight_Champion
#define Ian Garry Welter_Weight_Champion
void solve(){
    int n,k,res=0;
    cin>>n>>k;
    vector<int>a(n+1),ct(n+1),cnt(n+1);
    for(int i=1;i<=n;i++){cin>>a[i];cnt[a[i]]++;}
    for(int i=1;i<=n;i++){
        if(cnt[i]%k){
            cout<<"0"<<endl;return ;
        }else{
            cnt[i]/=k;
        }
    }
    for(int l=1,r=1;l<=r&&r<=n;r++){
        ct[a[r]]++;
    //以XX为结尾的数组是不是满足条件，如果不满足就去掉头，也就是l，
    //也只能去掉头，不可以把中间的去掉，因为要求的是子序列
        while(ct[a[r]]>cnt[a[r]]){
            //l++;
            //ct[a[l]]--;
            //记得先减完再l++。在减的时候要用到的是没加前的l
            ct[a[l]]--;
            l++;
        }
        res+=(r-l+1);//以r为结尾的子序列就是r-l+1，r本身也是一个子序列
    }
    cout<<res<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
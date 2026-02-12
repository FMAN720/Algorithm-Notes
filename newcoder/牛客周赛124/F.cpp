#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
using ll=long long;
const int INF=1e18;
//未知，区间dp
void solve(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n & 1) {
        cout << -1 << endl;
        return;
    }
    vector<int> freq(26, 0);
    for (char c : s)
        freq[c - 'a']++;
    bool f = true;
    for (auto v : freq)
        if (v & 1) {
            f = false;
            break;
        }
    if (!f) {
        cout << -1 << endl;
        return;
    }
    //判断条件
    //这个可以用dp来写，dp来写的话，就要断环成链，这个断环成链就是复制一份字符串到原来字符串后面
    //因为dp这个东西是适用于线性的，如果是圆形，不断环成链的话，就不可以枚举所有情况
    string ss=s+s;
    vector<vector<int>>dp(2*n,vector<int>(2*n,INF));
    vector<int>aa(2*n);
    for(int i=0;i<n;i++){
        aa[i]=a[i];
        aa[i+n]=aa[i];
    }
    for(int len=2;len<=n;len+=2){
        for(int l=0;l+len-1<2*n;l++){
            int r=l+len-1;
            for(int k=l+1;k<=r;k+=2){
                if(ss[l]!=ss[k])continue;
                int L=0;
                if(l+1<k-1){
                   L=dp[l+1][k-1];
                   if(L==INF)continue;
                }
                int R=0;
                if(k+1<r){
                    R=dp[k+1][r];
                    if(R==INF)continue;
                }
                int c=L+R+aa[l]*aa[k];
                if(c<dp[l][r])dp[l][r]=c;
            }
        }
    }
    int ans=INF;
    for(int i=0;i<n;i++){
        ans=min(ans,dp[i][i+n-1]);
    }//由于你断环成链了，所以要枚举所有起点求出最小值
    if(ans==INF)cout<<"-1"<<endl;
    else cout<<ans<<endl;
}
signed main(){
    int t=1;
    cin>>t;
    while(t--)solve();
}
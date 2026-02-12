#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1), len(n + 1, 1);//用len[i]表示从i到前面有多少个连续的数等于a[i],
    //例如a[] = {1,1,2,2,2,1},那么len[] = {1,2,1,2,3,1}
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 2; i <= n; i ++){
        if(a[i] == a[i - 1]) len[i] = len[i - 1] + 1;
    }
    vector<int> dp(n + 5, 0);
    int ans = 0;//dp表示，以第i个元素为结尾的好数组有多少个
    for(int i = 1; i <= n; i ++){
        if(i - a[i]>= 0 && len[i] >= a[i]) dp[i] = 1 + dp[i - a[i]];
        else dp[i]= 0;
        ans+=dp[i];
    }
    cout << ans << endl;
    return;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
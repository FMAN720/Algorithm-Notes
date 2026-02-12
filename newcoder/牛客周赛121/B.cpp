#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve() {
    int n, x, res = 0;
    bool f = true;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if (t + res >= x) res = min(res + t - x, t);//如果res>X的话，就吃前一天的，这个时候
        //剩余的就是这一天的，不是res+t-x了，因为只能用当天或者昨天的食材，前一天的就不可以用了
        else f = false;
    }
    if (f) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}
signed main(){
    int t=1;
    cin>>t;
    while(t--)solve();
}
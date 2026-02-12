#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (n < 3 || m < 3) {
            cout << "1\n";
        } else {
            int a = ((n + 1) / 2) * ((m + 1) / 2);   // 奇,奇
            int b = (n / 2) * (m / 2);               // 偶,偶
            int c = ((n + 1) / 2) * (m / 2);        // 奇,偶
            int d = (n / 2) * ((m + 1) / 2);        // 偶,奇
            ///最重要的就是，棋子的移动，他的奇偶性是不会变的，求出这四种组合的点数，
            //再除以2
            //就是就是这个组合可以有的棋子数量
            //再取出最大的那一个
            int ans = max({(a + 1) / 2, (b + 1) / 2, (c + 1) / 2, (d + 1) / 2});
            cout << ans << '\n';
        }
    }
    return 0;
}
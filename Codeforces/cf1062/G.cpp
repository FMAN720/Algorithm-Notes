// author: khba
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int64_t a[n], c[n], dp[n];
        for (int64_t &i : a) cin >> i;
        for (int64_t &i : c) cin >> i;
        for (int i = 0; i < n; ++i) dp[i] = c[i];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (a[j] <= a[i]) dp[i] = max(dp[i], dp[j] + c[i]);
        cout << accumulate(c, c + n, 0LL) - *max_element(dp, dp + n) << '\n';
    }
}
//dp[i] 表示以第 i 个元素结尾的最长非递减子序列的最大成本和。
//使用动态规划来找到最长非递减子序列的最大成本和，然后用总成本减去这个值，就得到了需要删除的最小成本。
//简单点说就是得到一个非递减子序列的最大成本，然后用总的减去这个最大的就是最小的
#include <iostream>
#include <vector>
using namespace std;
// 使用全局变量并预留足够空间，避免多次分配内存
const int MAXN = 200005;
vector<int> adj[MAXN];
int sz[MAXN];
int p[MAXN];
// DFS 计算每个子树的大小以及记录父节点
void dfs(int u, int fa) {
    sz[u] = 1;
    p[u] = fa;
    for (int v : adj[u]) {
        if (v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}
void solve() {
    int n;
    if (!(cin >> n)) return;
    // 清空上一组测试数据的影响
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 特判 n=1
    if (n == 1) {
        cout << 1 << "\n";
        return;
    }

    // 以 1 为根进行 DFS
    dfs(1, 0);

    int perfect_count = 0;
    for (int i = 1; i <= n; i++) {
        bool is_perfect = true;
        for (int v : adj[i]) {
            int comp_size;
            // 如果 v 是 i 的子节点
            if (v != p[i]) {
                comp_size = sz[v];
            } else {
                // 如果 v 是 i 的父节点
                comp_size = n - sz[i];
            }

            // 如果发现任何一个分量的大小是偶数，则不完美
            if (comp_size % 2 == 0) {
                is_perfect = false;
                break;
            }
        }
        if (is_perfect) {
            perfect_count++;
        }
    }

    cout << perfect_count << "\n";
}

int main() {
    // 优化输入输出效率
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 1E6;
int tr[N + 1][2];
int cnt[N + 1];
int tim = 0;
int m;  // 目标长度，需要设为全局（或传参，这里选全局更贴近原逻辑）
string S;  // 拼接结果的字符串
// 插入字符串到字典树的函数（原代码不变）
void insert(const string& s) {
	int p = 0;
	for (auto c : s) {
		int k = c - '0';
		if (!tr[p][k]) {
			tr[p][k] = ++tim;
		}
		p = tr[p][k];
	}
	cnt[p]++;
}
// 普通DFS函数（替代原lambda递归）
void dfs(int p, int cur) {
    // 终止条件：达到目标长度，输出并退出程序
	if (cur == m) {
		cout << S << "\n";
		exit(0);
	}
    // 遍历0/1两个分支
	for (int k = 0; k < 2; k++) {
		if (tr[p][k]) {
			S += char(k + '0');  // 拼接字符
			// 递归调用：直接用函数名，无需传self
			dfs(tr[p][k], cur + cnt[tr[p][k]]);
			S.pop_back();  // 回溯
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n >> m;  // 读入n和m，m赋值给全局变量
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		insert(s);
	}
	S ="";  // 初始化结果字符串
	dfs(0, 0);  // 启动DFS：根节点0，初始长度0
	cout << "-1\n";  // 没找到符合条件的字符串时输出-1
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define oliveitra light_weight_champion
#define Ian Garry Welter_weight_champion
const int  N=2005;
int n, m, i, j, k, a[N], b[N], c[N];
long long ans;
void solve(){
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		//scanf("%d%d", a+i, b+i);
		//a是长度，b是数量
		cin>>a[i]>>b[i];
		c[i] = a[i];
	}
	sort(c+1, c+n+1);
	for(ans=0, i=1; i<=n; i++){
		//这里考虑了有相同长度的木棍组成的三角形的情况
		if(b[i] >= 3) ans++;
		if(b[i] >= 2) ans += lower_bound(c+1, c+n+1, 2*a[i])-c-1-1;//找到第一个大于两边之和的木棍长度，减去c得到这个数字
		//1 2 3 4 5 6 假设是2*3，那么找到6，第一个减去1，是减去这个6，第二个减去是减去自己这个3
		//每条边都不一样
		for(j=1; j<=n; j++){
			if(a[j] <= a[i]) continue;
			//这里避免了重复计算，如果改成<=,那么下面的范围的计算也要改掉
            
			//第一个>=a[j]+a[i]的数                            第一个大于a[j]的数，假设范围在第七个和第五个之间
			//就是7-5=2
			//这里的范围是这样的的原因是，我们假设了这个第三条边的长度是最大的 即x>a[j]>a[i];这样也是保证不重复计算
			/*具体例子
假设 a[i] = 3, a[j] = 5：

理论范围：(5-3, 5+3) = (2, 8) → 有效值：3,4,5,6,7

但在 a[i] ≤ a[j] ≤ x 假设下：

x 必须 ≥ 5（因为是最大边）

所以实际范围：[5, 8) → 有效值：5,6,7

代码中排除 x = 5（a[j] 自身），所以：6,7

如果你用 (a[j]-a[i], a[j]+a[i])
这样会找到：3,4,5,6,7

但这里包含了 3,4，这些值 小于 a[j] = 5，违反了 x 是最大边的假设。*/
			ans += lower_bound(c+1, c+n+1, a[j]+a[i])-upper_bound(c+1, c+n+1, a[j]);
		}
	}
	printf("%lld\n", ans);
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}
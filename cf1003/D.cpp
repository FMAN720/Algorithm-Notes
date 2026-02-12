#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL N=2e5+5;
LL n,m,sum[N],a[N];
bool cmp(LL a,LL b){return a>b;}
void solve(){
	cin>>n>>m;
	LL ans=0;
	for(LL i=1;i<=n;i++){
		LL sum=0;
		for(LL j=1;j<=m;j++){
			LL x;cin>>x;
			ans+=(m-j+1)*x;
			sum+=x;
		}
		a[i]=sum;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		ans+=((n-i)*m)*a[i];
	}
	cout<<ans<<'\n';
}
int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	int T;cin>>T;
	while(T--)solve();
	return 0;
} 
//洛谷超级nb题解：
//https://www.luogu.com.cn/problem/solution/CF2065D，有超级简单易懂的公式推导，这个要求数学
/*
此处详细解释在csdn上
*/

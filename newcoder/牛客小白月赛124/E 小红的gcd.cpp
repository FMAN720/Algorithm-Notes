#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Mio_qh signed
#define el '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define pq priority_queue
const int MOD = 998244353;
const int N = 100721;

void solve() {
    int n,ans=0;
    cin >> n;
    int k=(2*n-1)/3;
    vector<string > a(n);
    for(int i=0;i<n;i++) cin >>a[i];
    string bzd[]={"gcd","gdc","dgc","dcg","cdg","cgd"};
    for(auto zyy : bzd){
    	char c1=zyy[0],c2=zyy[1],c3=zyy[2];
		if(a[0][0]!=c1 || a[n-1][n-1]!=c3) continue;
    	vector <vector<int>> dp(n,vector<int>(n,0));
    	dp[0][0]=1;
    	for(int w=1;w<2*n-1;w++){//w=i,代表第i+1个字母
            //第i+1个字母都会满足i+j=w,画图即可知道
    		for(int i=0;i<n;i++){
    			int j=w-i;//这里很巧妙，这里会自动模拟走的路线，
                //只能向右边或则下边走，（这里没必要去考虑如果有向右边走或者可以向上走的举一反三，
                //如果是这样就无穷了，无意义）
    			if(j<0 || j>=n) continue;//去掉数组越界的情况
    			char need;
    			if(w<k) need=c1;
    			else if(w<2 * k && w>=k) need=c2;
    			else need=c3;
    			if(a[i][j]!=need) continue;//说明这条路走不通    
                //动态dp
    			int temp=0;
    			if(i>0) temp = (temp+dp[i-1][j]) % MOD;
    			if(j>0) temp = (temp + dp[i][j-1] ) %MOD;
    			dp[i][j]=temp;
			}
		}
    	ans=(ans+dp[n-1][n-1])%MOD;
	}
	cout << ans << el;
}


Mio_qh main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}
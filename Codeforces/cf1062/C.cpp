#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int _;
	cin >> _;
	while(_--){
		int n;
		cin >> n;
		bool f1 = 0, f0 = 0; 
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			if(a[i] % 2 == 0)f1 = 1;
			else f0 = 1;
		}
		if(f0 && f1){
			sort(a + 1, a + n + 1);
			for(int i = 1; i <= n; i++)cout << a[i] << " \n"[i == n];
		}
		else{
			for(int i = 1; i <= n; i++)cout << a[i] << " \n"[i == n];
		} 
	} 
	return 0;
}
//又有偶数又有奇数，就是直接排序的情况字典序最小
//如果不是这样的话，就是不动
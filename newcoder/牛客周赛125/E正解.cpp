#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2000010;
int a[N],minl[N],minr[N],sum[N];
int n,m;
void solve(){
    minl[0]=1e9+10;
	cin>>n>>m;
	minr[n+1]=1e9+19;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
		minl[i]=min(a[i],minl[i-1]);
	}
	for(int i=n;i>=1;i--)minr[i]=min(a[i],minr[i+1]);
	int l=1,r=n,s1=a[1],s2=a[n];
	while(m--){
		int x,y;
		cin>>x;
		if(x==1){
			cin>>y;
			l=max(l,y);
			if(l<r)s1=min(s1,minl[l]);
			else s1=minl[n],r=l+1;
		}
		else if(x==2){
			cin>>y;
			r=min(r,y);
			if(l<r) s2=min(s2,minr[r]);
			else s2=minl[n],l=r-1;
		}
		else {
            int ans=0;
			ans+=l*s1;
			ans+=(n-r+1)*s2;
			ans+=sum[r-1]-sum[l];
			cout<<ans<<endl;
		}
	}
}
signed main(){
    ios::sync_with_stdio(false); // 加速cin/cout
    cin.tie(nullptr);
	int t;
    cin>>t;
    while(t--)solve();
}
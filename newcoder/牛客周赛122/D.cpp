#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
/*void solve(){
   int n,min_n=INT_MAX,sum=0;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++){cin>>a[i];min_n=min(min_n,a[i]);sum+=a[i];}
   if(min_n>=2)cout<<n<<endl;//0是肯定有的，如果最小的那个都大于2，那说明无论你怎么去掉，
   ///最小的不在S中的非负整数都不会变
   else{//就是最小的那个是1
   sort(a,a+n);
   int num=upper_bound(a,a+n,1)-a;
   cout<<n-num<<endl;
   }
}*/
void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    bool found=false;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        if (a[i]==1) found=true;
    }
    if(found==false) cout<<n<<endl;
    else {
        sort(a.begin(),a.end());
        int mx=0;
        int ans=0;
        for(int i=0;i<n;i++) {
            if(a[i]==0)ans++;
            if (a[i]<=mx+1) mx+=a[i];
            else ans++;
        }
        cout<<ans<<endl;
    }
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}

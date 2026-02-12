#include<bits/stdc++.h>
using namespace std;
#define int long long 
using ll=long long;
typedef unsigned long long ull;
const int MOD=998244353;
const int mod=1e9+7;
const int N=2e5+10;
int n,m,k,t;
//有点双指针的感觉
//当不满足条件的时候级一直往前，直达达到目标为止
//都是随着当满足条件的时候,右边的i不变，左边的l++,
//当不会大于k的时候，就直接把i往右边移动，因为右结尾是i的最小区间已经全部结束了，
//虽然现在有了一个最小的ans,但是不可以满足于当前现状，要不断往前看，要继续往前走看会不会有新的可能
//一直维护ans，
//输出的时候ans的最小（如果有的话）
void solve(){
   cin>>n>>m>>k;
   string s;
   cin>>s;
   int l=0,ans=N;
   int r=0,y=0,w=0;
   for(int i=0;i<n;i++){
     if(s[i]=='r') r++;
     else if(s[i]=='y') y++;
     else w++;
     while(l<=i&&2*max(r,y)+min(r,y)+2*min(w,m)>=k){
       ans=min(ans,i-l+1);
       if(s[l]=='r') r--;
       else if(s[l]=='y') y--;
       else w--;
       l++;
    }
   }
   if(ans==N) ans=-1;
   cout<<ans<<endl;
}
signed main(){
 int t;
 cin>>t;
 while(t--)solve();
}
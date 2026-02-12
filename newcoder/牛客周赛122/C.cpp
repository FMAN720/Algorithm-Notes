#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define oliveira light_weight_champion
void solve(){
  int n,max_n=0,min_n=INT_MAX,sum=0;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];max_n=max(max_n,a[i]);min_n=min(min_n,a[i]);}
  int el=max_n+min_n*n;
  cout<<(el>sum?sum:el)<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}//这种题目要小心的就是不能写的太复杂
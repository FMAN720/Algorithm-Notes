#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve(){
   int n;
   cin>>n;
   if(n<=2)cout<<"-1"<<endl;
   else if(n%2==1){
    for(int i=2;i<=n;i++)cout<<i<<" ";
    cout<<"1"<<endl;
   }
   else{
    for(int i=2;i<n-1;i++)cout<<i<<" ";
     cout<<n<<" "<<"1"<<" "<<n-1<<endl;
     //如果是偶数的话
     //1 2 3 4 5 6
     //2 3 4 5 6 1
     //    *     *这里会有一个就是3->6=+3   4->1=-3,这里的这种相等只有偶数的时候相同
     //一开始想到的肯定是把6 和1 的位置换一下不就可以了
     //但是题目要求上下两个数字要不一样，所以想到了这种
   }
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}
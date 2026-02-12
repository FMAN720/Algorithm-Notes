#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define oliveira light_weight_champion
bool check(int x){
    int sum=0;
    int temp=x*x;
    while(temp!=0){
        sum+=temp%10;
        temp/=10;
    }
    if(sum==x)return true;
    return false;
}
signed main(){
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
   int t;
   cin>>t;
   while(t--){
    int r,l;
    cin>>r>>l;
    int cnt=0;
    for(int i=r;i<=l;i++){
       if(check(i))cnt++;
    }
    cout<<cnt<<endl;
   }
}
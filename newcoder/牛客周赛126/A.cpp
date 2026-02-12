#include<bits/stdc++.h>
using namespace std;
#define int long long
using ll=long long;
void solve(){
int x;
cin>>x;
if(x+5<=13){
    cout<<x<<" "<<x+1<<" "<<x+2<<" "<<x+3<<" "<<x+4<<" "<<endl;
}
else{
    cout<<x<<" "<<x-1<<" "<<x-2<<" "<<x-3<<" "<<x-4<<" "<<endl;
}
}
signed main(){
int t=1;
while(t--)solve();
}
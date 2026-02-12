#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve(){
    int a,b,l,r,cnt=0;
    cin>>a>>b>>l>>r;
//(x-a)=k(x-b)
//(x-a)-(x-b)=(k-1)(x-b)
//x=(b-a)/(k-1)+b
//假设c=(b-a)/(k-1),又因为题目的要求，所以k>1,c肯定是b-a的一个因子，所以，只要c是b-a的一个因子，
//且c+b，没有超过范围,那么cnt++;

//这种数学的真没招了
int c=b-a;
for(int i=1;i<=sqrt(c);i++){
    if(c%i==0){
        if(i+b>=l&&i+b<=r)cnt++;
        if(c/i!=i&&c/i+b>=l&&c/i+b<=r)cnt++;
    }
}
cout<<cnt<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}
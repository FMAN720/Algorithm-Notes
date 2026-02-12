#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
using ll=long long;
typedef unsigned long long ull;
const int MOD=998244353;
const int mod=1e9+7;
void solve(){
    int k;
    cin>>k;
    for(int i=1;i<=18;i++){
        int L=k*(int)pow(10,i);
        int R=k*(int)pow(10,i)+(int)pow(10,i)-1;
        int sq=sqrt(R);
        if(sq*sq>=L){cout<<sq*sq<<endl;
        break;}
    }
}
//这个直接去看题解了，不做过多赘述，太难了，验题人自己都看了好久
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}
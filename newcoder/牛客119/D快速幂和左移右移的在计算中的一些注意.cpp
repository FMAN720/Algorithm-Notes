#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD=998244353;
#define oliveira light_weight_champion
//1 1 1  
//1+2+4 一直乘以2，就是一直平方的意思
//快速幂
int quick(int x,int y){
    int result=1;
    while(y!=0){
    if(y&1)result=((result%MOD)*x)%MOD;
    x=(x*x)%MOD;//这里也要取模，真该死啊啊啊啊啊啊啊啊
    y>>=1;
    }
    return result%MOD;
}
//不是直接把位置都移动完然后再开始计算
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,l=0;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            if(i&1)l+=x;//偶数右移奇数左移
            else l-=x;
            //往右边移动会造成精度的缺失
            //3/2*2！=3*2/2，所以一旦l<0的时候，就直接右移，
            //最后只计算左移的就可以了
            while(k&&l<0){l++,k>>=1;}
        }
        if(k&&l>0)k=(k%MOD*quick(2,l))%MOD;
        cout<<k%MOD<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD=1e9+7;
int quick(int x,int y){
    int result=1;
    while(y!=0){
    if(y&1)result=((result%MOD)*x)%MOD;
    x=(x*x)%MOD;//这里也要取模，真该死啊啊啊啊啊啊啊啊
    y>>=1;
    }
    return result%MOD;
}
//费马小定理，这里要知道的是，除法和取模是不可以一起用的，
//x/k%MOD是不对的，x*k^(MOD-2)这样是对的，见博客
int inv(int x){
    return quick(x,MOD-2);
}
signed main(){
    int n;
    cin>>n;
    //这个下面的推导是这样的
    //假设要求是维度为根号k，那么就是说，题目里那个公式的根号下的是k
    //也就是说两个节点中要有k对不同的数字，因为(1-0)^2/(0-1)^2才会是1，k个1加起来才会是k
    //那么要有k个不一样可以怎么选呢？就是C（n,k)嘛，那有几对呢2^n*C(n,k)嘛，
    //但是，这个2^n*C(n,k)是有重复的，会出现A找B计算了一次，B找A又出现了一次，所以要除以2，
    //所以就是2^(n-1)*C(n,k)=2^(n-1)*C(n-1,k)*(n-k+1)/k-->这个公式告诉我们没必要去写
    //复杂的阶乘，只要算出C(n-1,1),就可以算出C（n-1，2）
    //要C（n-1，1），只要C(n-1,0)-->这个就是1，没必要算
    //之所以要这样替换的原因是，这样替换之后，只要算出c(n-1,0)就可以了
    int ans=quick(2,n-1);
    for(int i=1;i<=n;i++){
        ans=ans*(n-i+1)%MOD;
        ans=ans*inv(i)%MOD;
        cout<<ans<<" \n"[i==n];
    }
}
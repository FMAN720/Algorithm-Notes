#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define oliveira Light_weight_champion
#define Ian Garry Welter_weight_champion
//链接：https://ac.nowcoder.com/acm/contest/120455/C
//来源：牛客网

//为了避免大量的输出，假设第 i 行第 j 列受到的总伤害是 wij
//你只需要输出Σwij(i+j)对 10^9+7 取模的结果即可


//这里要看清楚啊啊啊啊啊啊啊啊啊 啊
/*对第 xi 行的贡献：

第 xi 行的每个格子 (xi, j) 获得 zi 伤害

这些格子的权重是 (xi + j)

总贡献 = zi × Σ[xi + j] (j=1..M)

= zi × [M×xi + (1+2+...+M)]

= zi × [M×xi + M(M+1)/2]

对第 yi 列的贡献：

第 yi 列的每个格子 (i, yi) 获得 zi 伤害

这些格子的权重是 (i + yi)

总贡献 = zi × Σ[i + yi] (i=1..N)

= zi × [N×yi + (1+2+...+N)]

= zi × [N×yi + N(N+1)/2]
减去重复计算：

格子 (xi, yi) 被行和列各算了一次

需要减去一次：zi × (xi + yi)*/
signed main(){
    int N,M,H;
    cin>>N>>M>>H;
    long long ans=0;
    int MOD=1'000'000'007;
    int m=M*(M+1)/2,n=N*(N+1)/2;
    int i,j,z;
    for(int k=0;k<H;k++){
        cin>>i>>j>>z;
        long long sum=1LL*M*i+1LL*N*j+1LL*(m+n)-i-j;
        sum=(sum*z)%MOD;
        
        ans=(ans+sum)%MOD;
    }
    cout<<ans;
    return 0;
}
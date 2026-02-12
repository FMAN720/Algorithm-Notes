#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int sol(){
    int minx=99;
    int n;
    cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        //其实我们只要枚举所有的2~53的质数
        //他要求的是到10^18内没找到就输出-1，但是根本不需要考虑这个
        //我们注意到2×3×5×7×11×13×17×19×23×29×31×37×41×43×47×53>10^18
        //在10^18的范围内肯定是解的
        for(int i=2;i<=99;i++){//这里开到99是为了保险
            if(gcd(tmp,i)==1) {minx=min(minx,i);break;}//直接枚举所有的质数
        }
    }
    return minx;
}
signed main(){
    int t;
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--) cout<<sol()<<'\n';
    return 0;
}
//注意，是跟数组里所有的数字都互为质数，然后求这个的最小值，那么这个数字肯定是个质数，
//如果是个合数的话，那他肯定有一个因子
//是个质数，那这个质数也满足条件，那么最小的就会是这个质因子，那么这个最小的答案又变成了质数
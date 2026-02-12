#include<bits/stdc++.h>
#define MAXN 1
#define ll long long
using namespace std;
ll cal(ll x){
    return x*(x+1)/2;
}
ll l,r,p,q;
ll f(ll x){
    return x/q*cal(p-1)+cal(min(x%q,p-1));
}
//接下来我将以人类的力量来详细解释这段神秘的代码中的这个巧妙的我想不到的下一次也不一定能碰到，碰到也不一定想的起来的
//超级神奇函数的正真作用:
/*可以知道的是
q是大的，p是小的
g(i)={ 
i%q   如果 i%q<p   这个好理解，他是从大道小往下取模运算的，如果比最小的都小，拿取个鬼模，都不变
0      如果 i%q>=p  这个，你取一次模，假设对m取模 结果肯定<m，
因为是小于m的，后面肯定有小于m的数，当这个结果跟这个取模就会为0
例如，8%5=3，因为p~q是渐渐减1减1这样减少的，5后面肯定有3，当3%3的时候就是为0了。
*/
int main(){
    int T;cin>>T;
    while(T--){
        cin>>l>>r>>p>>q;
        cout<<f(r)-f(l-1)<<endl;//类似前缀和相减的原理
    }
    return 0;
}
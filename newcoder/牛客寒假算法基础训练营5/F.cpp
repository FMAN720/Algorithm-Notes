#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lll __int128
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const int MOD = 998244353;
const int N = 200005;
const int mod=1e9+7;
int fastpow(int base, int exp) {
    int result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) result = (base*result)%MOD;
        exp >>= 1;
        base = (base*base)%MOD;
    }
    return result;
}
int hx[8]={1,1,-1,-1,2,-2,2,-2};
int hy[8]={2,-2,2,-2,1,1,-1,-1};
void print(lll x) {
    if(x==0) cout<<0<<endl;
    else {
        string ans="";
        while(x!=0) {
            int t=x%10;
            ans=to_string(t)+ans;
            x=x/10;
        }
        cout<<ans<<endl;
    }
}
lll input(){
   string s;
    cin >> s;  // 先读入字符串
    __int128 res = 0;
    int sign = 1;
    size_t i = 0;//这个的原因是s.size()是size类型的，其实s.length也是，但是在循环中可以直接int i的原因是什么呢？？
    //就是可能会报错 保险用这个    
    if (s[0] == '-') {  // 处理负号
        sign = -1;
        i = 1;
    }
    for ( ; i < s.size(); ++i) {
        res = res * 10 + (s[i] - '0');  // 逐位累加
    }
    return res * sign;
} 
int mysqrt(int x) {
    if (x==0) return 0;
    int left=1,right=x,ans=0;
    while(left<=right) {
        int mid=left+(right-left)/2;
        if(x/mid>=mid) {
            ans=mid;
            left=mid+1;
        }
        else right=mid-1;
    }
    return ans;
}
int fact[N+1];
int inv_fact[N+1];
int inv(int a) {
    return fastpow(a,MOD-2);
}
 
void prefact() {
    fact[0] = 1;
    for (int i = 1; i <= N; i++) fact[i] = fact[i-1] * i %MOD;
    inv_fact[N] =fastpow(fact[N],MOD-2);
    for (int i = N-1; i >= 0; i--) inv_fact[i] =inv_fact[i+1]*(i+1) %MOD;
    //1/9! = 1/10! × 10
}
 
int C(int n, int r) {
    return fact[n] * inv_fact[r] %MOD * inv_fact[n-r] %MOD;
}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ddx[8]={0,1,0,-1,1,-1,1,-1};
int ddy[8]={1,0,-1,0,1,-1,-1,1};
int n,a,b;
int res(int n,int a,int b,int c){
    if(c*7>n)return 0;
    //c是qcjjkkt的数量
    int les=n-7*c;
    int qcjtd=min(les,c);
    les=les-qcjtd;
    return c*a+qcjtd*b+(les/2)*b;
}
void solve(){
    cin>>n>>a>>b;
    cout<<max({res(n,a,b,0),res(n,a,b,n/7),res(n,a,b,n/8),res(n,a,b,(n+7)/8)})<<endl;
}
//这个的逻辑和下面会长的逻辑一样
void solve2(){
    cin>>n>>a>>b;
    //主要是qcjjkktd和主要是td进行比较
    //a+b>4b的时候，这样更划算，就是a>3b
    int h1=0,h2=0;
    if(a>=3*b){
        h1=n/8*(a+b)+(n%8)/2*b;
    }else{
        h1=n/2*b;
    }

    //这里是算主要是qcjjkkt的，就是单纯qcjjkkt
    int l=n/8+1;//最少要有几个qcjjkkt才是主要是qcjjkkt，为什么是n/8+1，因为如果是n/8的话，就代表
    //所有的qcjjkkt都有一个d，就变成了主要是qcjjkktd了，就不是qcjjkkt了
    int r=n/7;//最多可以有几个qcjjkkt
    //所以结果用算式表示就是  a*k+b(n-7k)==(a-7b)k+bn
    //这里是，所有的qcjjkkt的数量加上剩余的空格，这些空格就是给qcjjkkt后面加个d，这样比单独
    //的td更划算
    //有没可能就是给所有的qcjjkkt加上d之后还有空格可以放单独的td呢？，不可能，
    //因为最少的qcjjkkt都n/8+1了，如果所有的qcjjkkt都加上d，总的数量就超过n了
    //所以到最后甚至都不可以把所有的qcjjkkt的后面都加上d，这样才叫大部分是qcjjkkt
    //结合上面的公式
    if(a>7*b){
        h2=a*r+(n-7*r)*b;
    }else if(a<7*b){
        h2=a*l+(n-7*l)*b;
    }else{
        h2=b*n;
    }
    cout<<max(h2,h1)<<endl;
}
signed main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
int t=1;
cin>>t;
while(t--)solve();
}
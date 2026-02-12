#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lll __int128
#define endl '\n'
#define pb push_back
#define Oliveira signed
#define all(x) (x).begin(), (x).end()
#define pq priority_queue
const int mod=998244353;
const int MOD = 998244353;
const int N = 200005;
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

int p[8];
int q[8];
int c;
int a[10];
int inv_100=fastpow(100,MOD-2);
int cal(int x){
    string s=to_string(x);
    string cnt="";
    for(int i=1;i<=4-s.length();i++){
        cnt.push_back('0');
    }
    for(auto c:s)cnt.push_back(c);
    int res=1;
    for(auto c:cnt){
        res=res*a[c-'0']%mod;
    }
    return res;
}
void solve(){
    cin>>c;
    for(int i=1;i<=7;i++){
        cin>>p[i];
        q[i]=100-p[i];
    }
    a[0]=(p[1]*p[2]*p[3]*p[5]*p[6]*p[7])%mod,a[0]=(a[0]*q[4])%mod,a[0]=(a[0]*fastpow(inv_100,7))%mod;
 
    a[1]=(p[3]*p[6])%mod,a[1]=(a[1]*q[1]*q[2]*q[4]*q[5]*q[7])%mod,a[1]=(a[1]*fastpow(inv_100,7))%mod;
 
    a[2]=(p[1]*p[3]*p[4]*p[5]*p[7])%mod,a[2]=(a[2]*q[2]*q[6])%mod,a[2]=(a[2]*fastpow(inv_100,7))%mod;
 
    a[3]=(p[1]*p[3]*p[4]*p[6]*p[7])%mod,a[3]=(a[3]*q[2]*q[5])%mod,a[3]=(a[3]*fastpow(inv_100,7))%mod;
 
    a[4]=(p[2]*p[3]*p[4]*p[6])%mod,a[4]=(a[4]*q[1]*q[5]*q[7])%mod,a[4]=(a[4]*fastpow(inv_100,7))%mod;
 
    a[5]=(p[1]*p[2]*p[4]*p[6]*p[7])%mod,a[5]=(a[5]*q[3]*q[5])%mod,a[5]=(a[5]*fastpow(inv_100,7))%mod;
 
    a[6]=(p[1]*p[2]*p[4]*p[5]*p[6]*p[7])%mod,a[6]=(a[6]*q[3])%mod,a[6]=(a[6]*fastpow(inv_100,7))%mod;
 
    a[7]=(p[1]*p[3]*p[6])%mod,a[7]=(a[7]*q[2]*q[4]*q[5]*q[7])%mod,a[7]=(a[7]*fastpow(inv_100,7))%mod;
 
    a[8]=(p[1]*p[2]*p[3]*p[4]*p[5]*p[6]*p[7])%mod,a[8]=(a[8])%mod,a[8]=(a[8]*fastpow(inv_100,7))%mod;
 
    a[9]=(p[1]*p[2]*p[3]*p[4]*p[6]*p[7])%mod,a[9]=(a[9]*q[5])%mod,a[9]=(a[9]*fastpow(inv_100,7))%mod;
 
    int ans=0;
    for(int i=0;i<=c;i++){
        ans=(ans+cal(i)*cal(c-i))%mod;
    }
    cout<<ans<<endl;
}
Oliveira main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
int t;
cin>>t;
while(t--)solve();
}
//记得学状态压缩
///0b1101101-->相当于1101101这个二进制的十进制，换了一种方式表达
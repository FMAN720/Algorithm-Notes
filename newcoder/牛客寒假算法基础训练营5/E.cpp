#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lll __int128
#define endl '\n'
#define all(x) (x).begin(), (x).end()
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
void solve(){
    int n,p,b=0,maxx=0,r=0,l=0;cin>>n>>p;
    //有两种情况，一种是：p[r]-p[l-1]>0 (p[r]-p[l-1])%p
    //           另外一种是 p[r]-p[l-1]<0 (p[r]-p[l-1]+p)%p
    map<int,int>mp;//记录哪一个都行，这个mp的作用就是记录这个前缀和出现的最早的下标
    set<int>s;
    set<int>::iterator ite;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        b=(b+x)%p;
        if(b>maxx){
            maxx=b;
            l=0;
            r=i;
        }//这里是考虑第一种情况，如果是第一种情况，那么就要让p[r]尽可能的大
        if(b!=p-1&&s.lower_bound(b+1)!=s.end()){
            int bb=(b-*s.lower_bound(b+1)+p)%p;
            if(bb>maxx){
                maxx=bb;
                r=i;
                l=mp[*s.lower_bound(b+1)]+1;
            }
        }//这里考虑第二种情况，就是要p[l-1]就比p[r]大那么一点点
        if(mp.find(b)==mp.end()){
            mp[b]=i;
        }
        s.insert(b);
        if(maxx==p-1){
            cout<<l<<" "<<r<<" "<<maxx<<endl;
            return ;
        }//insert和这个放在哪里无所谓
    }
    cout<<l<<" "<<r<<" "<<maxx<<endl;
}
signed main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
int t=1;
//cin>>t;
while(t--)solve();
}
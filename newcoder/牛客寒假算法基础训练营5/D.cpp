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
/*
要当前最小的两个
*/
void solve(){
    //小根堆，从小到大排
    //priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pqq;
    int n;cin>>n;
    priority_queue<pair<int,int>>pq;
    if(n==1){
        cout<<"0"<<endl;
        return ;
    }
    for(int i=0;i<n;i++){
        int c,w;
        cin>>c>>w;
        pq.push({-w,c});
    }
    int ans=0;
    while(pq.size()!=0){
        int c=pq.top().second;
        int w=-pq.top().first;
        pq.pop();
        if(c==1&&pq.empty()){
            cout<<ans<<endl;
            return ;
        }
        if(c>=2){
            int sum_num=c/2;
            ans=(ans+sum_num%mod*(w*2%mod))%mod;
            pq.push({-w*2,sum_num});
            c%=2;
        }
        if(c==1){
            if(pq.empty()){
                cout<<ans<<endl;
                return ;
            }
            int c2=pq.top().second;
            int w2=-pq.top().first;
            pq.pop();
            ans=(ans+(w2+w)%mod)%mod;
            pq.push({-(w+w2),1});
            if(c2>1){
                pq.push({-w2,c2-1});
            }
        }
    }
}
signed main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
int t=1;
//cin>>t;
while(t--)solve();
}
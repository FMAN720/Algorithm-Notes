#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lll __int128
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define pq priority_queue
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
    string s;
    cin >> s;
    int n = s.size(), mx = 0;
    for (int d = 0; d <= 13; ++d) {//枚举每个间隔，看哪一个间隔可以保留的字符是最多的
        //这里枚举到13就可以了，因为距离是环，超过一半就没意义了
        array<int, 26> dp{}, ndp{};
        for (int i = 0; i < 26; ++i)
            dp[i] = (s[0] - 'a') == i;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {
                ndp[j] = max(dp[(j - d + 26) % 26], dp[(j + d) % 26]) + (j == s[i] - 'a');
                //这个ndp的意思就是：在当前字符是XX颜色的时候，配合着前面的情况，有几个
                //字符是可以不用改变的
                //这里要设两个dp的原因是，你在算ndp的时候，不可以用更新过的数据，要用的是
                //没更新前的数据
            }
            dp.swap(ndp);
            //dp的存储的是上一步的结果，当上一步（就是i-1个字符是XX颜色的时候最大可以保留几个字符）
            //这里是把ndp这个新的数据存储到dp里当作上一步的，因为i要++了
        }
        for (auto v : dp)
            mx = max(mx, v);
    }
    //n减去最多可以保留的，就是最少操作次数
    cout << n - mx << endl;
}
signed main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
int t=1;
//cin>>t;
while(t--)solve();
}
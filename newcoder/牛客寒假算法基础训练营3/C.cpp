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


int get_min_ops(int n, const string& s, int target_start) {
    int end0 = 0; // 当前以 '0' 结尾的交替子序列数量
    int end1 = 0; // 当前以 '1' 结尾的交替子序列数量

    for (int i = 0; i < n; ++i) {
        // 当前位置目标应该是 target_start, 1-target_start, target_start...
        int target_val = (target_start + i) % 2;
        
        // 如果当前位与目标不符，说明这一位属于需要翻转的子序列 B
        if ((s[i] - '0') != target_val) {
            char current_char = s[i];
            if (current_char == '0') {
                // 尝试将这个 '0' 接在某个以 '1' 结尾的交替子序列后面
                if (end1 > 0) {
                    end1--;
                }
                end0++;
            } else {
                // 尝试将这个 '1' 接在某个以 '0' 结尾的交替子序列后面
                if (end0 > 0) {
                    end0--;
                }
                end1++;
            }
        }
    }
    // 总的操作次数等于最终生成的交替子序列总数
    return end0 + end1;
}
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    // 情况 1: 目标是 010101...
    int res1 = get_min_ops(n, s, 0);
    // 情况 2: 目标是 101010...
    int res2 = get_min_ops(n, s, 1);

    // 取两者的最小值
    cout << min(res1, res2) << "\n";
}
signed main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
int t=1;
cin>>t;
while(t--)solve();
}
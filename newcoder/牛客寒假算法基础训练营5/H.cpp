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
    int n;
    cin>>n;
    if(n==1){
        cout<<"Yes"<<endl;
        return ;
    }
    int s=0;
    vector<vector<int>>a(n,vector<int>(n+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            s+=a[i][j];
        }
    }
    if(s%(n*n)!=0){
        cout<<"No"<<endl;
        return ;
    }
    //我们将矩阵像国际象棋棋盘一样涂上黑白两色（坐标和i+j%2)
    //任何一对“相邻数字”必然包含一个黑格和一个白格。
    //肯定都是一个黑加一个黑少 一个白加一个白少
    int change=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]-=s/(n*n);
            if((i+j)%2==0)change+=a[i][j];
            else change-=a[i][j];
        }
    }
    if(change!=0){
        cout<<"No"<<endl;
        return ;
    }
    //水平操作：第一行和改变了 ±2，第二行和改变了 ∓2。行和的奇偶性不变。
    //垂直操作：第一列和改变了 ±2  第二列和改变了 ∓2。列和的奇偶性不变。
    for(int i=0;i<n;i++){
        int sum1=0,sum2=0;
        for(int j=0;j<n;j++){
            sum1+=a[i][j];
            sum2+=a[j][i];
        }
        if(sum1%2!=0){cout<<"No"<<endl;return ;}
        if(sum2%2!=0){cout<<"No"<<endl;return ;}
    }
    //变成相同的数字和全部变成0是一个道理
    //所以这里是奇偶性是要为偶数
    cout<<"Yes"<<endl;
}
signed main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
int t=1;
//cin>>t;
while(t--)solve();
}
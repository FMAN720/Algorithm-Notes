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
    /*
    | ->r
    0--------c
    |-r
    */
   //r是一半的高度
   //c是宽度
    int n,k,r,c;
    cin>>n>>k>>r>>c;
    struct S{int p,v;}a[n];
    for(int i=0;i<n;i++)cin>>a[i].p>>a[i].v;
    double l=0.0,h=1e18;
    /*
    这在竞赛中比 while(h-l > eps) 更常用，因为它可以强制保证精度，
    且不会因为浮点数精度误差导致死循环。100次迭代能提供极高的精度
    2^-100
    */
    for(int i=0;i<100;i++){
        double mid=(l+h)*0.5;
        vector<pair<double,double>>b;
        for(auto&t:a){    
            double v=t.v*mid;
            if(v<r)continue;//来算这个点和这个时间的情况下，可以覆盖到哪里
            //如果这个圆的半径都到不了r，那肯定不可以
            double h=sqrt(v*v-r*r);
            double L=t.p-h,R=t.p+h;
            L=max(0.0,L);
            R=min(R,c*1.0);
            b.push_back({L,R});
        }
        sort(all(b));//以右端点排序
        double x=0.0;
        int j=0;//指针的作用
        int cnt=0;//用了几个开关
        bool find=false;
        int m=b.size();
        while(x<c){
            //要一层一层的覆盖过去
            //直到覆盖到c
            double y=x;
            while(j<m&&b[j].first<=x){
                y=max(y,b[j].second);
                j++;
            }
            if(y==x)break;
            cnt++;
            if(cnt>k)break;
            x=y;
            if(x>=c){
                find=true;
                break;
            }
        }
        if(find)h=mid;
        else l=mid;
    }
    cout<<fixed<<setprecision(10)<<l<<endl;
}
signed main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
int t=1;
//cin>>t;
while(t--)solve();
}
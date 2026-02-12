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
   int n,m,q;
   cin>>n>>m>>q;
   vector<vector<int>>a(n+1,vector<int>(m+1)),signxy(n+1,vector<int>(m+1));
   for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        cin>>a[i][j];
    }
   }
   int maxx=-1,maxxi=1,maxxj=1;
   for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        int hurt=0;
        for(int x=-2;x<=2;x++){
            for(int y=-2;y<=2;y++){
                if(abs(x)+abs(y)<=2){
                  if(i+x<1||i+x>n||j+y<1||j+y>m)continue;
                else{
                    hurt+=a[i+x][j+y];
                }  
              }    
            }
        }
        signxy[i][j]=hurt;
        if(maxx<signxy[i][j]){
            maxx=signxy[i][j];
            maxxi=i;
            maxxj=j;
        }
    }
   }
   while(q--){
    int xx,yy,zz;
    cin>>xx>>yy>>zz;
    for(int x=-2;x<=2;x++){
        for(int y=-2;y<=2;y++){
            if(abs(x)+abs(y)<=2){
                if(xx+x<1||xx+x>n||yy+y<1||yy+y>m)continue;
                else{
                signxy[xx+x][yy+y]+=zz;
                if(signxy[xx+x][yy+y]>maxx){
                    maxx=signxy[xx+x][yy+y];
                    maxxi=xx+x;
                    maxxj=yy+y;
                }
                }
            }
        }
    }
    cout<<maxxi<<" "<<maxxj<<endl;
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
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lll __int128
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define pq priority_queue
//const int MOD = 998244353;
const int N = 200005;
int fastpow(int base, int exp,int MOD) {
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
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ddx[8]={0,1,0,-1,1,-1,1,-1};
int ddy[8]={1,0,-1,0,1,-1,-1,1};
//这个解法是这样的
/*
暴力枚举x和y
要求x/y的第f位的小数
x*(10^f-1)/y=一个整数，加上x*(10^f-1)%y/y
类型于30/7=4+2/7.这个2/7的小数点后的第一个数就是我们想要的
我们可以 ---> 2*10/7,就可以得到这个第一个数字

这里的快速幂得到的不是一个10^的一个数字   这里的快速幂函数要改变的原因是，
我们把这个很大的10的几次方的数字拿来算和把取余过后的拿来算是一个道理
因为这个10^本来就要对于分母取余的嘛-->如果不这样的话，太大了，会WA的
*/


//但是这一题可以换一个写法

/*
我们注意到

余数1~8都是可以用D/9得到
0和9的话
1/11=0.090909
10/11=0.909090

代码如下

void solve() {
    int a, b;
    cin >> a >> b;
    if (b == 0) {
        if (a & 1)
            cout << 1 << " " << 11 << endl;
        else
            cout << 10 << " " << 11 << endl;
    } else if (b == 9) {
        if (a & 1)
            cout << 10 << " " << 11 << endl;
        else
            cout << 1 << " " << 11 << endl;
    } else {
        int g = gcd(b, 9);//注意这里要最简，就是分子分母要互质
        cout << b / g << " " << 9 / g << endl;
    }
}


tmd，c!!
*/
void solve(){
    int n,m;cin>>n>>m;
    for(int i=2;i<=1000;i++){
        int move=fastpow(10,n-1,i);//特殊的fastpow
        for(int j=1;j<i;j++){
            if(__gcd(i,j)==1){
                int res=j*move%i;
                if(res*10/i==m){
                    cout<<j<<" "<<i<<endl;
                    return ;
                }
            }
        }
    }
}
signed main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
int t=1;
cin>>t;
while(t--)solve();
}
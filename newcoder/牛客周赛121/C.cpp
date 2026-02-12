/*#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod=998244353;
int sum(int n){
    //如果是负数的话，不就爆炸了吗
    if(n==0)return 1;
    if(n==1)return 1;
    else return n*sum(n-1)%mod;//这样是不对的，(a/b)%mod!=(a%mod/b%mod)%mod
}
void solve(){
    int n,ans=1;
    string s;
    cin>>n>>s;
    set<char>ss;
    vector<int>a(26);
    for(int i=0;i<s.length();i++){
        a[s[i]-'a']++;
        ss.insert(s[i]);
    }
    if(ss.size()<3){cout<<"0"<<endl;return ;}
    for(int i=0;i<26;i++){
        if(a[i]!=0)ans=(ans*a[i])%mod;
    }
    int m=ss.size();
    cout<<(ans*m*(m-1)*(m-2))%mod;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
     int t=1;
     while(t--)solve();
}*/

//题目都看不懂吗你啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊 啊啊，是任选三个字母
//你的那个解法的意思是，所有的方案相乘，再乘以A(3,3),这个算出来的是什么鬼
#include<iostream>
#include<vector>
#include<string>
#include <assert.h>
using namespace std;
#define int long long
const int mod = 998244353;
void solve(){
    int n;
    string s;
    if (!(cin >> n >> s)) return;
    // 统计每种字符的出现次数
    vector<int> cnt(26, 0);
    for(char c : s){
        cnt[c - 'a']++;
    }
    // dp[i] 表示选择了 i 个不同字符的组合方案数
    vector<int> dp(4, 0);
    dp[0] = 1; // 选0个字符方案数为1
    // 遍历26种字符
    for(int i = 0; i < 26; i++){
        if(cnt[i] == 0) continue;
        int c = cnt[i];
        // 类似于01背包，倒序更新
        // 更新 dp[3]: 在已选2个的基础上，再选当前这个字符
        dp[3] = (dp[3] + dp[2] * c) % mod;
        // 更新 dp[2]: 在已选1个的基础上，再选当前这个字符
        dp[2] = (dp[2] + dp[1] * c) % mod;
        // 更新 dp[1]: 在已选0个的基础上，再选当前这个字符
        dp[1] = (dp[1] + dp[0] * c) % mod;
    }
    //
/*  这个dp怎么理解呢，就是
    1.假设来了10个a，那么dp【1】就是10，
    2.又来了10个b那么dp[2]就是10*10=100,dp[1]=10+10=20
    3.这个时候又来了10个c那么dp[3]=100*10,dp[2]=100+20*10=300,dp[1]=20+10=30
    假设有n种字母，每种字母出现测次数都是k，依此推类，就可以知道三种不同字母组成的不同
    组合的和*/
    //为什么是从3-2-1呢？算3的时候要的是这个字母没有加进来时候的dp[2],如果是1-2-3的话，就重复了
    //这个6是因为A（3，3）=6
    int ans = (dp[3] * 6) % mod;
    cout << ans << endl;
}
void solve2() {
    int n, cnt = 0;
    string s;
    cin >> n >> s;
    vector<int> c(26);
    for (auto v : s) c[v - 'a']++;
    for (auto v : c) cnt += v > 0;
    assert(cnt >= 3);
    int ans = 0;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            for (int k = 0; k < 26; ++k) {
                if (i != j && j != k && i != k && c[i] && c[j] && c[k]) ans += c[i] * c[j] * c[k];
            }
        }
    }
    cout << ans * 6 << "\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
    solve();
    return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
int n,q,sum=0;
cin>>n>>q;
vector<int>a(n+1);
vector<int>pri(n+1);//前缀和
vector<pair<int,int>>aa;
for(int i=1;i<=n;i++){
cin>>a[i];
sum+=a[i];
pri[i]=pri[i-1]+a[i];
}
aa.push_back({1,a[1]});
for(int i=2;i<=n;i++){
    if(a[i]<aa.back().second){
        aa.push_back({i,a[i]});
    }
    else{
        aa.push_back({i,aa.back().second});
    };
}
while(q--){
    int oi;
    cin>>oi;
    if(oi==1){
        int x;
        cin>>x;
        sum=sum-(pri[x]-(aa[x-1].second)*x);      
    }
    else if(oi==2){
        int y;
        cin>>y;
        int temp=sum-pri[y-1];//后缀原来的和
        sum=sum-(temp-aa[n-1].second*(n-y+1));
    }
    else cout<<sum<<endl;
}
}
signed main(){
   int t;
   cin>>t;
   while(t--)solve(); 
}*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
    int n,q;
    ll sum=0; // 用ll避免溢出
    cin>>n>>q;
    vector<int>a(n+1);          // 原数组（1~n）
    vector<ll>pri(n+1, 0);      // 前缀和数组（pri[i] = a[1]+...+a[i]）
    vector<pair<int, int>> pre_min(n+1); // pre_min[i] = {i, 前i个元素的最小值}
    vector<pair<int, int>> suf_min(n+1); // suf_min[i] = {i, 从i到n的最小值}
    // 1. 输入数组并计算前缀和、总和
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum += a[i];
        pri[i] = pri[i-1] + a[i];
    }
    // 2. 初始化pre_min：前i个元素的最小值
    pre_min[1] = {1, a[1]};
    for(int i=2;i<=n;i++){
        pre_min[i].first = i;
        pre_min[i].second = min(a[i], pre_min[i-1].second); // 正确取前i个的最小值
    }
    // 3. 初始化suf_min：从i到n的最小值（补充原代码缺失的后缀最小值）
    suf_min[n] = {n, a[n]};
    for(int i=n-1;i>=1;i--){
        suf_min[i].first = i;
        suf_min[i].second = min(a[i], suf_min[i+1].second);
    }
    // 4. 处理查询
    while(q--){
        int oi;
        cin>>oi;
        if(oi==1){
            // 类型1：将前x个元素全部替换为前x个的最小值，更新sum
            int x;
            cin>>x;
            ll old_sum = pri[x];                // 前x个元素原来的和
            ll new_sum = (ll)pre_min[x].second * x; // 替换后的和
            sum = sum - old_sum + new_sum;      // 正确更新sum：减旧值+加新值
        }
        else if(oi==2){
            // 类型2：将y到n的元素全部替换为y到n的最小值，更新sum
            int y;
            cin>>y;
            ll old_sum = pri[n] - pri[y-1];     // y到n原来的和
            ll cnt = n - y + 1;                 // 元素个数
            ll new_sum = (ll)suf_min[y].second * cnt; // 替换后的和
            sum = sum - old_sum + new_sum;      // 正确更新sum
        }
        else if(oi==3){
            // 类型3：输出当前sum
            cout<<sum<<endl;
        }
    }
}
signed main(){
    ios::sync_with_stdio(false); // 加速cin/cout
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
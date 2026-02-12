#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void test_case_run() {
    int n;
    cin >> n;
    ll a[n+1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll sum = 0;
    for (int i = 2; i <= n; i++) sum += abs(a[i]-a[i-1]);
    ll ans = min(sum - abs(a[2]-a[1]), sum - abs(a[n]-a[n-1]));
    for (int i = 2; i < n; i++) {
        ans = min(ans, sum - abs(a[i+1]-a[i]) - abs(a[i]-a[i-1]) + abs(a[i+1]-a[i-1]));
    }   
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) test_case_run();
    return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve(){
int n;
scanf("%d",&n);
int a[n]={0},b[n],sum=0,max_num=INT_MIN;
for(int i=0;i<n;i++)scanf("%d",&a[i]);
for(int i=0;i<n-1;i++){
    b[i]=abs(a[i+1]-a[i]);
    sum+=b[i];
    max_num=max(b[i],max_num);
}
for(int i=0;i<n-1;i++){
    if(b[i]==max_num){
        if(i!=0&&i!=n-2)sum=sum-b[i]-b[i-1]+abs(a[i+1]-a[i-1]);
        else sum-=b[i];
        break;}
    }
cout<<sum<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}
这样写错误的原因在于：只单纯的考虑了相邻两元素差值绝对值最大的情况，
举一个简单的反例，直接证明第二段代码错误：
反例数组
a = [1, 10, 1, 10, 1]
步骤 1：计算相邻差值（b 数组）
b[0] = |10-1|=9，b[1] = |1-10|=9，b[2] = |10-1|=9，b[3] = |1-10|=9所有相邻差都是 9，
max_num=9，第二段代码会选择第一个出现的最大差（i=0）。
步骤 2：第二段代码的计算结果
i=0 是首尾（n-2=3，i=0≠3），所以执行 sum -= b[i]：原 sum = 9+9+9+9=36，
减去 b [0]=9，结果为 27。

但是最优的结果因该是18才对
*/
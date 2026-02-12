#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define Oliveira signed
void solve(){
    int n,ans=0;
    cin>>n;
    vector<int>a(n+1),cnt(31);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=0;j<=30;j++){
            if((a[i]>>j)&1)cnt[j]++;
        }
    }
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=0;j<=30;j++){
            if((a[i]>>j)&1){
                //相当于1*2^j
                sum+=(1<<j)*(n-cnt[j]);
            }else{
                sum+=(1<<j)*(cnt[j]);//这里记得括号，优先级不同
            }
            ans=max(ans,sum);
        }
    }
    cout<<ans<<endl;
}
Oliveira main(){
    int t;
    cin>>t;
    while(t--)solve();
}
//题解：
/*
题目的理解首先要理解好，是给你n个数字
//相同是0,不同是1
让你计算出来最大的''一直异或''是多大，这个ak可以是任何数字，可以是a1,a2…………
就是遍历所有的数字让它作为x^y中的x,求出最大的那个最优解



https://codeforces.com/blog/entry/141796
这个理解起来非常简单，但是写出来就有点难了
*/




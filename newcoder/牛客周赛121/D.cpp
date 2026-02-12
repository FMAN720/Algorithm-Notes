#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
//00010001
/*
void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for(int i=0;i<=n;i++){
        int temp=i,cnt=0,j=0;
        for(j=0;j<s.length();j++){
            if(s[j]=='0'){
            cnt++;
            if(cnt==k){
                temp--;
                cnt=0;
            }
            }
            else {
            cnt=0;
            }
            if(temp<0)break;
        }
        cout<<j<<" ";//这个地方输出j而不是j-1的原因就是，本来输出的就该是j+1，例如2就代表走到
        第三个格子，但是要再减去一，因为走到第三个格子不满足条件，走到第三个格子就是连续k个0了
        所以要-1
        j+1-1=j
    }
}*/
//虽然是对的，但是n^2这个复杂度太高了，需要更加简便的方法
void solve(){
    int n,k;
    string s;
    cin>>n>>k>>s;
    vector<int>a(n+1);
    int cost=0,cnt=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0'){
            cnt++;
            if(cnt==k){
            cost++;
            cnt=0;
            }
        }
        else{
            cnt=0;
        }
        if(cost<=n)a[cost]=i+1;//这里是i+1,上面那个是j的原因是，
        //上面那个是死在第j+1天，这里是在i+1天还活着
        else break;
    }
    //有可能出现这种情况，就是a[3]=5，它后面的都是0了，因为，当消耗3次的时候就走完了
    //所以为了避免这种情况的发生，我们就是直接取一个前缀max
    for(int i=1;i<=n;i++)a[i]=max(a[i],a[i-1]);//前缀max，因为这个
    for(int i=0;i<=n;i++)cout<<a[i]<<" \n"[i==n];
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    int t=1;
    while(t--)solve();
}
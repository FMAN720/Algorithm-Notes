#include<bits/stdc++.h>
using namespace std;
#define int long long
using ll=long long;
typedef unsigned long long ull;
//https://www.luogu.com.cn/problem/solution/CF2009E，这里就是有一段连续有序的一段数列
//要找出一个分段点，起始点的数值是k,有n个数字 sum1=k+…………k+R-1，sum2=k+R+…………k+n
//等差数列求和，sum1-sum2的绝对值要最小，求的就是这个最小的绝对值，
//这个式子求出来就是个二次函数，所以想到用三分法
ll k,n;
ll check(ll r)
{
	return abs(k*n-2*k*r+(n*n-2*r*r+2*r-n)/2);
}
void solve(){
   cin>>n>>k;
   int ans=INT_MAX;
   int l=0,r=n;
   while (l<r)
   {
    int midl=(2*l+r)/3;
    int midr=(l+2*r)/3;
    if(check(midl)<check(midr)){
        ans=min(check(midl),ans); 
        r=midr-1;
    }else{
        ans=min(ans,check(midr));
        l=midl+1;
    }
   }
   cout<<ans<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}
//这个跟那个模板的区别在哪里？，就是那个模板它式double的，他的那个l和r是不用+1和-1的，但是如果
//你也不加一减一的话，那么就死循环了，
//还有，不可以直接写check(l)或者check(r),如果是double的话，可以但是int就是不可以

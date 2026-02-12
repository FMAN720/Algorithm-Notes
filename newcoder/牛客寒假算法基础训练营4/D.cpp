#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(a) a.begin(),a.end()
int f(int n)
{
    if(n==0)return 0;
    int w=1;
    while(n>0)
    {
        w*=(n%10);
        n/=10;
    }
    return w;
}
 
int g(int n)
{
    int i=0;
    while(f(n)!=n)
    {
        i++;
        n=f(n);
    }
    return i;
}
//这里的j参数是减去重复的
//例如2 3 和3  2这种的
//比如2 3 4和2 4 3都是24，但是没必要算多次，算一次就好了
void dfs(int n,int w,int j)
{
    if(n>=18)
    {
        if(g(w)>10)cout<<w<<":"<<g(w)<<"\n";
        return;
    }
    for(int i=j;i<=9;i++)
    {
        dfs(n+1,w*i,i);
    }
}
void d(int x)
{
    vector<int> a;
    for(int i=9;i>=2;i--)
    {
        while(x%i==0)
        {
            a.push_back(i);
            x/=i;
        }
    }
    if(x==1)
    {
        for(int i:a)cout<<i<<" ";
        cout<<"\n";
    }

}//由dfs可以知道，10^18的范围内是没有哪一个数字是g(w)>10的，
//由d函数可以把这个w给拆开，这样就又增加了一次，所以最大是11
signed main(){
dfs(1,1,2);//什么都没有，说明dfs搜索不出来某个数字是g（w)>10的
d(937638166841712);
d(4996238671872);
cout<<99999999998777772<<998888887777772<<endl;
}

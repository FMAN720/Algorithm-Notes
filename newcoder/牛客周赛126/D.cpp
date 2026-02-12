#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll=long long;
typedef unsigned long long ull;
int QuickSum(int x,int y){
    int temp=1;
    while(y!=0){
        if(y&1)temp*=x;
        x*=x;
        y>>=1;
    }
    return temp;
}
void solve(){
int x,y,n;
cin>>x>>y>>n;
//先是从左开始向左看，然后从右开始向右看
//<-1 <-5 4->1->   
vector<int>a(x),b(y);
set<int>q;
for(int i=0;i<x;i++)cin>>a[i];
for(int i=0;i<y;i++)cin>>b[i];
//这两个你一定要递增
for(int i=1;i<x;i++){
    if(a[i]<=a[i-1]){cout<<"-1"<<endl;
    return ;}
}
for(int i=1;i<y;i++){
    if(b[i]<=b[i-1]){
        cout<<"-1"<<endl;
        return ;
    }
}
if(a.back()!=b.back()){
cout<<"-1"<<endl;
return ;}
b.pop_back();
reverse(b.begin(),b.end());
if(a.size()+b.size()<n){
    while(a.size()+b.size()<n){
    a.emplace_back(a.back());
}
}
if(a.size()+b.size()>n){cout<<"-1"<<endl;return ;}
for(int i=0;i<a.size();i++)cout<<a[i]<<" ";
for(int i=0;i<b.size();i++)cout<<b[i]<<" ";
cout<<endl;
}
signed main(){
    int t=1;
    while(t--)solve();
}
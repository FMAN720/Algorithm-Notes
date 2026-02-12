#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll=long long;
void solve(){
int na,nb;
cin>>na>>nb;
string a,b;
cin>>a>>b;
queue<int>aa,bb;
for(int i=0;i<na;i++)aa.push(a[i]-'0');
for(int i=0;i<nb;i++)bb.push(b[i]-'0');
while(aa.size()&&bb.size()){
    if(aa.front()!=bb.front()){
        int x=aa.front();
        aa.pop();
        aa.front()^=x;
    }else{
        aa.pop();
        bb.pop();
    }
}
//当aa队列不是空的的时候也是可以的，只要队列里剩余的数字的异或和是0就可以了，0跟所有异或等于这个
//数字本身
int remind=0;
while(aa.size()){
    remind^=aa.front();
    aa.pop();
}
if(remind==0&&!bb.size()){
    cout<<"YES"<<endl;
}else{
    cout<<"NO"<<endl;
}
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}
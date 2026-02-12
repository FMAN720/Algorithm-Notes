#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve(){
string s;
cin>>s;
int n=s.length(),pos=-1;
vector<int>idx1;
for(int i=0;i<n;i++){
    if(s[i]=='1')idx1.push_back(i);
}
if(idx1.size()<=1)cout<<s<<endl;
else{
    int judge=idx1.size()&1;//判断是不是奇数
    vector<int>mark(n);
    int cnt=idx1.size()/2;
    for(int i=0;i<cnt;i++){
        mark[idx1.back()]='2';
        idx1.pop_back();
    }
    char p='.';
    int ptr=idx1.size()-1;
    for(int i=n-1;i>=0;){
        while(i>=0&&i>idx1[ptr]){
            if(s[i]!='1')
            p=s[i];
            i--;
        }
            if(p=='2'){
                pos=i;
            }
        ptr--;
        if(ptr<0)break;
    }
    if(judge){
        if(pos==-1)mark[idx1.back()]='1';
        else mark[pos]='1';
    }
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            if(mark[i]=='1')cout<<"1";
            else if(mark[i]=='2')cout<<"2";
        }else cout<<s[i];
    }
    cout<<endl;
}
}
signed main(){
    int t=1;
    while(t--)solve();
}
#include<iostream>
#include<vector>
using namespace std;
#define int long long
#define endl '\n'
void solve(){
string s;
cin>>s;
vector<int>cnt1;
for(int i=0;i<s.length();i++){
    if(s[i]=='1')cnt1.push_back(i);
}
vector<int>mark(s.length());
int l=0,r=cnt1.size()-1,lst=-1;
for(int i=0;i<s.length();i++){
    if(s[i]=='2')lst=i;
    else if(s[i]=='0'){
        while(l<=r&&cnt1[l]<lst){
            l++;
        }
        while(l<=r&&cnt1[l]<i){
        if(cnt1[r]<i)break;
        mark[cnt1[l]]=1;
        mark[cnt1[r]]=2;
        l++;
        r--;
        }
    }
}
for(int i=0;i<s.length();i++){
    if(mark[i]==1)continue;
    else if(mark[i]==2)cout<<"2";
    else cout<<s[i];
}
cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t=1;
    while(t--)solve();
}
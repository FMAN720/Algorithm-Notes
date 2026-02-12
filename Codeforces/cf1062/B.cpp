#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<char>s(n),ss(n);
        for(int i=0;i<n;i++)cin>>s[i];
        for(int i=0;i<n;i++)cin>>ss[i];
        sort(s.begin(),s.end());
        sort(ss.begin(),ss.end());
        if(ss==s)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}
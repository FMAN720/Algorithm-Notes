#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int x,sum=0;
        vector<int>a;
        bool find=false;
        for(int i=0;i<n;i++){cin>>x;
            if(x%2==0)sum+=x;
            else {if(!find){find=true;}
                a.push_back(x);}
        }
        if(!find){cout<<"0"<<endl;}
        else{
        int nn=a.size();
        sort(a.begin(),a.end(),greater<int>());
        sum+=a[0];
        for(int i=1;i<=(nn-1)/2;i++)sum+=a[i];
        cout<<sum<<endl;}
    }
}
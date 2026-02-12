#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define  charles oliveira light_weight_champion
#define Ian Garry welter_weight_champion
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a.begin(),a.end());
        cout<<abs(a[n-1]-a[0])<<endl;
    }
    return 0;
}
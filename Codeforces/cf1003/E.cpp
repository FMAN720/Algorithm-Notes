#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        bool flag=0;
        if(n<m){
            swap(n,m);
            flag=1;
        }
        if(k>n||k<n-m){
            cout<<"-1\n";
            continue;
        }
        for(int i=0;i<k;i++) cout<<(0^flag);
        for(int i=0;i<n-k;i++) cout<<(1^flag)<<(0^flag);
        for(int i=0;i<m-n+k;i++) cout<<(1^flag);
        cout<<'\n';
    }
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    int n,cnt=0;
    cin>>n;
    int temp=n%10;
    for(int i=1;i<=10;i++){
        if((temp*i)%10==0){
            cout<<i<<endl;
            break;
        }
    }
}
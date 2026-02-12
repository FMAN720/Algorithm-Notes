#include<bits/stdc++.h>
using namespace std;
#define int long long
using ll=long long;
typedef unsigned long long ull;
void solve(){
 string s[7] = {"Red", "Orange", "Yellow", "Green", "Blue", "Indigo", "Violet"};
 int a[7];
 int max_num=-1;
 int max_i=0;
 for(int i=0;i<7;i++){
    cin>>a[i];
    if(a[i]>max_num){max_i=i;
    max_num=a[i];}
}
cout<<s[max_i]<<endl;  
}
signed main(){
int t=1;
while(t--)solve();
}
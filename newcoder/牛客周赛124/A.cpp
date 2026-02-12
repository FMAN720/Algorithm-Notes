#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve(){
int a,b;
scanf("%d %d",&a,&b);
if(a>b)printf("Alice");
else if(a<b)printf("Bob");
else printf("Draw");
}
signed main(){
    int t=1;
    while(t--)solve();
}
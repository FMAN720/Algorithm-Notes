#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int distance(int x,int y,int x2,int y2){
    return (x*x+y*y)-(x2*x2+y2*y2);
}
void solve(){
    int a,b,c,d,e,f;
    scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
    if(distance(a,b,c,d)==distance(c,d,e,f))printf("Yes");
    else printf("NO");
}
signed main(){
    int t=1;
    //scanf("%d",&t);
    while(t--)solve();
}
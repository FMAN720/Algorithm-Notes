#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define oliveira light_weight_champion
#define Ian Garrt Welter_weight_champion
signed main(){
    int x,y,p1,p2;
    cin>>x>>y>>p1>>p2;
    if(x>y)cout<<"A"<<endl;
    else if(y>x)cout<<"B"<<endl;
    else if(x==y&&p1<p2)cout<<"A"<<endl;
    else if(x==y&&p1>p2)cout<<"B"<<endl;
    else cout<<"C"<<endl;
}
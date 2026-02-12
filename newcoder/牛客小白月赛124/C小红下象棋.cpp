#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[]={-2,-1,1,2,-2,-1,1,2};
int b[]={-1,-2,-2,-1,1,2,2,1};
//模拟一个马可以走的各个方向
void solve(){
    int x,y, n;
    cin>>x>>y>>n;//王的位置
    int cnt=0,cnt_f=0;//一个用来判断是不是没地方跑了，一个用来判断是不是被将军了
    for(int i=0;i<n;i++){
        //马的位置
        int xx,yy;
        cin>>xx>>yy;
        for(int i=0;i<8;i++){
            if(abs(xx+a[i]-x)<=1&&abs(yy+b[i]-y)<=1)cnt++;
            if(abs(xx+a[i]-x)==0&&abs(yy+b[i]-y==0))cnt_f++;
        }
    }
    if(cnt>=8){//这里，不用担心如果满足了条件但是王还有地方走的可能，这个是不可能的，因为不可能在同一个
        //地方有多个马
        //要值得注意的是这里的>=8,不是==8，这里仔细想一下就知道了
        if(cnt_f>0)cout<<"B"<<endl;
        else cout<<"A"<<endl;
    }else cout<<"C"<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
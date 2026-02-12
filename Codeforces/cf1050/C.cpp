#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int px=0,py=0,point=0;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            point+=x-px;//开始的时候都用0，这样可以判断开始的时候是不是要动
            //如果两个坐标相减的奇偶性和两个坐标的要求相减的奇偶性相同，
            //那么就是可以在范围内一直动，一分钟动一次
            //这样的得分最高
            if(abs(x-px)%2!=abs(y-py)%2)point--;
            //如果不相同那么就要等一分钟再出发，这样就会少得一分
            px=x,py=y;  
        }
        if(px!=m)point+=m-px;//如果最后一个要求小于m，也就是总的长度，那么在剩下的没有要求的时间段内
        //可以任意的动，为了打到最好的效果，那么就是一直动，一分钟动一次
        cout<<point<<endl;
    }
}
//https://codeforces.com/contest/2148/problem/C
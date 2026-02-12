#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll=long long;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<long long>a(n),b(m);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    set<int>c(b.begin(),b.end());
    //sort(b.begin(),b.end());
    //贪心的思路是，在满足条件的情况下，要求前一个的数字尽量小
    //x-a[i]>=a[i-1]
    //x>=a[i]+a[i-1]
    for(int i=0;i<n;i++){
        if(i==0)a[i]=min(a[i],*c.begin()-a[i]);
        else{
            auto it=c.upper_bound(a[i]+a[i-1]-1);//找到严格大于a[i]+a[i-1]-1的数字，在
            //队列c中，这里是保证这个it尽量小
           if(it!=c.end()){
            if(a[i]>=a[i-1])a[i]=min(a[i],*it-a[i]);//这里是大于等于，当a[i]==a[i-1]
            //如果a[i]本来就大于a[i-1],那就让他尽量小
            else a[i]=*it-a[i];
           }
           //如果找不到的话，说明不用考虑，因为考虑了也没用，也不能做什么,不管是不是大于后面的
           //还是小于后面的，你都做不了什么，因为你没做，可能大于前面的，做了一定小于前面的
        }
    }
    if(is_sorted(a.begin(),a.end())){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}

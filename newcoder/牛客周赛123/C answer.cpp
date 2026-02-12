#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
struct poke{
    int value;
    char sign;
    int idx;
};
void solve(){
    int n;
    cin>>n;
    vector<poke>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i].value>>a[i].sign;
        a[i].idx=i;
    }
    sort(a.begin()+1,a.end(),[](const poke &x,const poke &y){
        if(x.value!=y.value)return x.value<y.value;
        return x.sign<y.sign;
    });
    vector<pair<int,int>>rec;
    int cnt=0;
    for(int i=1;i<=n;){
        int j=i;
        vector<poke>tmp;
        unordered_set<char>aa;
        while(j<=n&&a[j].value==a[i].value){
            if(aa.find(a[j].sign)==aa.end()){
                aa.insert(a[j].sign);
                tmp.push_back(a[j]);
            }
            j++;//因为已经按照已有的规则排好序了，j++就是检查下一个是不是跟上一个一样的
        }//去重
        for(int k=0;k+1<tmp.size();k+=2){
            rec.push_back({tmp[k].idx,tmp[k+1].idx});
            cnt+=2;
        }
        i=j;//相当于，数字是1的找完了，现在开始找数字是2的。
    }
    cout<<cnt<<endl;
    for(auto &p:rec)cout<<p.first<<" "<<p.second<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

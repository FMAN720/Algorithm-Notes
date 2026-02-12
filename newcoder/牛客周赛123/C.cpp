#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct poke{
    int value;
    char sign;
    int idx;
};
void solve(){
    int n,cnt=0;
    cin>>n;
    vector<poke>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i].value>>a[i].sign;
        a[i].idx=i;
    }
    sort(a.begin()+1,a.end(),[](const poke&a,const poke&b){
        if(a.value!=b.value)return a.value<b.value;
        return a.sign<b.sign;
    });
    vector<pair<int,int>>rec;
    for(int i=1;i<=n;){
    unordered_set<char>aa;
    vector<poke>temp;
        int j=i;
        while(j<=n&&a[i].value==a[j].value){
            if(aa.find(a[j].sign)==aa.end()){
            aa.insert(a[j].sign);
            temp.push_back(a[j]);
            }
            j++;
        }
        for(int k=0;k+1<temp.size();k+=2){
            rec.push_back({temp[k].idx,temp[k+1].idx});
            cnt+=2;
        }
        i=j;
    }
    cout<<cnt<<endl;
    for(int i=0;i<rec.size();i++)cout<<rec[i].first<<" "<<rec[i].second<<endl;
}
signed main(){
    int t=1;
    while(t--)solve();
}
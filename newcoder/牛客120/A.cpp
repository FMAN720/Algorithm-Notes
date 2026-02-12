#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    int n;cin>>n;
    string s1="a";
    string s2="b";
    string s3="a";
    if(n==1)cout<<"aba"<<endl;
    else{
    int s=n-1;
    while(s--){
         s1+="a";
         s3+="a";
    }
    cout<<s1+s2+s3<<endl;}
    return 0;
}
/*#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    cout<<string(n,'a')+"b"+string(n,'a');
}*/
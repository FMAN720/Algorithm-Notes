#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    int l,r;
    cin>>l>>r;
   cout<<(r+2)/3-(l+1)/3<<(r+1)/3-l/3<<r/3-(l-1)/3<<endl;
}
//abcabcabcabc
//2      9
/*#include <cstdio>

int l, r;
int main(){
	scanf("%d%d", &l, &r);
	printf("%d %d %d", (r+2)/3-(l+1)/3, (r+1)/3-l/3, r/3-(l-1)/3);
	return 0;

    [1,r]中的取模为1的个数减去[1,l-1]中取模为1的数量，前缀和思想
    3*k+1<=n
    假设n=12
    k<=(n-1)/3=3.66666,就是3+1个数，因为k可以取0，
    即k=(n-1)/3+1,即(n+2)/3
    
}*/
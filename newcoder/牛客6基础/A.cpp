#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main()
{
    double a[3];cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    if(a[0]+a[1]<=a[2])cout<<"wtnl";
    else 
    {
        cout << "Yes"<<endl;
        printf("%.2lf %.2lf %.2lf",(a[0]+a[1]-a[2])/2,(a[0]+a[2]-a[1])/2,(a[2]+a[1]-a[0])/2);
    }
}
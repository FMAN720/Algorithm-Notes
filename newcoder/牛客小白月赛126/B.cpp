#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,n,a[100001],num,b[100001];
	cin>>T;
	while(T--)
	{
		cin>>n;
		num=0; 
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<n;i++)b[i]=a[i+1]-a[i];
		b[n]=8-a[n]+a[1];
		sort(b+1,b+n+1);
		for(int i=1;i<n;i++)num+=b[i];
		printf("%d\n",num);
	}
	return 0;
 } 
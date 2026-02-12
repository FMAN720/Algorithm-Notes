#include<bits/stdc++.h>

int n;
long T[110];
double a;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%ld",&T[i]);
	}
	std::sort(T,T+n);
    a=T[0];
	for(int i=0;i<n;i++){
		a=sqrt(a*T[i]);
	}
	printf("%12f",a);
}
//就是按照原来的思路，先把小的放到根号里

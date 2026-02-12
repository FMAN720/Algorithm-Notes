#include<bits/stdc++.h>
using namespace std;
int n,x,y,s;
int main(){
	cin>>n;
	while(n--){
		cin>>x>>y;
		if(x<=1&&y>=1)s++;
		if(x<=9&&y>=9)s++;
		cout<<s<<'\n';
		s=0;
	}
	return 0;
}//就他妈只有1和9，猜的对 
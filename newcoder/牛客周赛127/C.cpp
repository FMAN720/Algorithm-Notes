#include <iostream>
using namespace std;
int main(){
    //这个的问题是你是一定要四舍五入的，如果是3243的话，你不可以直接把原来的输出出来
    //你要把3240输出出来，你是一定要四舍五入的，一定要
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		int kai=0;
		int len=s.size();
		for(int i=0;i<len;i++){
			if(s[i]>='5'&& kai==0){
				kai=1;
				if(i==0){
					cout<<'1';
				}else{
					s[i-1]++;
				}
				
			}
			if(kai==1){
				s[i]='0';
			}
		}
		if(kai==0){
			s[len-1]='0';
		}
		cout<<s<<endl;
	}
	return 0;
}
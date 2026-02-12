#include<iostream>
using namespace std;
constexpr int N=2e5+5;
int T,n,k,a[N];
int main(){
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		
		// 算法核心：贪心构造字典序最大序列
		int i,j,pos=1;  // pos记录当前找到的最大值位置
		for(i=j=1;i<=n;i++){  // 同时初始化i=1, j=1
			// 在成本k限制内寻找最大值
			// 注意：这里的j会在循环中持续增加，即使退出内层while也不会重置
			while(j-i<=k&&j<=n){  // j-i<=k 表示操作成本限制
				if(a[j]>a[pos])
					pos=j;  // 更新最大值位置
				++j;  // j持续向右扩展
			}
			// 此时j指向超出成本限制的位置或数组末尾的下一个位置
			
			if(a[pos]>a[i]){  // 如果找到更大的值
				if(i>pos){  // 这种情况在本算法中实际上不会发生
					if(!k) continue;
					a[i]=a[pos];
					++pos,--k;
				}
				else{  // i <= pos的情况
					// 将区间[i,pos)的所有元素替换为a[pos]
					// 操作成本为pos-i
					k-=pos-i;  // 减去本次操作的成本
					for(int loop_k=i;loop_k<pos;loop_k++)  // 修复：避免变量名冲突
						a[loop_k]=a[pos];  // 区间替换
				}
			}
			// 注意：算法中j没有重置，这是一个有意的设计
			// 它保持了滑动窗口的特性，继续向前搜索
		}
		for(int i=1;i<=n;i++)
			cout<<a[i]<<' ';
		cout<<'\n';
	}
	return 0;
}

/*
算法工作原理（以[3,1,4,1,4], k=3为例）：

1. i=1, j=1, pos=1: 在[1,1+3]=[1,4]范围内找最大值 -> pos=3(a[3]=4)
   执行替换 a[1..2] = 4, k变成3-(3-1)=1, 数组变为[4,4,4,1,4]

2. i=2: 已经在上一步被处理为4

3. i=3: a[3]=4已经是最大，无需替换

4. i=4: 在[4,4+1]=[4,5]范围内找最大值 -> pos=5(a[5]=4)
   a[5]=a[4]，无需替换

5. i=5: 处理完毕

实际上，由于j不重置的特殊设计，算法在寻找最大值时具有滑动窗口特性，
这使得它能在成本限制下有效地构造出字典序较大的序列。

注意：代码中的for(int k=i;k<pos;k++)存在变量名冲突，实际运行会有问题。
*/
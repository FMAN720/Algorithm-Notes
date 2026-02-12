#include<bits/stdc++.h>
using namespace std;
#define int long long
using ll=long long;
typedef unsigned long long ull;
void solve(){
		int n;
		scanf("%d",&n);
		if(n<=2 || n==4){
			printf("-1\n");
			return;
		}
		if(n%2==0){
			printf("1 2 1 ");
			n-=3;
		}
		for(int i=1;i<=n/2+1;i++) printf("%d ",i);
		for(int i=n/2;i>=1;i--) printf("%d ",i);
		printf("\n");
}	
signed main(){
int t=1;
cin>>t;
while(t--)solve();
}
/*import java.util.Scanner;

public class 牛客周赛127C {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            int n = scanner.nextInt();
            if (n <= 2 || n == 4) {
                System.out.println("-1");
            } else {
                if (n % 2 == 0) {
                    System.out.print("1 2 1 ");
                    n = n - 3;
                }
                for (int i = 1; i <= n/2 + 1; i++) {
                    System.out.print(i + " ");
                }
                for (int i = n/2; i >= 1; i--) {
                    if (i == 1) {
                        System.out.println(i);
                    } else {
                        System.out.print(i + " ");
                    }
                }
            }
        }
        scanner.close();
    }
}*/
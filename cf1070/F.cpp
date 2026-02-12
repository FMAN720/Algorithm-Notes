#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        vector<int> LAST(m, -1);
        
        for(int i = 0; i < n; i++) {
            bool shift = false;
            vector<int> CUR(m, 0);
            
            for(int j = 0; j < m; j++) {
                int elm = ((i * m + j) % k) + 1;
                if(elm == LAST[j]) {
                    shift = true;
                }
                CUR[j] = elm;
            }
            
            if(shift) {
                vector<int> temp = CUR;
                for(int j = 0; j < m; j++) {
                    CUR[j] = temp[(j+1) % m];
                }
            }
            
            for(int j = 0; j < m; j++) {
                cout << CUR[j];
                if(j < m-1) cout << " ";
            }
            cout << endl;
            
            LAST = CUR;
        }
    }
    
    return 0;
}




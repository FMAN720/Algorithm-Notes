#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        if(n == 0) {
            cout << "0" << endl;
            continue;
        }
        stack<char> s;
        for(char c : str) {//不用char c   while(cin>>c)
            //因为这样会一直读，直到读不了为止，会把下面的数据也在第一次读取掉
            if(!s.empty() && s.top() == '(' && c == ')') {
                s.pop();
            } else {
                s.push(c);
            }
        }
        cout << s.size() << endl;
    }
    return 0;
}/*char c;
    while (cin >> c) {
        if (s.empty()) s.push(c);
        else if (s.top() == '[' && c == ']' || s.top() == '(' && c == ')' || s.top() == '{' && c == '}') s.pop();
        else s.push(c);
    }
    if (s.empty()) cout << "Yes";
    else cout << "No";*/
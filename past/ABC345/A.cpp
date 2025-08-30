#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define nsort(a) sort(a.begin(), a.end())
#define rsort(a) sort(a.rbegin(), a.rend())
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int cnt=0;
    stack<char> st;
    rep(i, s.size()) {
        if(s[i]=='<') cnt++;
        if(st.empty()) {
            st.push(s[i]);
        } else if(s[i]=='>' && cnt) {
            while(st.top()=='=') {
                st.pop();
            }
            st.pop();
            cnt--;
        } else {
            st.push(s[i]);
        }
    }
    if(st.empty()) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}

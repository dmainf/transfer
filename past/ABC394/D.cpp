#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>; 
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    stack<char> st;
    rep(i, s.size()) {
        if(!st.empty() && (
          (st.top()=='(' && s[i]==')') || 
          (st.top()=='[' && s[i]==']') ||
          (st.top()=='<' && s[i]=='>')  
          )
        ) {
            st.pop();
        }
        else st.push(s[i]);
    }
    if(st.empty()) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
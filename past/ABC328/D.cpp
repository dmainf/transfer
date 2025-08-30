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
        st.push(s[i]);
        char C=st.top(); st.pop();
        if(C!='C' || st.empty()) {
            st.push(C);
            continue;
        }
        char B=st.top(); st.pop();
        if(B!='B' || st.empty()) {
            st.push(B);
            st.push(C);
            continue;
        }
        char A=st.top(); st.pop();
        if(A!='A') {
            st.push(A);
            st.push(B);
            st.push(C);
            continue;
        }
    }
    string ans;
    while(!st.empty()) {
        char x=st.top(); st.pop();
        ans+=x;
    }
    reverse(all(ans));
    cout << ans << endl;

    return 0;
}

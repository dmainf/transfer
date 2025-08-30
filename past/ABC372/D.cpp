#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    vector<int> ans(n);
    stack<int> st;
    drep(i, n) {
        ans[i]=st.size();
        while(!st.empty() && st.top()<h[i]) st.pop();
        st.push(h[i]);
    }
    rep(i, n)  cout << ans[i] << " \n"[i==n-1];

    return 0;
}

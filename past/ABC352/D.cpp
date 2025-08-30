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
    int n, k;
    cin >> n >> k;
    vector<int> p(n), q(n);
    rep(i, n) cin >> p[i];
    rep(i, n) p[i]--;
    rep(i, n) q[p[i]]=i;
    set<int> st;
    int ans=INF;
    rep(i, n) {
        st.emplace(q[i]);
        if(st.size()>k) st.erase(q[i-k]);
        if(st.size()==k) ans=min(ans, *st.rbegin()-*st.begin());
    }
    cout << ans << endl;

    return 0;
}
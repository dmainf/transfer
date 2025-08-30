#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pl = pair<ll, int>;
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<ll> somen(n, 0);
    set<int> st;
    rep(i, n) st.insert(i);
    priority_queue<pl, vector<pl>, greater<pl>> pq;
    rep(mi, m) {
        int t, w, s;
        cin >> t >> w >> s;
        while(!pq.empty()) {
            auto [time, idx]=pq.top();
            if(time<=t) {
                st.insert(idx);
                pq.pop();
            } else break;
        }
        if(st.empty()) continue;
        int idx=*st.begin();
        somen[idx]+=w;
        st.erase(idx);
        pq.push({t+s, idx});
    }
    rep(i, n) cout << somen[i] << endl;

    return 0;
}
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
    n*=k;
    vector<vector<int>> G(n);
    rep(i, n-1) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    function<int(int, int)> dfs=[&](int u, int p) {
        int used = 0, pend = 0;
        for(auto v : G[u]){
            if(v == p) continue;
            int d = dfs(v, u);
            if(d == -2) return -2;
            if(d > 0){
                if(used == 1) return -2;
                int cand = d + 1;
                if(cand == k){
                    if(pend != 0) return -2;
                    used = 1;
                } else {
                    if(pend == 0) pend = cand;
                    else{
                        if(pend + cand - 1 == k){
                            used = 1;
                            pend = 0;
                        } else return -2;
                    }
                }
            }
        }
        if(used == 1) return -1;
        if(pend != 0) return pend;
        return 1;
    };
    if(k == 1){
        cout << "Yes" << endl;
        return 0;
    }
    int res = dfs(0, -1);
    if(res==-1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}

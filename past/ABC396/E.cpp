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
const int MAX=1e6;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> G(n);
    rep(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    vector<bool> seen(n, false);
    vector<int> fval(n, 0);
    vector<int> a(n, 0);
    rep(i, n) {
        if(!seen[i]){
            vector<int> comp;
            queue<int> q;
            q.push(i);
            seen[i]=true;
            fval[i]=0;
            while(!q.empty()){
                int cur=q.front(); 
                q.pop();
                comp.push_back(cur);
                for(auto &edge:G[cur]){
                    int nxt=edge.first;
                    int w=edge.second;
                    if(!seen[nxt]){
                        seen[nxt]=true;
                        fval[nxt]=fval[cur] ^ w;
                        q.push(nxt);
                    } else {
                        if(fval[nxt]!=(fval[cur]^w)){
                            cout << -1 << endl;
                            return 0;
                        }
                    }
                }
            }
            int t=0;
            for(int bit=0; bit < 31; bit++){
                int cnt1=0;
                for(int v:comp){
                    if((fval[v]>>bit)&1) cnt1++;
                }
                int cnt0=comp.size()-cnt1;
                if(cnt1>cnt0)
                    t|=(1 << bit);
            }
            for (int v:comp){
                a[v]=t^fval[v];
            }
        }
    }
    rep(i, n) cout << a[i] << " \n"[i==n-1];
    
    return 0;
}
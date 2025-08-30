#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;
using ll=long long;
using pi=pair<int, int>;
using pl=pair<ll, int>;
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const ll INF=1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<vector<int>> d(n, vector<int>(n));
    rep(i, n) rep(j, n) {
        cin >> d[i][j];
    }
    //from 0 city to i city
    vector<ll> car(n, INF);
    {
        car[0]=0;
        priority_queue<pl, vector<pl>, greater<pl>> pq;
        pq.push({0, 0});
        while(!pq.empty()) {
            auto [w, v]=pq.top();
            pq.pop();
            if(w!=car[v]) continue;
            rep(nv, n) {
                ll n_wei=w+(ll)d[v][nv]*a;
                if(n_wei<car[nv]) {
                    car[nv]=n_wei;
                    pq.push({n_wei, nv});
                }
            }
        }
    }
    //from n-1 to i city
    vector<ll> train(n, INF);
    {
        train[n-1]=0;
        priority_queue<pl, vector<pl>, greater<pl>> pq;
        pq.push({0, n-1});
        while(!pq.empty()) {
            auto [n_wei, nv]=pq.top();
            pq.pop();
            if(n_wei!=train[nv]) continue;
            rep(v, n) {
                ll wei=n_wei+(ll)d[v][nv]*b+c;
                if(wei<train[v]) {
                    train[v]=wei;
                    pq.push({wei, v});
                }
            }
        }
    }
    ll ans=INF;
    rep(k, n) ans=min(ans, car[k]+train[k]);
    cout << ans << endl;

    return 0;
}
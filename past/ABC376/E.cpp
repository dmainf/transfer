#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const ll INF=1e18;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        rep(i, n) cin >> a[i];
        rep(i, n) cin >> b[i];
        vector<pi> p;
        rep(i, n) p.push_back({a[i], b[i]});
        sort(all(p));
        priority_queue<int, vector<int>, less<int>> pq;
        ll mn=INF;
        ll sum=0;
        rep(i, n) {
            auto [ai, bi]=p[i];
            pq.push(bi);
            sum+=bi;
            if(k<pq.size()) {
                int tmp=pq.top();
                pq.pop();
                sum-=tmp;
            }
            if(pq.size()==k) mn=min(mn, sum*ai);
        }
        cout << mn << endl;
    }

    return 0;
}
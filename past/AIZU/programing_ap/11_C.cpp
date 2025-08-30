#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> b(k);
    rep(i, k) cin >> b[i];
    sort(all(b));
    vector<pair<int, vector<int>>> ans;
    rep(x, (1<<k)) {
        bitset<28> d;
        vector<int> sub;
        rep(j, k) if(x&(1<<j)) {
            d.set(b[j]);
            sub.push_back(b[j]);
        }
        ans.push_back({d.to_ulong(), sub});
    }
    sort(all(ans));
    for(auto [d, tmp]:ans) {
        cout << d << ":";
        for(int e:tmp) cout << " " << e;
        cout << endl;
    }

    return 0;
}
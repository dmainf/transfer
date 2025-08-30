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
    vector<pair<int, vector<int>>> ans;
    rep(x, (1<<n)) if(__builtin_popcount(x)==k) {
        bitset<18> b;
        vector<int> tmp;
        rep(bit, n) if(x&(1<<bit)) {
            tmp.push_back(bit);
            b.set(bit);
        }
        ans.push_back({b.to_ullong(), tmp});
    }
    for(auto [d, tmp]:ans) {
        cout << d << ":";
        for(int x:tmp) cout << " " << x;
        cout << endl;
    }

    return 0;
}
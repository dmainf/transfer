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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int q;
    cin >> q;
    sort(all(a));
    vector<pi> ans;
    while(q--) {
        int k;
        cin >> k;
        ans.push_back({lower_bound(all(a), k)-a.begin(), upper_bound(all(a), k)-a.begin()});
    }
    for(auto [l, u]:ans) {
        cout << l << " " << u << endl;
    }

    return 0;
}
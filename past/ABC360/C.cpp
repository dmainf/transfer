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
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }
    vector<int> w(n);
    rep(i, n) cin >> w[i];
    vector<vector<pair<int, int>>> box(n);
    rep(i, n) box[a[i]].push_back({w[i], i});
    ll cost=0;
    rep(i, n) {
        if(box[i].empty()) continue;
        if(box[i].size()<=1) continue;
        sort(all(box[i]));
        while(box[i].size()>1) {
            cost+=box[i][0].first;
            box[i].erase(box[i].begin());
        }
    }
    cout << cost << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<int, vector<int>> bean;
    rep(i, n) {
        int a, c;
        cin >> a >> c;
        bean[c].push_back(a);
        sort(all(bean[c]));
    }
    int ans=0;
    for(auto p : bean) {
        ans = max(ans, p.second[0]);
    }
    cout << ans << endl;

    return 0;
}

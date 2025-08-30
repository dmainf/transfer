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
    vector<int> a(n);
    rep(i, n) cin>> a[i];
    vector<pair<int, int>> ans;
    int i=0;
    rep(i, n) {
        while(a[i]!=i+1) {
            int j=a[i]-1;
            ans.push_back({i+1, j+1});
            swap(a[i], a[j]);
        }
    }
    std::cout << ans.size() << std::endl;
    rep(i, ans.size()) std::cout << ans[i].first << " " << ans[i].second << std::endl;

    return 0;
}

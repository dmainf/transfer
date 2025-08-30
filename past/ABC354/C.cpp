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
    vector<int> a(n), c(n);
    rep(i, n) cin >> a[i] >> c[i];
    vector<int> is(n);
    rep(i, n) is[i]=i;
    sort(is.begin(), is.end(), [&](int i, int j) {
        return a[i] > a[j];
    });
    vector<int> ans;
    for(int i:is) {//aの降順にiが並んでる
        if(ans.size()==0 || c[ans.back()]>c[i]) {
            ans.push_back(i);
        }
    }
    sort(all(ans));
    cout << ans.size() << endl;
    rep(i, ans.size()) cout << ans[i]+1 << " \n"[i==ans.size()-1];

    return 0;
}

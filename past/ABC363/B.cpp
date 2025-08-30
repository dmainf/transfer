#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define nall(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t, p;
    cin >> n >> t >> p;
    vector<int> l(n);
    rep(i, n) cin >> l[i];
    set<int> now;
    int ans=0;
    while(now.size()<p) {
        rep(i, n)if(l[i]>=t) now.emplace(i);
        ans++;
        rep(i, n) l[i]++;
    }
    cout << ans-1 << endl;
    
    return 0;
}

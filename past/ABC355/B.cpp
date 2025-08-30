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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> c(n+m);//a==0 b==1
    rep(i, n) {
        int tmp; cin >> tmp;
        c[i]={tmp, 0};
    }
    for(int i=n; i<n+m; i++) {
        int tmp; cin >> tmp;
        c[i]={tmp, 1};
    }
    sort(all(c));
    rep(i, n+m-1) {
        if(c[i].second==0 && c[i+1].second==0) {
            Yes;
            return 0;
        }
    }
    No;

    return 0;
}

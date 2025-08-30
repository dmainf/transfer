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
    vector<int> l(n), r(n);
    rep(i, n) cin >> l[i] >> r[i];
    ll min=0, max=0;
    rep(i, n) {
        min+=l[i]; max+=r[i];
    }
    if(min<=0 && 0<=max) Yes;
    else {
        No;
        return 0;
    }
    min*=-1;
    rep(i, n) {
        if(min<=r[i]-l[i]) {
            l[i]+=min;
            rep(i, n) cout << l[i] << " \n"[i==n-1];
            return 0;
        }
        min-=r[i]-l[i];
        l[i]=r[i];
    }
    return 0;
}
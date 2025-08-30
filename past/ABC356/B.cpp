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
    vector<int> a(m);
    rep(i, m) cin >> a[i];
    vector<int> sum(m);
    rep(i, n)rep(j, m) {
        int x;
        cin >> x;
        sum[j]+=x;
    }
    bool flag=true;
    rep(i, m) if(sum[i]<a[i]) {
        flag=false;
    }
    if(flag) Yes;
    else No;

    return 0;
}
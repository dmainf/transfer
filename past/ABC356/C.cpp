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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> as(m);
    vector<char> r(m);
    rep(i, m) {
        int c;
        cin >> c;
        rep(j, c) {
            int a;
            cin >> a;
            a--;
            as[i] |= 1<<a;
        }
        cin >> r[i];
    }
    int ans=0;
    rep(x, 1<<n) {
        bool flag=true;
        rep(i, m) {
            int num=__builtin_popcount(as[i]&x);
            if((num>=k) != (r[i]=='o')) flag=false;
        }
        if(flag) ans++;
    }
    cout << ans << endl;

    return 0;
}
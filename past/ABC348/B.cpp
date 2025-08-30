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
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    rep(i, n) {
        int maxx=0;
        int maxxi;
        rep(j, n) {
            if(maxx<(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])) {
                maxx=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                maxxi=j;
            }
        }
        cout << maxxi+1 << endl;
    }

    return 0;
}

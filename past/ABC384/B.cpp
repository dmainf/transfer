#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r;
    int d[109], a[109];
    cin >> n >> r;
    rep(i, n) cin >> d[i] >> a[i];

    int tb=r, ta=0;
    rep(i, n) {
        if(d[i]==1) {
            if(1600<=tb && tb<=2799) {
                ta=tb+a[i];
                tb=ta;
            }
        } else {
            if(1200<=tb && tb<=2399) {
                ta=tb+a[i];
                tb=ta;
            }
        }
    }
    cout << tb << endl;
}
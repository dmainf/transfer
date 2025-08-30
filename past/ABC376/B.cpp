#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
int f(int n, int s, int g, int x) {
    if(s>g) swap(s, g);
    if(s<x && x<g) return  n-(g-s);
    return g-s;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    int ans=0;
    int l=0, r=1;
    rep(i, q) {
        char h;
        int t;
        cin >> h >> t;
        t--;
        if(h=='L') {
            ans+=f(n, l, t, r);
            l=t;
        }
        if(h=='R') {
            ans+=f(n, r, t, l);
            r=t;
        }
    }
    cout << ans << endl;
    return 0;
}

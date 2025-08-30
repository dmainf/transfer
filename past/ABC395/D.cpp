#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> rep(n+q+1), cnt(n+q+1, 0), p(n+1), pt(n+1), it(n+1);
    int used;
    rep.resize(n+q+1);
    cnt.resize(n+q+1, 0);
    for(int i=1; i<=n; i++){
        pt[i]=i;
        it[i]=i;
    }
    used=n;
    for(int i=1; i<=n; i++){
        rep[i]=i;
        cnt[i]=1;
        p[i]=i;
    }
    auto sn=[&](int a, int b) {
        int A=pt[a], B=pt[b];
        swap(it[A], it[B]);
        swap(pt[a], pt[b]);
    };
    auto mp=[&](int a, int b) {
        int k = p[a];
        if (cnt[k] == 1) {
            rep[k] = pt[b];
        } else {
            cnt[k]--;
            used++;
            cnt[used] = 1;
            rep[used] = pt[b];
            p[a] = used;
        }
    };
    auto qy=[&](int a) {
        int k = p[a];
        return it[rep[k]];
    };
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int a, b;
            cin >> a >> b;
            mp(a, b);
        } else if(t == 2){
            int a, b;
            cin >> a >> b;
            sn(a, b);
        } else {
            int a;
            cin >> a;
            cout << qy(a) << "\n";
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
int main(){//無理だった
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w, q;
    cin>> h >> w >> q;
    vector<set<int>> row(h);
    vector<set<int>> cul(w);
    rep(i, h) rep(j, w) {
        row[i].emplace(j);
        cul[j].emplace(i);
    }
    ll des=0;
    auto erase=[&](int i, int j) {
        row[i].erase(j);
        cul[j].erase(i);
    };
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        if(row[r].count(c) && cul[c].count(r)) {
            erase(r, c);
            des++;
            continue;
        }
        {
            auto it=row[r].lower_bound(c);
            if(it!=row[r].end()) erase(r, *it), des++;
            if(it!=row[r].begin()) {
                auto pre=prev(it);
                erase(r, *pre);
                des++;
            }
        }
        {
            auto it=cul[c].lower_bound(r);
            if(it!=cul[c].end()) erase(*it, c), des++;
            if(it!=cul[c].begin()) {
                auto pre=prev(it);
                erase(*pre, c);
                des++;
            }
        }
    }
    cout << h*w-des << endl;
    
    return 0;
}
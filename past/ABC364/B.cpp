#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    int si, sj;
    cin >> si >> sj;
    si--; sj--;
    vector<string> c(h);
    rep(i, h) cin >> c[i];
    string x;
    cin >> x;
    vector<int> dh = {0, 0, -1, 1}; 
    vector<int> dw = {-1, 1, 0, 0}; 
    pair<int, int> p = {si, sj};
    rep(i, x.size()) {
        int ni = p.first, nj = p.second;
        if (x[i] == 'L') { ni += dh[0]; nj += dw[0]; }
        if (x[i] == 'R') { ni += dh[1]; nj += dw[1]; }
        if (x[i] == 'U') { ni += dh[2]; nj += dw[2]; }
        if (x[i] == 'D') { ni += dh[3]; nj += dw[3]; }

        if (ni >= 0 && ni < h && nj >= 0 && nj < w && c[ni][nj] == '.') {
            p.first = ni;
            p.second = nj;
        }
    }
    cout << p.first + 1 << " " << p.second + 1 << endl;
    
    return 0;
}
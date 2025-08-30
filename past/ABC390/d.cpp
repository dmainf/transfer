#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X;
    cin >> N >> X;

    // ビタミンごとに食品を3つのベクタに分ける
    vector<pair<int,int>> g1, g2, g3;

    // 入力を振り分け
    for(int i = 0; i < N; i++){
        int v, a, c;
        cin >> v >> a >> c;  // v=ビタミン種類(1/2/3), a=ビタミン量, c=カロリー
        if(v == 1) {
            g1.push_back(make_pair(a, c));
        } else if(v == 2) {
            g2.push_back(make_pair(a, c));
        } else {
            g3.push_back(make_pair(a, c));
        }
    }

    // dp1[c]: カロリー c 以下で得られるビタミン1の最大量
    vector<int> dp1(X + 1, 0);
    for(int i = 0; i < (int)g1.size(); i++){
        int a    = g1[i].first;   // ビタミン量
        int cost = g1[i].second; // カロリー
        // ナップサック典型: 大きい c からループ
        for(int c = X; c >= cost; c--){
            dp1[c] = max(dp1[c], dp1[c - cost] + a);
        }
    }
    // 「c以下で利用できる最大値」にするための累積最大
    for(int c = 1; c <= X; c++){
        dp1[c] = max(dp1[c], dp1[c - 1]);
    }

    // dp2[c]: カロリー c 以下で得られるビタミン2の最大量
    vector<int> dp2(X + 1, 0);
    for(int i = 0; i < (int)g2.size(); i++){
        int a    = g2[i].first;
        int cost = g2[i].second;
        for(int c = X; c >= cost; c--){
            dp2[c] = max(dp2[c], dp2[c - cost] + a);
        }
    }
    for(int c = 1; c <= X; c++){
        dp2[c] = max(dp2[c], dp2[c - 1]);
    }

    // dp3[c]: カロリー c 以下で得られるビタミン3の最大量
    vector<int> dp3(X + 1, 0);
    for(int i = 0; i < (int)g3.size(); i++){
        int a    = g3[i].first;
        int cost = g3[i].second;
        for(int c = X; c >= cost; c--){
            dp3[c] = max(dp3[c], dp3[c - cost] + a);
        }
    }
    for(int c = 1; c <= X; c++){
        dp3[c] = max(dp3[c], dp3[c - 1]);
    }

    // (c1, c2, c3) を割り当てるときの「ビタミン1,2,3の最小値」を最大化
    int ans = 0;
    for(int c1 = 0; c1 <= X; c1++){
        for(int c2 = 0; c2 + c1 <= X; c2++){
            int c3 = X - (c1 + c2);
            int v1 = dp1[c1];
            int v2 = dp2[c2];
            int v3 = dp3[c3];
            int m  = min(v1, min(v2, v3));
            ans = max(ans, m);
        }
    }

    cout << ans << "\n";
    return 0;
}

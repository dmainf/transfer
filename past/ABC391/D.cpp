#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, w;
    cin >> n >> w;
    vector<int> x(n), y(n);
    vector<vector<pair<int,int>>> cols(w+1);
    for (int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        cols[x[i]].push_back({y[i], i});
    }
    vector<int> block(n, 0);
    vector<int> count(w+1, 0);
    for (int c = 1; c <= w; c++){
        sort(cols[c].begin(), cols[c].end(), [](auto &a, auto &b){
            return a.first < b.first;
        });
        count[c] = cols[c].size();
        for (int i = 0; i < (int)cols[c].size(); i++){
            int bid = cols[c][i].second;
            block[bid] = i+1;
        }
    }
    int m = INT_MAX;
    for (int c = 1; c <= w; c++){
        m = min(m, (int)count[c]);
    }
    if(m == INT_MAX) m = 0;
    vector<int> D_arr(m+1, 0);
    D_arr[0] = 0;
    for (int r = 1; r <= m; r++){
        int curMax = 0;
        for (int c = 1; c <= w; c++){
            if(count[c] >= r){
                int y_val = cols[c][r-1].first;
                curMax = max(curMax, y_val);
            }
        }
        D_arr[r] = curMax;
    }
    vector<pair<int,int>> cand;
    for (int r = 1; r <= m; r++){
        cand.push_back({D_arr[r], r});
    }
    sort(cand.begin(), cand.end(), [](const pair<int,int> &a, const pair<int,int> &b){
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });
    int sz = cand.size();
    vector<int> prefixMax(sz, 0);
    for (int i = 0; i < sz; i++){
        if(i == 0)
            prefixMax[i] = cand[i].second;
        else
            prefixMax[i] = max(prefixMax[i-1], cand[i].second);
    }
    int Q;
    cin >> Q;
    for (int qi = 0; qi < Q; qi++){
        int T, A;
        cin >> T >> A;
        A--;
        int r_A = block[A];
        int d = 0;
        if(m > 0){
            auto it = upper_bound(cand.begin(), cand.end(), make_pair(T, INT_MAX));
            if(it == cand.begin()){
                d = 0;
            } else {
                int pos = it - cand.begin() - 1;
                d = prefixMax[pos];
            }
        }
        cout << ( (r_A > d) ? "Yes" : "No" ) << "\n";
    }
 
    return 0;
}

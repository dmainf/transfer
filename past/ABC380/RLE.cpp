#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
using ll=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<pair<char, int>> rle;
    for(char c:s) {
        if(rle.size() && rle.back().first==c) {
            rle.back().second++;
        } else {
            rle.push_back({c, 1});
        }
    }
    int one=0;
    rep(i, rle.size()) {
        if(rle[i].first=='1') {
            one++;
            if(one==k) {
                swap(rle[i], rle[i-1]);
            }
        }
    }
    rep(i, rle.size()) {
        rep(j, rle[i].second) {
            cout << rle[i].first;
        }
    }
    cout << endl;

	return 0;
}
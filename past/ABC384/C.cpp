#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
int main() {
    int n=5;
    vector<int> a(5);
    vector<pair<int, string>> ranking;
    rep(i, n) cin >> a[i];
    for(int s=1; s<32; s++) {
        string name; int score=0;
        rep(i, n) {
            if((s>>i)&1) {
                score += a[i];
                name += 'A' + i;
            }
        }
        ranking.emplace_back(-score, name);
    }
    sort(ranking.begin(), ranking.end());
    for(auto [score, name] : ranking) {
        cout << name << endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n=5;
    vector<int> a(5);
    vector<pair<int, string>> ranking;
    for(int i=0; i<5; i++) cin >> a[i];
    for(int i=1; i<32; i++) {
        int score=0; string name;
        for(int b=0; b<n; b++) {
            if((i>>b)&1) {
                score+=a[b];
                name += 'A'+b;
            }
        }
        ranking.emplace_back(-score, name);
    }
    sort(ranking.begin(), ranking.end());
    for(auto [score, name] : ranking) {
        cout << name << endl;
    }
}
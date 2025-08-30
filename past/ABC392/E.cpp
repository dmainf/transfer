#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<set<int>> groups;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        bool merged = false;
        for (int j = 0; j < groups.size(); j++){
            if (groups[j].count(a) || groups[j].count(b)) {
                groups[j].insert(a);
                groups[j].insert(b);
                merged = true;
                break;
            }
        }
        if (!merged) {
            set<int> newGroup;
            newGroup.insert(a);
            newGroup.insert(b);
            groups.push_back(newGroup);
        }
    }
    cout << groups.size() - 1 << endl;
    return 0;
}

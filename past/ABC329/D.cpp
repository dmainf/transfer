#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>; 
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<set<int>> score(m+1);
    rep(i, n) score[0].insert(i);
    vector<int> human(n, 0);
    int mx=0;
    vector<int> ans;
    rep(i, m) {
        int a;
        cin >> a;
        a--;
        score[human[a]].erase(a);
        human[a]++;
        score[human[a]].insert(a);
        mx=max(mx, human[a]);
        ans.push_back(*score[mx].begin()+1);
    }
    for(auto x:ans) cout << x << endl;

    return 0;
}

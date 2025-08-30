#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;
using ll=long long;
using pi=pair<int, int>;
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> score(n, 0);
    rep(i, n) {
        string s;
        cin >> s;
        rep(j, s.size()) {
            if(s[j]=='o') score[i]++;
        }
    }
    vector<set<int>> mp(1e6);
    rep(i, n) mp[score[i]].insert(i+1);
    for(int i=1e6; i>=0; i--) if(!mp[i].empty()) {
        for(auto x:mp[i]) cout << x << " ";
    }
    cout << endl;

    return 0;
}
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
    int n;
    cin >> n;
    vector<pair<int, string>> ss;
    rep(i, n) {
        string s;
        cin >> s;
        ss.push_back({s.size(), s});
    }
    sort(all(ss));
    string sss="";
    rep(i, n) sss+=ss[i].second;
    cout << sss << endl;

    return 0;
}
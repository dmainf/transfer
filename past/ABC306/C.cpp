#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> idx(n+1);
    rep(i, 3*n) {
        int a;
        cin >> a;
        idx[a].push_back(i);
    }
    vector<pi> num;
    //{idx, num}
    rep(i, n) {
        num.push_back({idx[i+1][1], i+1});
    }
    sort(all(num));
    for(auto [z, x]:num) cout << x << " ";
    cout << endl;

    return 0;
}
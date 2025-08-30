#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl;
#define NO cout<<"No"<<endl;
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll k;
    cin >> n >> k;
    vector<vector<int>> G(n);
    rep(i, n) rep(j, n) {
        int a;
        cin >> a;
        if(a) G[i].push_back(j);
    }
    vector<vector<mint>> dp(n, vector<mint>(n, 0));
    queue<int> que;
    que.push(0);
    while(true) {
        int v=que.front();
        que.pop();
        for(int nv:G[v]) {
            
        }
    }

    return 0;
}
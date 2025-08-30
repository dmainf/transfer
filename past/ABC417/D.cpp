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
struct Present {
    int p, a, b;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Present> presents(n);
    rep(i, n) {
        int p, a, b;
        cin >> p >> a >> b;
        presents[i] = {p, a, b};
    }
    const int MAX=500;
    vector<ll> suff(n+1, 0);
    rep(i, n) suff[i+1]=suff[i]+presents[i].b;
    vector<vector<ll>> dp(n+1, vector<ll>(MAX+1));
    rep(x, MAX+1) dp[n][x]=x;
    for(int i=n-1; i>=0; i--) {
        auto [p, a, b]=presents[i];
        rep(x, MAX+1) {
            ll nxt;
            if(x<=p) nxt=(ll)x+a;
            else nxt=max(0, x-b);

            if(nxt<=MAX) dp[i][x]=dp[i+1][nxt];
            else {
                ll tmp=nxt-MAX;
                int it=lower_bound(suff.begin()+i+2, suff.end(), tmp+suff[i+1])-suff.begin();
                if(it>n) dp[i][x]=nxt-(suff[n]-suff[i+1]);
                else {
                    ll tmp=nxt-(suff[it]-suff[i+1]);
                    dp[i][x]=dp[it][tmp];
                }
            }
        }
    }
    int q;
    cin >> q;
    vector<ll> ans;
    while (q--) {
        ll x;
        cin >> x;
        if(x<=MAX) ans.push_back(dp[0][x]);
        else {
            ll tmp=x-MAX;
            int it=lower_bound(suff.begin()+1, suff.end(), tmp)-suff.begin();
            if(it>n) ans.push_back(x-suff[n]);
            else ans.push_back(dp[it][x-suff[it]]);
        }
    }
    for(ll x:ans) cout << x << endl;

    return 0;
}
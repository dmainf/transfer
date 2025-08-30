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
    ll n;
    cin >> n;
    unordered_map<ll, ll> memo;
    function<ll(ll)> f=[&](ll x) -> ll {
        if(x<2) return 0;
        if(memo.count(x)) return memo[x];
        if(x%2==0) memo[x]=x+f(x/2)+f(x/2);
        else memo[x]=x+f(x/2)+f(x/2+1);
        return memo[x];
    };
    memo[0]=0;
    memo[1]=0;
    cout << f(n) << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const ll INF=1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    ll ans=INF;
    //a<=b
    //a<=[m/a]+1
    //a*a-a<m
    for(ll a=1; a*a-a<m; a++) {
        ll b=(m+a-1)/a;
        if(a<=n && b<=n) ans=min(ans, a*b);
    }
    cout << (ans==INF ? -1:ans) << endl;

    return 0;
}
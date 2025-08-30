#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<ll,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, L, K;
    cin >> n >> L >> K;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> yokan;
    ll pre=0;
    rep(i, n) {
        yokan.push_back(a[i]-pre);
        pre=a[i];
    }
    yokan.push_back(L-pre);
    auto f=[&](ll mid) -> bool {
        ll tmp=0;
        int cnt=0;
        for(ll x:yokan) {
            if(tmp+x<mid) {
                tmp+=x;
            } else {
                cnt++;
                tmp=0;
            }
        }
        return (cnt<K+1);
    };
    ll l=0, r=L;
    while(l<=r) {
        ll mid=(l+r)/2;
        if(f(mid)) r=mid-1;
        else l=mid+1;
    }
    cout << r << endl;

    return 0;
}
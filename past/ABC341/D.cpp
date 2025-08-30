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
long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}
long long lcm(long long a, long long b) {
    long long d = gcd(a, b);
    return a / d * b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    ll k;
    cin >> n >> m >> k;
    ll LCM=lcm(n, m);
    auto f=[&](ll x) {
        return x/n+x/m-2*(x/LCM)<k;
    };
    ll low=1, high=1e18;
    while(low<=high) {
        ll mid=(low+high)/2;
        if(f(mid)) low=mid+1;
        else high=mid-1;
    }
    cout << low << endl;

    return 0;
}

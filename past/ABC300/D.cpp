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
const int MAX=1e6;
struct Sieve {
    int n;
    vector<int> f, primes;
    Sieve(int n=1):n(n), f(n+1) {
        f[0] = f[1] = -1;
        for (ll i = 2; i <= n; ++i) {
            if (f[i]) continue;
            primes.push_back(i);
            f[i] = i;
            for (ll j = i*i; j <= n; j += i) {
                if (!f[j]) f[j] = i;
            }
        }
    }
    bool isPrime(int x) { return f[x] == x;} 
    vector<int> factorList(int x) {
        vector<int> res;
        while (x != 1) {
            res.push_back(f[x]);
            x /= f[x];
        }
        return res;
    }
    vector<pair<int, int>> factor(int x) {
        vector<int> fl = factorList(x);
        if (fl.size() == 0) return {};
        vector<pair<int, int>> res(1, std::pair<int, int>(fl[0], 0));
        for (int era : fl) {
            if (res.back().first == era) {
                res.back().second++;
            } else {
                res.emplace_back(era, 1);
            }
        }
        return res;
    }
    vector<pair<ll,int>> factor(ll x) {
        vector<pair<ll,int>> res;
        for (int era : primes) {
            int y = 0;
            while (x%era == 0) x /= era, ++y;
            if (y != 0) res.emplace_back(era,y);
        }
        if (x != 1) res.emplace_back(x,1);
        return res;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    Sieve era(MAX);
    vector<int> s(MAX+1, 0);
    for(int x:era.primes) s[x]=1;
    rep(i, MAX) s[i+1]+=s[i];
    int ans=0;
    int SIZE=era.primes.size();
    rep(ai, SIZE) {
        ll a=era.primes[ai];
        if(a*a*a*a*a>n) break;
        for(int bi=ai+1; bi<SIZE; bi++) {
            ll b=era.primes[bi];
            if(a*a*b*b*b>n) break;
            ll r=n/a/a/b;
            ll cM=sqrt(r);
            ans+=s[cM]-s[b];
        }
    }
    cout << ans << endl;

    return 0;
}
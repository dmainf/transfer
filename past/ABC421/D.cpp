#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<ll,ll>;
//const int di[]={+1,-1,+0,+0};
//const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int takai, takaj, aokii, aokij; cin >> takai >> takaj >> aokii >> aokij;
    ll n, m, l; cin >> n >> m >> l;
    vector<pair<char, ll>> s(m), t(l);
    rep(i, m) {
        char op; ll a; cin >> op >> a;
        s[i]={op, a};
    }
    rep(i, l) {
        char op; ll b; cin >> op >> b;
        t[i]={op, b};
    }

    auto dir=[&](char c) -> pi {
        if(c=='U') return {-1,0};
        if(c=='D') return {+1,0};
        if(c=='L') return {0,-1};
        if(c=='R') return {0,+1};
        return {-1, -1};
    };
    ll di=takai-aokii, dj=takaj-aokij;
    int si=0, ti=0;
    //count of a RLE block
    ll scnt=0, tcnt=0;
    ll ans=0;
    while(si<m && ti<l) {
        auto [sdir, slen]=s[si]; auto [tdir, tlen]=t[ti];
        ll len=min(slen-scnt, tlen-tcnt);
        auto [sidir, sjdir]=dir(sdir); auto [tidir, tjdir]=dir(tdir);
        ll vi=sidir-tidir; ll vj=sjdir-tjdir;
        if(vi==0 && vj==0) {
            // same direction
            if(di==0 && dj==0) ans+=len;
        } else if(vi!=0 && vj!=0) {
            if((-di)%vi==0 && (-dj)%vj==0) {
                ll t1=(-di)/vi, t2=(-dj)/vj;
                if(t1==t2 && 1<=t1 && t1<=len) ans++;
            }
        } else if(vi!=0) {
            // di+vi*t==0 → t=-di/vi
            if((-di)%vi==0) {
                ll t=(-di)/vi;
                if(dj+vj*t==0 && 1<=t && t<=len) ans++;
            }
        } else if(vj!=0) {
            // dj+vj*t==0 → t=-dj/vj
            if((-dj)%vj==0) {
                ll t=(-dj)/vj;
                if(di+vi*t==0 && 1<=t && t<=len) ans++;
            }
        }
        di+=vi*len; dj+=vj*len;
        scnt+=len; tcnt+=len;
        if(scnt==slen) { si++; scnt=0; };
        if(tcnt==tlen) { ti++; tcnt=0; };
    }
    cout << ans << endl;

    return 0;
}
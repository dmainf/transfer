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
    string s;
    cin >> s;
    ll n;
    cin >> n;
    ll ans=0;
    int M=s.size();
    reverse(all(s));
    rep(i, M) if(s[i]=='1') {
        ans+=1LL<<i;
    }
    if(n<ans) {
        cout << -1 << endl;
        return 0;
    }
    for(int bit=M; bit>=0; bit--) {
        if(s[bit]!='?') continue;
        ll tmp=(1LL<<bit);
        if(ans+tmp<=n) ans+=tmp;
    }
    cout << ans << endl;

    return 0;
}
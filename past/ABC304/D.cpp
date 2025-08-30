using namespace std;
#include <bits/stdc++.h>
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
    int w, h, n;
    cin >> w >> h >> n;
    vector<int> p(n), q(n);
    rep(i, n) cin >> p[i] >> q[i];
    int A, B;
    cin >> A;
    vector<int> a(A);
    rep(i, A) cin >> a[i];
    cin >> B;
    vector<int> b(B);
    rep(i, B) cin >> b[i];
    map<pi, int> mp;
    rep(i, n) {
        int x=lower_bound(all(a), p[i])-a.begin();
        int y=lower_bound(all(b), q[i])-b.begin();
        mp[{x, y}]++;
    }
    int m=INF, M=0;
    for(auto [z, x]:mp) {
        m=min(m, x);
        M=max(M, x);
    } 
    if(mp.size()<(A+1)*(B+1)) m=0;
    printf("%d %d\n", m, M);

    return 0;
}
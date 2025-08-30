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
    int n, m;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    cin >> m;
    vector<int> b(m);
    rep(i, m) cin >> b[i];
    int x;
    cin >> x;
    sort(all(b));
    vector<bool> kaidan(x+1, false);
    kaidan[0]=true;
    rep(v, x) {
        rep(i, n) {
            if(kaidan[v]) {
                int nv=v+a[i];
                if(x<nv) continue;
                if(binary_search(all(b), nv)) continue;
                kaidan[nv]=true;
            }
        }
    }
    if(kaidan[x]) YES;
    else NO;

    return 0;
}
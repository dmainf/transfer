#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl;
#define NO cout<<"No"<<endl;
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    vector<vector<ll>> a(h, vector<ll>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];
    //0     0000
    //7     0111
    //10    1010
    //2     0010
    //score 1111
    vector<vector<bool>> b(h, vector<bool>(w, false));
    ll ans=0;
    auto f=[&](auto f, vector<vector<bool>> b, int i, int j) {
        if(j==w) { i++; j=0; }
        if(i==h) {
            ll tmp=0;
            rep(k, h) rep(l, w) {
                if(!b[k][l]) tmp^=a[k][l];
            }
            ans=max(ans, tmp);
            return;
        }
        if(b[i][j]) {
            f(f, b, i, j+1);
        } else {
            //okanai
            f(f, b, i, j+1);
            //tate
            if(i+1<h && !b[i+1][j]) {
                b[i][j]=b[i+1][j]=true;
                f(f, b, i, j+1);
                b[i][j]=b[i+1][j]=false;
            }
            //yoko
            if(j+1<w && !b[i][j+1]) {
                b[i][j]=b[i][j+1]=true;
                f(f, b, i, j+1);
                b[i][j]=b[i][j+1]=false;
            }
        }
    };
    f(f, b, 0, 0);
    cout << ans << endl;

    return 0;
}
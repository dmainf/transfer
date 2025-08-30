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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    string s;
    cin >> s;
    vector<vector<int>> cnt_l(n+1, vector<int>(3, 0));
    vector<vector<int>> cnt_r(n+1, vector<int>(3, 0));
    rep(i, n) {
        cnt_l[i+1]=cnt_l[i];
        if(s[i]=='M') cnt_l[i+1][a[i]]++;
    }
    for(int i=n-1; i>=0; i--) {
        cnt_r[i]=cnt_r[i+1];
        if(s[i]=='X') cnt_r[i][a[i]]++;
    }
    ll ans=0;
    auto mex=[&](int a, int b, int c) {
        rep(x, 3) if(a!=x && b!=x && c!=x) {
            return x;
        }
        return 3;
    };
    rep(j, n) if(s[j]=='E') {
        rep(i, 3) rep(k, 3) {
            ans+=(ll)cnt_l[j][i]*cnt_r[j+1][k]*mex(i, a[j], k);
        }
    }
    cout << ans << endl;

    return 0;
}
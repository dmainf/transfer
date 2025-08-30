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
    int n; cin >> n;
    vector<pi> student(n);
    rep(i, n) {
        int c, p; cin >> c >> p;
        student[i]={c, p};
    }
    vector<ll> pre1(n+1, 0), pre2(n+1, 0);
    rep(i, n) {
        pre1[i+1]=pre1[i];
        pre2[i+1]=pre2[i];
        auto [c, score]=student[i];
        if(c==1) pre1[i+1]+=score;
        if(c==2) pre2[i+1]+=score;
    }
    int q; cin >> q;
    vector<pi> ans;
    while(q--) {
        int l ,r; cin >> l >> r;
        ll tmp1, tmp2;
        tmp1=pre1[r]-pre1[l-1];
        tmp2=pre2[r]-pre2[l-1];
        ans.push_back({tmp1, tmp2});
    }
    for(auto [x, y]:ans) cout << x << " " << y << endl;

    return 0;
}
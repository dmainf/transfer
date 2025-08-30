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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    int left=INF, right=-INF;
    int top=INF, bottom=-INF;
    rep(i, h) rep(j, w) if(s[i][j]=='#') {
        left=min(left, j);
        right=max(right, j);
        top=min(top, i);
        bottom=max(bottom, i);
    }
    pi ans;
    for(int i=top; i<=bottom; i++) {
        for(int j=left; j<=right; j++) {
            if(s[i][j]=='.') ans={i, j};
        }
    }
    cout << ans.first+1 << " " << ans.second+1 << endl;

    return 0;
}
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
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    vector<pi> ans;
    rep(si, n) rep(sj, m) if(si+9<=n && sj<=m) {
        bool flag=true;
        //left-top
        for(int i=si; i<si+3; i++) {
            for(int j=sj; j<sj+3; j++) {
                if(s[i][j]!='#') flag=false;
                break;
            }
        }
        //right-down
        for(int i=si+6; i<si+9; i++) {
            for(int j=sj+6; j<sj+9; j++) {
                if(s[i][j]!='#') flag=false;
                break;
            }
        }
        //left-top
        for(int i=si; i<si+4; i++) {
            if(i!=si+3) {
                if(s[i][sj+3]!='.') flag=false;
            } else {
                for(int j=sj; j<sj+4; j++) {
                    if(s[i][j]!='.') flag=false;
                }
            }
        }
        //right-down
        for(int i=si+5; i<si+9; i++) {
            if(i!=si+5) {
                if(s[i][sj+5]!='.') flag=false;
            } else {
                for(int j=sj+5; j<sj+9; j++) {
                    if(s[i][j]!='.') flag=false;
                }
            }
        }
        if(flag) ans.push_back({si, sj});
    }
    if(ans.size()) {
        for(auto [i, j]:ans) {
            cout << i+1 << " " << j+1 << endl;
        }
    } else {
        cout << endl;
    }

    return 0;
}
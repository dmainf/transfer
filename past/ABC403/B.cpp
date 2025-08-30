#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string t, u;
    cin >> t;
    cin >> u;
    rep(offset, t.size()) {
        bool flag=true;
        rep(i, u.size()) {
            if(!(t[offset+i]=='?' || t[offset+i]==u[i])) flag=false;
        }
        if(flag) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}
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
    string s, t;
    cin >> s >> t;
    vector<int> flip(n+1, 0);
    //区間XOR
    rep(i, m) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        flip[l]^=1;
        if(r+1<n) flip[r+1]^=1;
    }
    int f=0;
    rep(i, n) {
        f^=flip[i];
        if(f) swap(s[i], t[i]);
    }
    cout << s << endl;

    return 0;
}
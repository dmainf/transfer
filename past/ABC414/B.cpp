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
    vector<pair<char, ll>> p;
    rep(i, n) {
        char c;
        ll l;
        cin >> c >> l;
        p.push_back({c, l});
    }
    string s;
    rep(i, n) {
        auto [c, l]=p[i];
        if(100<s.size()+l) {
            cout << "Too Long" << endl;
            return 0;
        }
        rep(j, l) s+=c;
    }
    cout << s << endl;

    return 0;
}
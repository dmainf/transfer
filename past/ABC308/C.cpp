#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using ld=long double;
using pi=pair<int,int>;
using pd=pair<ld, int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pd> p(n);
    rep(i, n) {
        ld a, b;
        cin >> a >> b;
        ld tmp=a/(a+b);
        p[i]={tmp, i+1};
    }
    map<ld, vector<ld>, greater<ld>> mp;
    for(auto [pro, idx]:p) mp[pro].push_back(idx);
    for(auto [pro, idx]:mp) {
        sort(all(idx));
        for(int x:idx) cout << x << " ";
    }
    cout << endl;

    return 0;
}
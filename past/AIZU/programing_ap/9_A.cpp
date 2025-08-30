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
    set<int> a, b;
    rep(i, n) {
        int tmp;
        cin >> tmp;
        a.insert(tmp);
    }
    cin >> m;
    rep(i, m) {
        int tmp;
        cin >> tmp;
        b.insert(tmp);
    }
    vector<int> c;
    set_union(all(a), all(b), back_inserter(c));
    for(int x:c) cout << x << endl;

    return 0;
}
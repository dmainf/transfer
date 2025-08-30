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
    sort(all(a));
    int q; cin >> q;
    vector<int> ans;
    while(q--) {
        int b; cin >> b;
        int it=lower_bound(all(a), b)-a.begin();
        if(0<it) ans.push_back(min(abs(b-a[it]), abs(b-a[it-1])));
        else ans.push_back(abs(b-a[it]));
    }
    for(int x:ans) cout << x << endl;

    return 0;
}
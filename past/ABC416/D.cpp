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
    int t; cin >> t;
    vector<ll> ans;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(n);
        rep(i, n) { cin >> a[i]; a[i]%=m; }
        rep(i, n) { cin >> b[i]; b[i]%=m; }
        //3 6
        //1 3 4
        //0 1 2

        //1 4 0
        //5
        sort(all(a));
        sort(all(b));
        multiset<int> mst(all(a));
        ll tmp=0;
        rep(i, n) {
            int need=(m-b[i])%m;
            auto it=mst.lower_bound(need);
            int val;
            if(it==mst.end()) {
                val=*mst.begin();
                mst.erase(mst.begin());
            } else {
                val=*it;
                mst.erase(it);
            }
            tmp+=(val+b[i])%m;
        }
        ans.push_back(tmp);
    }
    for(ll x:ans) cout << x << endl;

    return 0;
}
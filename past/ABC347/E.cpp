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
    int n, q;
    cin >> n >> q;
    set<int> st;
    vector<pi> p(q);
    //plus[i]:i回目の操作で加算する数
    vector<int> plus(q);
    rep(i, q) {
        int x;
        cin >> x;
        if(st.count(x)) {
            st.erase(x);
            p[i]={x, -1};
        } else {
            st.insert(x);
            p[i]={x, +1};
        }
        plus[i]=st.size();
    }
    vector<ll> pre(q+1, 0);
    rep(i, q) pre[i+1]=pre[i]+(ll)plus[i];
    //last[i]：iが最後に入った時刻
    vector<int> last(n+1, -1);
    //inter[x]：xの区間[l, r)のリスト
    //l:追加されたクエリ番号
    //r:削除されたクエリ番号
    vector<vector<pi>> inter(n+1);
    for(int t=1; t<=q; t++) {
        auto [x, op]=p[t-1];
        if(op==+1) last[x]=t;
        if(op==-1) {
            inter[x].push_back({last[x], t});
            last[x]=-1;
        }
    }
    for(int x=1; x<=n; x++) if(last[x]!=-1) {
        inter[x].push_back({last[x], q+1});
    }
    vector<ll> a(n+1, 0);
    for(int i=1; i<=n; i++) {
        for(auto [l, r]:inter[i]) { //neary O(1)
            a[i]+=pre[r-1]-pre[l-1];
        }
    }
    rep(i, n+1) if(i!=0) {
        cout << a[i] << (i==n ? "\n" : " ");
    }

    return 0;
}
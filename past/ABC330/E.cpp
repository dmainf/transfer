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
const int MAX=4e5;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n), cnt(MAX, 0);
    rep(i, n) {
        cin >> a[i];
        if(a[i]<MAX) cnt[a[i]]++;
    }
    set<int> st;
    rep(i, MAX) if(cnt[i]==0) {
        st.insert(i);
    }
    vector<int> ans;
    rep(qi, q) {
        int i, x;
        cin >> i >> x;
        i--;
        if(a[i]<MAX) {
            cnt[a[i]]--;
            if(cnt[a[i]]==0) st.insert(a[i]);
        }
        a[i]=x;
        if(a[i]<MAX) {
            if(cnt[a[i]]==0) st.erase(a[i]);
            cnt[a[i]]++;
        }
        ans.push_back(*st.begin());
    }
    for(auto x:ans) cout << x << endl;

    return 0;
}
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
struct NUM {
    int val;
    int cnt;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    //1 2 2 2 3 4 6 6 10 10
    //1       2 1 1 1
    if(d==0) {
        set<int> st;
        rep(i, n) st.insert(a[i]);
        cout << n-st.size() << endl;
        return 0;
    }
    map<int, vector<int>> mp;
    rep(i, n) mp[a[i]%d].push_back(a[i]);
    int keep=0;
    for(auto& [z, vec]:mp) {
        //vec：余りが同じ数の集合
        sort(all(vec));
        vector<NUM> p;
        for(auto x:vec) {
            if(p.empty() || p.back().val!=x) {
                p.push_back({x, 1});
            } else p.back().cnt++;
        }
        vector<int> dp(p.size(), 0);
        //dp[i]：iまで最高値
        rep(i, p.size()) {
            if(i==0) dp[0]=p[0].cnt;
            else {
                //衝突する＝どっちかしかとれない
                //sortしてあるから隣と比べるだけでいい
                if(p[i].val-p[i-1].val==d) {
                    int take=p[i].cnt+(i>=2 ? dp[i-2]:0);
                    dp[i]=max(dp[i-1], take);
                } else dp[i]=dp[i-1]+p[i].cnt;
            }
        }
        //余りが同じ集合ごとの残せる最大を足す
        keep+=dp[p.size()-1];
    }
    //要素数-残せる個数=消す個数
    cout << n-keep << endl;

    return 0;
}
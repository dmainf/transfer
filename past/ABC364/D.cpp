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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    vector<int> ans;
    rep(qi, q) {
        int b, k;
        cin >> b >> k;
        auto f=[&](int wj) -> bool {
            int l=b-wj;
            int r=b+wj;
            int li=lower_bound(all(a), l)-a.begin();
            int ri=upper_bound(all(a), r)-a.begin();
            return ri-li>=k;
        };
        int wa=-1, ac=2e8;
        while(wa+1<ac) {
            int wj=(wa+ac)/2;
            if(f(wj)) ac=wj;
            else wa=wj;
        }
        ans.push_back(ac);
    }
    for(auto answer:ans) cout << answer << endl;

    return 0;
}
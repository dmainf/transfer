#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pl=pair<int,ll>;
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
    vector<int> s(n, 0);
    for(int i=1; i<n; i++) {
        s[i]=s[i-1];
        if(i%2==0) s[i]+=a[i]-a[i-1];
    }
    auto f=[&](int x) {
        int idx=upper_bound(all(a), x)-a.begin();
        idx--;
        if(idx<0) return 0;
        int res=s[idx];
        if(idx%2==1) res+=x-a[idx];
        return res;
    };
    vector<int> ans;
    int q;
    cin >> q;
    while(q--) {
        int l ,r;
        cin >> l >> r;
        int tmp=f(r)-f(l);
        ans.push_back(tmp);
    }
    for(int x:ans) cout << x << endl;

    return 0;
}
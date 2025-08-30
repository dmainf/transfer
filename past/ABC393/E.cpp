#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int tmp=0;
    rep(i, n) {
        cin >> a[i];
        tmp=max(tmp, a[i]);
    }
    const int MA=tmp;
    vector<int> m(MA, 0);
    rep(i, n) m[a[i]]++;
    vector<int> cnt(MA, 0);
    for(int i=1; i<=MA; i++) {
        for(int j=i; j<=MA; j+=i) {
            cnt[i]+=m[j];//iの倍数と一致するm
        }
    }
    vector<int> ans(MA, 0);
    for(int i=1; i<=MA; i++) {
        if(cnt[i]<k) continue;
        for(int j=i; j<=MA; j+=i) {
            ans[j]=max(ans[j], i);
        }
    }
    rep(i, n) cout << ans[a[i]] << endl;

    return 0;
}
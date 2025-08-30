#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define nsort(a) sort(a.begin(), a.end())
#define rsort(a) sort(a.rbegin(), a.rend())
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> maxl(m+1, -1);
    rep(i, n) {
        int l, r;
        cin >> l >> r;
        maxl[r]=max(maxl[r], l);
    }
    long long ans=0;
    int l=1;
    for(int r=1; r<=m; r++) {
        cout << "r:" << r << " maxl[r]:" << maxl[r] << endl;
        while(l<=maxl[r]) l++;//=で回避
        ans+=r-l+1;
    }
    cout << ans << endl;

    return 0;
}

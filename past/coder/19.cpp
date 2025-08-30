#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int d, n, m;
    cin >> d >> n >> m;
    vector<int> shop(n+1, 0);
    for(int i=1; i<n; i++) cin >> shop[i];
    shop[n]=d;
    sort(all(shop));
    long long ans=0;
    rep(i, m) {
        int k;
        cin >> k;
        auto it=lower_bound(all(shop), k)-shop.begin();
        int tmp=abs(shop[it]-k);
        if(it>0) tmp=min(tmp, abs(shop[it-1]-k));
        ans+=tmp;
    }
    cout << ans << endl;

    return 0;
}

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
    int n;
    cin >> n;
    int atama=0;
    int atamai;
    long long ans=0;
    vector<int> a(n), b(n);
    rep(i, n) {
        cin >> a[i] >> b[i];
        if(atama<b[i]-a[i]) {
            atama=b[i]-a[i];
            atamai=i;
        }
    }
    rep(i, n) {
        if(atamai==i) {
            ans+=b[atamai];
            continue;
        }
        ans+=a[i];
    }
    cout << ans << endl;

    return 0;
}

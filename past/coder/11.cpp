#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define drep(i, n) for(int i=(n)-1;i>=0;i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(m);
    rep(i, m) {
        int k;
        cin >> k;
        rep(j, k) {
            int tmp;
            cin >> tmp;
            tmp--;
            s[i].push_back(tmp);
        }
    }
    vector<int> p(m);
    rep(i, m) cin >> p[i];
    int ans=0;
    rep(x, 1<<n) {
        vector<int> light(m, 0);
        rep(bit, n) {
            if(((x>>bit)&1)) {
                rep(i, m) if(find(s[i].begin(), s[i].end(), bit)!=s[i].end()) {
                    light[i]++;
                }
            }
        }
        bool flag=true;
        rep(i, m) if(light[i]%2!=p[i]){
            flag=false;
        }
        if(flag) ans++;
    }
    std::cout << ans << std::endl;

    return 0;
}

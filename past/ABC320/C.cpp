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
    int m;
    cin >> m;
    vector<string> s(3);
    rep(i, 3) cin >> s[i];
    vector<int> p={0, 1, 2};
    int ans=INF;
    do {
        char fi, se, th;
        for(int i=0; i<3*m; i++) {
            fi=s[p[0]][i%m];
            for(int j=i+1; j<3*m; j++) {
                se=s[p[1]][j%m];
                for(int k=j+1; k<3*m; k++) {
                    th=s[p[2]][k%m];
                    if(fi==se && se==th) ans=min(ans, k);
                }
            }
        }
    } while(next_permutation(all(p)));
    if(ans==INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
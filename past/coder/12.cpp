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
    vector<vector<bool>> con(n, vector<bool>(n, false));
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        con[a][b]=true;
        con[b][a]=true;
    }
    int ans=0;
    rep(x, 1<<n) {
        bool flag=true;
        rep(i, n) if((x>>i)&1) {
            rep(j, n) if(i!=j && ((x>>j)&1)) { // jも選ばれているならチェック
                if(!con[i][j]) flag=false;
            }
        }
        if(flag) {
            int cnt=__builtin_popcount(x);
            ans=max(ans, cnt);
        }
    }
    
    cout << ans << endl;

    return 0;
}
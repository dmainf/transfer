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
const int MAX=1e6;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    vector<vector<int>> s(n+3, vector<int>(n+3, 0)); 
    rep(i, m) {
        int a, b, x;
        cin >> a >> b >> x;
        a--; b--;
        s[a][b]++;
        s[a][b+1]--;
        s[a+x+1][b]--;
        s[a+x+1][b+x+2]++;
        s[a+x+2][b+1]++;
        s[a+x+2][b+x+2]--;
    }
    for(int i=1; i<n+3; i++){
        for (int j=1; j<n+3; j++){
            s[i][j] += s[i-1][j-1];
        }
    }
    for (int i=1; i<n+3; i++){
        for (int j=0; j<n+3; j++){
            s[i][j] += s[i-1][j];
        }
    }
    for (int i=0; i<n+3; i++){
        for (int j=1; j<n+3; j++){
            s[i][j] += s[i][j-1];
        }
    }
    ll ans=0;
    rep(i, n) rep(j, i+1) if(0<s[i][j]) {
        ans++;
    }
    cout << ans << endl;

    return 0;
}
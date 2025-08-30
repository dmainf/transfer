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
    int n;
    cin >> n;
    vector<int> imos(MAX+1, 0);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        imos[a]++;
        imos[b+1]--;
    }
    rep(i, MAX+1) imos[i]+=imos[i-1];
    int ans=0;
    rep(i, MAX+1) ans=max(ans, imos[i]);
    cout << ans << endl;

    return 0;
}
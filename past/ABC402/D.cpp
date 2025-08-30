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
    int n, m;
    cin >> n >> m;
    map<int, int> cnt;
    ll ans=(ll)m*(m-1)/2;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        int x=(a+b)%n;
        //今追加しようとしているグループに何本平行なのがあるか
        ans-=cnt[x];
        cnt[x]++;
    }
    cout << ans << endl;

    return 0;
}
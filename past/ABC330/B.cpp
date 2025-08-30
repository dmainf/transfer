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
    int n, l, r;
    cin >> n >> l >> r;
    //solve x
    //l<=x<=r
    //about every y={y|l<=y<=r}
    //|x-a|<=|y-a|
    rep(i, n) {
        int a;
        cin >> a;
        int ans;
        if(l<=a && a<r) ans=a;
        if(a<l) ans=l;
        if(r<=a) ans=r;
        cout << ans << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<ll, ll>;
const ll di[]={1,-1,0,0};
const ll dj[]={0,0,1,-1};
const ll INF=1e9;
struct Stone {
    ll index;
    ll num;
    bool operator<(const Stone& other) const {
        return index < other.index;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    vector<ll> x(m), a(m);
    rep(i, m) cin >> x[i], x[i]--;
    rep(i, m) cin >> a[i];
    //3 0 0 2 0
    vector<Stone> stone(m);
    rep(i, m) stone[i]={x[i], a[i]};
    sort(all(stone));
    ll sum=0, sum_index=0;
    rep(i, m) {
        if(sum<stone[i].index) {
            cout << -1 << endl;
            return 0;
        }
        //ただの合計
        sum+=stone[i].num;
        //全石の位置の和
        sum_index+=stone[i].num*stone[i].index;
    }
    //sum←可能かどうかの判定
    //sum_index←最小値を計算
    if(sum!=n) {
        cout << -1 << endl;
        return 0;
    }
    //0~n-1までの合計
    cout << n*(n-1)/2-sum_index << endl;

    return 0;
}
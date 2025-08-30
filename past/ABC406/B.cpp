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
    int n, k;
    cin >> n >> k;
    ll MAX=1;
    rep(i, k) MAX*=10;
    MAX--;
    //k=2
    //MAX=100
    //MAX=99
    ll cul=1;
    rep(i, n) {
        ll a;
        cin >> a;
        //cul*a>MAX
        //cul>MAX/a
        if(cul>(MAX/a)) cul=1;
        else cul*=a;
    }
    cout << cul << endl;

    return 0;
}
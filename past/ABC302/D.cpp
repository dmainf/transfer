#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    ll d;
    cin >> n >> m >> d;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    sort(rall(a));
    sort(rall(b));
    int aoki=0, snuke=0;
    while(aoki<n && snuke<m) {
        if(abs(a[aoki]-b[snuke])<=d) {
            cout << a[aoki]+b[snuke] << endl;
            return 0;
        }
        if(a[aoki]>b[snuke]) aoki++;
        else snuke++;
    }
    cout << -1 << endl;

    return 0;
}
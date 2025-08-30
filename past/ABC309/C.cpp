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
    int n, k;
    cin >> n >> k;
    map<int, ll> kusuri;
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        kusuri[1]+=b;
        kusuri[a+1]-=b;
    }
    //for(auto [day, x]:kusuri) cout << x << " ";
    //cout << endl;
    int pre=0;
    for(auto [day, x]:kusuri) {
        kusuri[day]+=kusuri[pre];
        pre=day;
    }
    //for(auto [day, x]:kusuri) cout << x << " ";
    for(auto [day, x]:kusuri) if(day!=0) {
        if(x<=k) {
            cout << day << endl;
            return 0;
        }
    }

    return 0;
}
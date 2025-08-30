#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl;
#define NO cout<<"No"<<endl;
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, h, x;
    cin >> n >> h >> x;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    int want=x-h;
    rep(i, n) {
        if(want<=p[i]) {
            cout << i+1 << endl;
            return 0;
        }
    }

    return 0;
}
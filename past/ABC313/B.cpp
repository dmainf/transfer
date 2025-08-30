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
    cin >> n >> m;
    vector<int> loser(n, 0);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        loser[b]++;
    }
    int ans=-1;
    rep(i, n) {
        if(loser[i]==0) {
            if(ans!=-1) {
                cout << -1 << endl;
                return 0;
            }
            ans=i+1;
        }
    }
    cout << ans << endl;

    return 0;
}
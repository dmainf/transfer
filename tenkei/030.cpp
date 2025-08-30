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
    cin >> n >> k ;
    vector<int> cnt(1e7, 0);
    for(int i=2; i<=n; i++) {
        if(1<=cnt[i]) continue;
        for(int j=i; j<=n; j+=i) cnt[j]++;
    }
    int ans=0;
    for(int i=2; i<=n; i++) if(k<=cnt[i]) ans++;
    cout << ans << endl;

    return 0;
}
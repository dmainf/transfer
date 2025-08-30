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
    string s;
    cin >> s;
    int n=s.size();
    double ans=0.0;
    rep(l, n) for(int r=l+2; r<n; r++) {
        if(!(s[l]=='t' && s[r]=='t')) continue;
        int x=0;
        for(int i=l; i<=r; i++) {
            if(s[i]=='t') x++;
        }
        ans=max(ans, (double)(x-2)/(r-l+1-2));
    }
    cout << fixed << setprecision(20) << ans << endl;

    return 0;
}
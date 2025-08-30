#include <bits/stdc++.h>
using namespace std;
#define rep(v,n) for(int v=0;v<(n);v++)
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
    int t;
    cin >> t;
    vector<bool> ans;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        s='0'+s;
        vector<bool> dp(1<<n, false);
        dp[0]=true;
        rep(v, 1<<n) if(dp[v]) {
            rep(bit, n) if(!(v&(1<<bit))) { //yet
                int nv=v|(1<<bit); //add 1 medechine
                if(s[nv]=='0') dp[nv]=true;
            }
        }
        ans.push_back(dp[(1<<n)-1]);
    }
    for(bool flag:ans) {
        if(flag) YES;
        else NO;
    }

    return 0;
}
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
    int n, h, m;
    cin >> n >> h >> m;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    //dp[i]：体力がiのときに節約できた魔力の最大値
    vector<int> dp(h+1, -1);
    dp[0]=0;
    int sum=0;
    rep(i, n) {
        sum+=b[i];
        int ai=a[i], bi=b[i];
        for(int j=h; j>=ai; j--) {
            dp[j]=max(dp[j], dp[j-ai]+bi);
        }
        int need=sum-m;
        //魔力だけでクリア可能
        if(need<=0) continue;
        bool flag=false;
        rep(j, h+1) {
            if(need<=dp[j]) {
                //
                flag=true;
                break;
            }
        }
        if(!flag) {
            cout << i << endl;
            return 0;
        }
    }
    cout << n << endl;

    return 0;
}
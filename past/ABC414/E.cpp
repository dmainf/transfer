#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=unsigned long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
#include <atcoder/modint>
using namespace atcoder;
using mint=modint998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    mint ans;
    ll b=2;
    while(b<=n) {
        ll k=n/b;
        if(k==0) break;
        ll b_high=n/k;
        ll b_low=b;
        mint cnt=b_high-b_low+1;
        mint sum_b=(b_low+b_high)*cnt/2;
        mint sum_bm=sum_b-cnt;
        ans+=(k-1)*sum_bm+cnt*n-k*sum_b;
        b=b_high+1;
    }
    cout << ans.val() << endl;

    return 0;
}
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
const ll INF=1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    ll ans=INF;
    //rotate as cut off 
    s+=s;
    //oparation a
    rep(i, n) {
        ll tmp=a*i;
        //oparation b
        rep(j, n/2) {
            int l=i+j;
            int r=(n-1)+i-j;
            if(s[l]!=s[r]) tmp+=b;
        }
        ans=min(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}
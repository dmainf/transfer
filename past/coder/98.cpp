#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>; 
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
const int MOD=1000000007;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    ll ans=1;
    vector<int> s(3, 0); 
    rep(i, n) {
        int a;
        cin >> a;
        int flag=0;
        rep(i, 3) if(s[i]==a) {
            flag++;
        }
        ans=ans*flag%MOD;
        rep(i, 3) if(s[i]==a) {
            s[i]++;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}

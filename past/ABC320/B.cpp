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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n=s.size();
    int ans=1;
    for(int l=0; l<n; l++) {
        for(int len=1; l+len<=n; len++) {
            string u, v;
            //TOYOTA
            if(len%2==0) {
                u=s.substr(l, len/2);
                v=s.substr(l+len/2, len/2);
                reverse(all(v));
            }
            if(len%2==1) {
                u=s.substr(l, len/2);
                v=s.substr(l+len/2+1, len/2);
                reverse(all(v));
            }
            if(u==v) ans=max(ans, len);
        }
    }
    cout << ans << endl;

    return 0;
}
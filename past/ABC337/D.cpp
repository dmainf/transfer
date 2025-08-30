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
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    int ans=INF;
    rep(i, h){
        int len=0, maxlen=0;
        int cnt=0;
        rep(j, w) {
            if(s[i][j]=='x') {
                len=0;
                cnt=0;
            } else {
                len++;
                if(k<=len) {
                    if(s[i][j]=='.') cnt++;
                    if(0<=j-k && s[i][j-k]=='.') cnt--;
                    ans=min(ans, cnt);
                } else {
                    if(s[i][j]=='.') cnt++;
                }
            }
        }
    }    
    rep(j, w){
        int len=0, maxlen=0;
        int cnt=0;
        rep(i, h) {
            if(s[i][j]=='x') {
                len=0;
                cnt=0;
            } else {
                len++;
                if(k<=len) {
                    if(s[i][j]=='.') cnt++;
                    if(0<=i-k && s[i-k][j]=='.') cnt--;
                    ans=min(ans, cnt);
                } else {
                    if(s[i][j]=='.') cnt++;
                }
            }
        }
    }
    if(ans==INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
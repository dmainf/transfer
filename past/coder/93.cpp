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
const int MAX=1e6;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w, K;
    cin >> h >> w >> K;
    vector<vector<int>> c(h, vector<int>(w));
    rep(i, h) rep(j, w) {
        char ch;
        cin >> ch;
        c[i][j]=ch-'0';
    }
    int ans=0;
    rep(H, h) rep(W, w) {
        vector<vector<int>> b=c;
        b[H][W]=INF;
        for (int j = 0; j < w; j++) {
            int pos = h - 1;
            for (int i = h - 1; i >= 0; i--) {
                if(b[i][j] != INF){
                    b[pos][j] = b[i][j];
                    pos--;
                }
            }
            for (int i = pos; i >= 0; i--){
                b[i][j] = INF;
            }
        }
        int score=0;
        int cnt=0;
        bool flag;
        do {
            flag=false;
            rep(i, h) {
                vector<pi> p;
                //RLE
                rep(j, w) {
                    if(b[i][j]!=INF && p.size() && p.back().first==b[i][j])
                        p.back().second++;
                    else p.push_back({b[i][j], 1});
                }
                int now=0;
                rep(j, p.size()) {
                    now+=p[j].second;
                    if(p[j].first!=INF && K<=p[j].second) {
                        score+=(1<<cnt)*(p[j].first*p[j].second);
                        flag=true;
                        for(int k=now-p[j].second; k<now; k++) {
                            b[i][k]=INF;
                        }
                    }
                }
            }
            //faling
            for (int j = 0; j < w; j++){
                int pos = h - 1;
                for (int i = h - 1; i >= 0; i--){
                    if(b[i][j] != INF){
                        b[pos][j] = b[i][j];
                        pos--;
                    }
                }
                for (int i = pos; i >= 0; i--){
                    b[i][j] = INF;
                }
            }
            cnt++;
        } while(flag);
        ans=max(ans, score);
    }
    cout << ans << endl;

    return 0;
}
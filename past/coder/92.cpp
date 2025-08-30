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
    int h;
    while(cin >> h && h!=0) {
        vector<vector<int>> pz(h, vector<int>(5));
        rep(i, h) rep(j, 5) cin >> pz[i][j];
        int ans=0;
        bool flag;
        do {
            flag=false;
            rep(i, h) {
                vector<pi> p;
                //RLE
                rep(j, 5) {
                    if(pz[i][j]!=INF && p.size() && p.back().first==pz[i][j])
                        p.back().second++;
                    else p.push_back({pz[i][j], 1});
                }
                int num=INF, cnt=0;
                int now=0;
                int l=INF, r=INF;
                rep(j, p.size()) {
                    now+=p[j].second;
                    if(3<=p[j].second && cnt<p[j].second) {
                        num=p[j].first;
                        cnt=p[j].second;
                        l=now-cnt, r=now;
                        flag=true;
                    }
                }
                if(num!=INF) for(int j=l; j<r; j++) {
                    pz[i][j]=INF;
                }
                ans+=num*cnt;
            }
            for(int i=h-1; 0<=i; i--) rep(j, 5) {
                if(pz[i][j]!=INF) continue;
                for(int k=i-1; 0<=k; k--) {
                    if(pz[k][j]!=INF) {
                        swap(pz[k][j], pz[i][j]);
                        break;
                    }
                }
            }
        } while(flag);
        std::cout << ans << std::endl;
    }

    return 0;
}
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
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<int>> row(h), col(w);
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        row[x].push_back(i);
        col[y].push_back(i);
    }
    vector<bool> remove(n, false);
    vector<bool> row_done(h, false), col_done(w, false);
    int q;
    cin >> q;
    //O(2*N+Q)
    while(q--) {
        int com, x;
        cin >> com >> x;
        x--;
        if(com==1) {
            if(row_done[x]) cout << 0 << endl;
            else {
                int cnt=0;
                //ここは1回しかやらない
                for(int i:row[x]) {
                    if(remove[i]) continue;
                    cnt++;
                    remove[i]=true;
                }
                row_done[x]=true;
                cout << cnt << endl;
            }
        }
        if(com==2) {
            if(col_done[x]) cout << 0 << endl;
            else {
                int cnt=0;
                //ここは1回しかやらない
                for(int i:col[x]) {
                    if(remove[i]) continue;
                    cnt++;
                    remove[i]=true;
                }
                col_done[x]=true;
                cout << cnt << endl;
            }
        }
    }

    return 0;
}
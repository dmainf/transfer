#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int di[]={-1,0,1,0};
const int dj[]={0,1,0,-1};
const int INF=1e9;
struct Grid {
    int i;
    int j;
    int view;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<bool>> b(h, vector<bool>(w, false));
    Grid v;
    v.i=0; v.j=0; v.view=0;
    rep(i, n) {
        if(!b[v.i][v.j]) {
            b[v.i][v.j]=true;
            v.view++;
            v.view%=4;
            v.i+=di[v.view];
            v.j+=dj[v.view];
        } else {
            b[v.i][v.j]=false;
            v.view--;
            v.view+=4;
            v.view%=4;
            v.i+=di[v.view];
            v.j+=dj[v.view]; 
        }
        v.i+=h; v.j+=w;
        v.i%=h; v.j%=w;
    }
    rep(i, h) {
        rep(j, w) {
            char tmp;
            if(b[i][j]) tmp='#';
            else tmp='.';
            cout << tmp;
        }
        cout << endl;
    }

    return 0;
}
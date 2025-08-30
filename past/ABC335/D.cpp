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
struct Dragon {
    int i;
    int j;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int now=1;
    Dragon dra;
    vector<vector<int>> b(n, vector<int>(n, 0));
    rep(ni, (n-1)/2) {
        dra={ni, ni};
        int step=n-1-2*ni;
        rep(i, step) {
            b[dra.i][dra.j]=now;
            dra.j++;
            now++;
        }
        rep(i, step) {
            b[dra.i][dra.j]=now;
            dra.i++;
            now++;
        }
        rep(i, step) {
            b[dra.i][dra.j]=now;
            dra.j--;
            now++;
        }
        rep(i, step) {
            b[dra.i][dra.j]=now;
            dra.i--;
            now++;
        }
    }
    rep(i, n) rep(j, n) {
        if((n-1)/2==i && (n-1)/2==j) cout << 'T' << " ";
        else cout << b[i][j] << " \n"[j==n-1];
    }

    return 0;
}

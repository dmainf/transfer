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
    int r, x;
    cin >> r >> x;
    if(x==1) {
        if(1600<=r && r<=2999) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    if(x==2) {
        if(1200<=r && r<=2399) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
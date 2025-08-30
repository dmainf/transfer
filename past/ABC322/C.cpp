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
    int n, m;
    cin >> n >> m;
    vector<int> hanabi(n, INF);
    rep(i, m) {
        int a;
        cin >> a;
        a--;
        hanabi[a]=0;
    }
    int cnt=0;
    for(int i=n-1; i>=0; i--) {
        if(hanabi[i]==0) cnt=0;
        else cnt++;
        hanabi[i]=cnt;
    }
    for(auto x:hanabi) cout << x << endl;

    return 0;
}
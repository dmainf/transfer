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
    int n;
    cin >> n;
    vector<int> dp;
    rep(i, n) {
        int c;
        cin >> c;
        auto it=lower_bound(all(dp), c)-dp.begin();
        if(it==dp.size()) dp.push_back(c);
        else dp[it]=c;
    }
    cout << n-dp.size() << endl;

    return 0;
}

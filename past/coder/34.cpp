#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>; 
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> dp(45, 1);
    for(int i=2; i<=44; i++) dp[i]=dp[i-1]+dp[i-2];
    int n;
    cin >> n;
    cout << dp[n] << endl;;

    return 0;
}

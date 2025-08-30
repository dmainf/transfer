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
    int m;
    cin >> m;
    ll sum=0, sum_c=0;
    rep(i, m) {
        ll d, c;
        cin >> d >> c;
        sum+=d*c;
        sum_c+=c;
    }
    cout << (sum-1)/9+(sum_c-1) << endl;

    return 0;
}
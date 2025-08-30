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
    ll n;
    cin >> n;
    if(n==1) cout << 0 << endl;
    n--;
    vector<int> m;
    while(n>0) {
        m.push_back(n%5);
        n/=5;
    }
    reverse(all(m));
    for(auto x:m) cout << x*2;
    cout << endl;

    return 0;
}
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
    string s;
    cin >> s;
    vector<int> cnt(10, 0);
    for(char c:s) cnt[c-'0']++;
    sort(rall(s));
    ll N=stoll(s);
    N=sqrt(N)+1;
    ll ans=0;
    rep(i, N+1) {
        vector<int> tmp(10, 0);
        ll num=(ll)i*i;
        //234   4
        //23    3
        //2     2
        //0
        string t=to_string(num);
        tmp[0]+=n-t.size();
        for(char c:t) tmp[c-'0']++;
        if(tmp==cnt) ans++;
    }
    cout << ans << endl;

    return 0;
}

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
    vector<int> d(n);
    rep(i, n) cin >> d[i];
    int ans=0;
    auto f=[&](string s) -> bool{
        bool flag=true;
        char c=s[0];
        rep(i, s.size()) if(c!=s[i]) {
            flag=false;
        }
        return flag;
    };
    for(int month=1; month<=n; month++) {
        for(int day=1; day<=d[month-1]; day++) {
            string s=to_string(month)+to_string(day);
            if(f(s)) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
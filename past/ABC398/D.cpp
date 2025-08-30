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
    int n, r, c;
    cin >> n >> r >> c;
    string s;
    cin >> s;
    set<pi> st;
    st.insert({0, 0});
    int fire_i=0, fire_j=0;
    int taka_i=r, taka_j=c;
    string ans="";
    rep(i, n) {
        if     (s[i]=='N') { fire_i++; taka_i++; }
        else if(s[i]=='W') { fire_j++; taka_j++; }
        else if(s[i]=='S') { fire_i--; taka_i--; }
        else if(s[i]=='E') { fire_j--; taka_j--; }
        st.insert({fire_i, fire_j});
        if(st.count({taka_i, taka_j})) ans+='1';
        else ans+='0';
    }
    cout << ans << endl;

    return 0;
}
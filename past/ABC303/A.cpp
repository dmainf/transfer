#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    string s, t; cin >> s >> t;
    rep(i, n) {
        if( (s[i]==t[i]) ||
            (s[i]=='1' && t[i]=='l' || s[i]=='l' && t[i]=='1') || 
            (s[i]=='0' && t[i]=='o' || s[i]=='o' && t[i]=='0') ) continue;
        NO;
        return 0;
    }
    YES;

    return 0;
}
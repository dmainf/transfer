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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    vector<int> p(n);
    rep(i, n) p[i]=i;
    do {
        bool flag=true;
        rep(i, n-1) {
            int cnt=0;
            rep(j, m) if(s[p[i+1]][j]!=s[p[i]][j]) {
                cnt++;
            }
            if(cnt!=1) flag=false;
        }
        if(flag) {
            YES;
            return 0;
        }
    } while(next_permutation(all(p)));
    NO;

    return 0;
}
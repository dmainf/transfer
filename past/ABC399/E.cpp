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
    string s, t;
    cin >> s >> t;
    vector<int> m(26, -1);
    rep(i, n) {
        int si=s[i]-'a';
        int ti=t[i]-'a';
        if(m[si]==-1) m[si]=ti;
        else if(m[si]!=ti){
            cout << -1 << "\n";
            return 0;
        }
    }
    int cnt=0;
    vector<int> f(26, -1);
    rep(i, 26) if(m[i]!=-1 && m[i]!=i){
        f[i]=m[i];
        cnt++;
    }
    int cycle=0;
    vector<int> mm(26, 0);
    function<void(int)> dfs=[&](int v) {
        mm[v]=1;
        int nv=f[v];
        if(nv!=-1) {
            if(mm[nv]==0) dfs(nv);
            else if(mm[nv]==1) cycle++;
        }
        mm[v]=2;
    };
    rep(i, 26) if(f[i]!=-1 && mm[i]==0) {
        dfs(i);
    }
    cout << cnt+cycle << endl;

    return 0;
}
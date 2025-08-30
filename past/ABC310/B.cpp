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
    vector<int> p(n);
    vector<vector<int>> f(n);
    rep(i, n) {
        cin >> p[i];
        int c;
        cin >> c;
        rep(j, c) {
            int x;
            cin >> x;
            f[i].push_back(x);
        }
    }
    rep(i, n) rep(j, n) if(i!=j) {
        bool flag=true;
        if(!(p[i]>=p[j])) flag=false;
        //j involved all of i
        for(int x:f[i]) {
            if(!count(all(f[j]), x)) {
                flag=false;
            }
        }
        if(!(p[i]>p[j] || f[j].size()>f[i].size())) flag=false;
        if(flag) {
            YES;
            return 0;
        }
    }
    NO;

    return 0;
}
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ans;
    auto f=[&](auto f, vector<int> a) {
        if(a.size()==n) {
            ans.push_back(a);
            return;
        }
        int l=1;
        if(a.size()>0) l=a.back()+10;
        a.push_back(l);
        while(a.back()+10*(n-a.size())<=m) {
            f(f, a);
            a.back()++;
        }
    };
    f(f, vector<int>());
    cout << ans.size() << endl;
    for(auto a:ans) {
        rep(i, n) cout << a[i] << " \n"[i==a.size()-1];
    }

    return 0;
}
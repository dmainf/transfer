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
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n);
    vector<vector<int>> ans;
    while(q--) {
        int op, t;
        cin >> op >> t;
        if(op==0) {
            int x;
            cin >> x;
            a[t].push_back(x);
        }
        if(op==1) {
            ans.push_back(a[t]);
        }
        if(op==2) {
            if(a[t].empty()) continue;
            a[t].clear();
        }
    }
    for(vector<int> tmp:ans) {
        if(tmp.empty()) cout << endl;
        else {
            rep(i, tmp.size()) {
                if(i>0) cout << " ";
                cout << tmp[i];
            }
            cout << endl;
        }
    }

    return 0;
}
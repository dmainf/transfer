#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(lst) lst.begin(),lst.end()
#define rall(lst) lst.rbegin(),lst.rend()
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
    vector<list<int>> lst(n);
    vector<vector<int>> ans;
    while(q--) {
        int op;
        cin >> op;
        if(op==0) {
            int t, x;
            cin >> t >> x;
            lst[t].push_back(x);
        }
        if(op==1) {
            int t;
            cin >> t;
            ans.push_back(vector<int>(all(lst[t])));
        }
        if(op==2) {
            int s, t;
            cin >> s >> t;
            lst[t].splice(lst[t].end(), lst[s]);
            lst[s].clear();
        }
    }
    for(auto tmp:ans) {
        rep(i, tmp.size()) {
            if(i!=0) cout << " ";
            cout << tmp[i];
        }
        cout << endl;
    }

    return 0;
}
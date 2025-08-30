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
    vector<queue<int>> que(n);
    vector<int> ans;
    while(q--) {
        int op, t;
        cin >> op >> t;
        if(op==0) {
            int x;
            cin >> x;
            que[t].push(x);
        }
        if(op==1) {
            if(!que[t].empty()) {
                ans.push_back(que[t].front());
            }
        }
        if(op==2) {
            if(!que[t].empty()) {
                que[t].pop();
            }
        }
    }
    for(int x:ans) cout << x << endl;

    return 0;
}
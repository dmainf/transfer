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
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    deque<int> dq={1};
    mint s=1;
    vector<int> ans;
    while(q--) {
        int com;
        cin >> com;
        if(com==1) {
            int x;
            cin >> x;
            dq.push_back(x);
            s=s*10+x;
        }
        if(com==2) {
            int front=dq.front();
            dq.pop_front();
            s-=mint(front)*mint(10).pow(dq.size());
        }
        if(com==3) ans.push_back(s.val());
    }
    for(int x:ans) cout << x << endl;

    return 0;
}
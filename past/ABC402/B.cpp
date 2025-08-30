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
    int q;
    cin >> q;
    queue<int> que;
    rep(i, q) {
        int query;
        cin >> query;
        if(query==1) {
            int x;
            cin >> x;
            que.push(x);
        }
        if(query==2) {
            cout << que.front() << endl;
            que.pop();
        }
    }


    return 0;
}
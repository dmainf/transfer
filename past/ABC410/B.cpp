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
    vector<pi> box(n);
    rep(i, n) box[i]={0, i+1};
    vector<int> ans(q);
    rep(qi, q) {
        int x;
        cin >> x;
        if(1<=x) {
            rep(i, n) if(x==box[i].second) {
                box[i].first++;
                break;
            }
            ans[qi]=x;
        }
        if(x==0) {
            sort(all(box));
            box.front().first++;
            ans[qi]=box.front().second;
        }
    }
    for(int x:ans) cout << x << " ";
    cout << endl;

    return 0;
}
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    pq.push(0);
    set<ll> st;
    //いま一番小さいところから埋めていくから必ず小さい数からstに格納される
    while(st.size()<=k) {
        auto val=pq.top();
        pq.pop();
        rep(i, n) {
            if(st.count(val)) continue;
            st.insert(val);
            rep(i, n) pq.push(val+a[i]);
        }
    }
    cout << *st.rbegin() << endl;

    return 0;
}
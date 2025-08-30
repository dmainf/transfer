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
    int n; cin >> n;
    list<int> lst;
    rep(i, n) {
        int a; cin >> a;
        lst.push_back(a);
    }
    auto it=lst.begin();
    while(next(it)!=lst.end()) {
        auto nxt=next(it);
        int l=*it;
        int r=*next(it);
        if(abs(l-r)==1) {
            it=nxt;
        } else if(l<r) {
            for(int x=l+1; x<r; x++) {
                //直前に挿入(=ポインタを変える必要がない)
                lst.insert(nxt, x);
            }
            it=nxt;
        } else if(l>r) {
            for(int x=l-1; r<x; x--) {
                lst.insert(nxt, x);
            }
            it=nxt;
        }
    }
    for(int x:lst) cout << x << " ";
    cout << endl;

    return 0;
}
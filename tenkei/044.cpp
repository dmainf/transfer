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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int cnt=0;
    vector<int> ans;
    while(q--) {
        int op, x, y;
        cin >> op >> x >> y;
        x--; y--;
        if(op==1) swap(a[(x-cnt+n)%n], a[(y-cnt+n)%n]);
        if(op==2) { cnt++; cnt%=n; }
        if(op==3) ans.push_back(a[(x-cnt+n)%n]);
    }
    for(int x:ans) cout << x << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define al(a) a.begin(),a.end()
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
    bitset<18> t;
    rep(i, k) {
        int b; cin >> b;
        t.set(b);
    }
    rep(x, (1<<n)) {
        bitset<18> u(x);
        if((u&t)==t) {
            cout << x << ":";
            rep(bit, 18) if(x&(1<<bit)) {
                cout << " " << bit;
            }
            cout << endl;
        }
    }

    return 0;
}
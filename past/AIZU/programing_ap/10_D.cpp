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
    int n;
    cin >> n;
    vector<bitset<64>> mask(n);
    rep(i, n) {
        int k;
        cin >> k;
        rep(j, k) {
            int b; cin >> b;
            mask[i].set(b);
        }
    }
    int q;
    cin >> q;
    bitset<64> b;
    while(q--) {
        int op, m;
        cin >> op >> m;
        if(op==0) cout << b.test(m) << endl;
        if(op==1) b|=mask[m];
        if(op==2) b&=~mask[m];
        if(op==3) b^=mask[m];
        if(op==4) cout << ((b&mask[m])==mask[m]) << endl;
        if(op==5) cout << (b&mask[m]).any() << endl;
        if(op==6) cout << (b&mask[m]).none() << endl;
        if(op==7) cout << (b&mask[m]).count() << endl;
        if(op==8) cout << (b&mask[m]).to_ullong() << endl;
    }

    return 0;
}
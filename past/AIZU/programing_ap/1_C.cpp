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
    int q;
    cin >> q;
    list<int> lst;
    auto it=lst.end();
    while(q--) {
        int 
        op;
        cin >> op;
        if(op==0) {
            int x;
            cin >> x;
            it=lst.insert(it, x);
        }
        if(op==1) {
            int d;
            cin >> d;
            //if(0<d)
            it=next(it, d);
            //else it=prev(it, -d);
        }
        if(op==2) {
            auto nit=next(it);
            lst.erase(it);
            it=nit;
        }
    }
    for(auto x:lst) cout << x << endl;

    return 0;
}
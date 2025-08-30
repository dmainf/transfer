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
    multimap<string, int> mp;
    while(q--) {
        int op;
        string key;
        cin >> op >> key;
        if(op==0) {
            int x;
            cin >> x;
            mp.insert({key, x});
        }
        if(op==1) {
            auto it=mp.lower_bound(key);
            auto end=mp.upper_bound(key);
            for(; it!=end; it++) {
                auto [y, z]=*it;
                cout << z << endl;
            }
        }
        if(op==2) mp.erase(key);
        if(op==3) {
            string l, r;
            l=key;
            cin >> r;
            auto it=mp.lower_bound(l);
            auto end=mp.upper_bound(r);
            for(; it!=end; it++) {
                auto [y, z]=*it;
                cout << y << " " << z << endl;
            }
        }
    }

    return 0;
}
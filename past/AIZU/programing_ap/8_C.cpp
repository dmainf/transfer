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
    map<string, int> mp;
    while(q--) {
        int op;
        string key;
        cin >> op >> key;
        if(op==0) {
            int x;
            cin >> x;
            mp[key]=x;
        }
        if(op==1) {
            if(mp.count(key)) cout << mp[key] << endl;
            else cout << 0 << endl;
        }
        if(op==2) mp.erase(key);
        if(op==3) {
            string l, r;
            l=key;
            cin >> r;
            auto left=mp.lower_bound(l);
            auto right=mp.upper_bound(r);
            for(auto i=left; i!=right; i++) {
                auto [y, z]=*i;
                cout << y << " " << z << endl;
            }
        }
    }

    return 0;
}
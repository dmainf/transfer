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
//3+5+3+4+6
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    bitset<64> b;
    while(q--) {
        int op;
        cin >> op;
        if(op<4) {
            int i;
            cin >> i;
            switch (op) {
            case 0:
                cout << b[i] << endl;
                break;            
            case 1:
                b.set(i);
                break;
            case 2:
                b.reset(i);
                break;
            case 3:
                b.flip(i);
                break;
            }  
        } else {
            switch (op) {
            case 4:
                cout << b.all() << endl;
                break;            
            case 5:
                cout << b.any() << endl;
                break;
            case 6:
                cout << b.none() << endl;
                break;            
            case 7:
                cout << b.count() << endl;
                break;
            case 8:
                cout << b.to_ulong() << endl;
                break;
            }
        }
    }

    return 0;
}
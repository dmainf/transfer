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
    rep(i, n) a[i]=i+1;
    vector<int> ans;
    ll shift=0;
    while(q--) {
        int com;
        cin >> com;
        if(com==1) {
            int p, x;
            cin >> p >> x; p--;
            a[(p+shift)%n]=x;
        }
        if(com==2) {
            int p;
            cin >> p; p--;
            ans.push_back(a[(p+shift)%n]);
        }
        if(com==3) {
            ll k;
            cin >> k;
            shift+=k;
            shift%=n;
        }
    }
    for(int x:ans) cout << x << endl;

    return 0;
}
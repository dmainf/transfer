#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>; 
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll s;
    cin >> n >> s;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    ll cir=0;
    rep(i, n) cir+=a[i];
    s%=cir;
    vector<int> b=a;
    rep(i, n) b.push_back(a[i]);
    ll tmp=0;
    int r=0;
    rep(l, 2*n) {
        while(r<2*n && tmp<s) {
            tmp+=b[r];
            r++;
        }
        if(s==tmp) {
            cout << "Yes" << endl;
            return 0;
        }
        tmp-=b[l];
    }
    cout << "No" << endl;

    return 0;
}
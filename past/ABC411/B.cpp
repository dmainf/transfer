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
    int n;
    cin >> n;
    vector<int> d(n-1);
    rep(i, n-1) cin >> d[i];
    vector<int> pre(n, 0);
    rep(i, n-1) pre[i+1]=pre[i]+d[i];
    rep(i, n) {
        for(int j=i+1; j<n; j++) {
            cout << pre[j]-pre[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
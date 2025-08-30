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
    vector<string> a(n);
    rep(i, n) cin >> a[i];
    auto b=a;
    //→
    rep(j, n-1) b[0][j+1]=a[0][j];
    //↓
    rep(i, n-1) b[i+1][n-1]=a[i][n-1];
    //←
    for(int j=n-1; j>=1; j--) {
        b[n-1][j-1]=a[n-1][j];
    }
    //↑
    for(int i=n-1; i>=1; i--) {
        b[i-1][0]=a[i][0];
    }
    rep(i, n) cout << b[i] << endl;

    return 0;
}
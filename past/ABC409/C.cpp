#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl;
#define NO cout<<"No"<<endl;
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, l;
    cin >> n >> l;
    vector<int> d(n);
    d[0]=0;
    rep(i, n-1) cin >> d[i+1];
    vector<int> point(l, 0);
    point[0]++;
    int last=0;
    for(int i=1; i<n; i++) {
        last=(last+d[i])%l;
        point[last]++;
    }
    ll ans=0;
    //1 1 1 0 2 0
    if(l%3!=0) ;
    else {
        int len=l/3;
        rep(start, len) {
            int a=start;
            int b=(a+len)%l;
            int c=(b+len)%l;
            ans+=(ll)point[a]*point[b]*point[c];
        }
    }
    cout << ans << endl;

    return 0;
}
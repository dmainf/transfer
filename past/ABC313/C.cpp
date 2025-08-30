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
    vector<int> a(n);
    ll sum=0;
    rep(i, n) {
        cin >> a[i];
        sum+=(ll)a[i];
    }
    //4 7 3 7
    //5 6 3 7
    //5 6 4 6
    //5 6 5 5   3
    ll ave=sum/n;
    vector<int> b(n, ave);
    rep(i, sum-ave*n) b[i]++;
    sort(all(a));
    sort(all(b));
    ll ans=0;
    rep(i, n) ans+=abs(a[i]-b[i]);
    ans/=2;
    cout << ans << endl;

    return 0;
}
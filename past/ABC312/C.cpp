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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    sort(all(a));
    sort(all(b));
    auto check=[&](int x) -> bool {
        //1 2 3 4 5 6 7
        //0 1 2 3 4 5 6
        int uru=upper_bound(all(a), x)-a.begin();
        int kau=b.end()-lower_bound(all(b), x);
        return kau<=uru;
    };
    int low=0;
    int high=1e9+1;
    while(low<=high) {
        int mid=(low+high)/2;
        if(check(mid)) high=mid-1;
        else low=mid+1;
    }
    int ans=low;
    cout << ans << endl;

    return 0;
}
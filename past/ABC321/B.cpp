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
    int n, x;
    cin >> n >> x;
    vector<int> a(n-1);
    rep(i, n-1) cin >> a[i];
    sort(all(a));
    int ans;
    //head
    {
        int sum=0;
        for(int i=0; i<n-2; i++) sum+=a[i];
        if(x<=sum) {
            ans=0;
            cout << ans << endl;
            return 0;
        }
    }
    //middle
    {
        int sum=0;
        for(int i=1; i<n-2; i++) sum+=a[i];
        //x<=sum+ans
        //x-sum<=ans
        //ans=x-sum
        if(a.front()<=x-sum && x-sum<=a.back()) {
            ans=x-sum;
            cout << ans << endl;
            return 0;
        }
    }
    //tail
    {
        int sum=0;
        for(int i=1; i<n-1; i++) sum+=a[i];
        if(x<=sum) {
            ans=a.back();
            cout << ans << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}
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
const int MAX=2*1e5;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    map<int, int> m;
    int zero=0;
    rep(i, n) {
        if(a[i]==0) zero++;
        else {
            int na=1;
            for(int p=2; p*p<=a[i]; p++) {
                int cnt=0;
                while(a[i]%p==0) {
                    a[i]/=p;
                    cnt++;
                }
                cnt%=2;
                if(cnt==1) na*=p;
            }
            if(a[i]!=1) na*=a[i];
            m[na]++;
        }
    }
    ll ans=(ll)zero*(zero-1)/2+(ll)zero*(n-zero);
    for(auto [x,num]:m) ans+=(ll)num*(num-1)/2;
    cout << ans << endl;
    
    return 0;
}
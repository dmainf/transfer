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
    while(true) {
        vector<int> a(4);
        bool flag=true;
        rep(i, 4) {
            cin >> a[i];
            if(a[i]!=0) flag=false;
        }
        if(flag) break;
        while(true) {
            int mn=INF;
            int mn_idx;
            for(int i=3; i>=0; i--) if(a[i]!=0) {
                if(a[i]<mn) {
                    mn=a[i];
                    mn_idx=i;
                }
            }
            rep(i, 4) if(a[i]!=0 && i!=mn_idx) {
                a[i]-=mn;
            }
            int cnt=0;
            rep(i, 4) if(a[i]!=0) {
                cnt++;
            }
            if(cnt==1) break;
        }
        int ans=-1;
        rep(i, 4) ans=max(ans, a[i]);
        cout << ans << endl;
    }

    return 0;
}
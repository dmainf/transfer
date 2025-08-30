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
    while(cin >> n) {
        if(n==0) break;
        vector<int> v(n);
        rep(i, n) cin >> v[i];
        bool flag=false;
        int ans=0;
        rep(i, n-1) {
            if(v[i]>v[i+1] && flag) {
                ans++;
                flag=false;
            }
            if(v[i]<v[i+1]) flag=true;
        }
        cout << ans << endl;
    }

    return 0;
}
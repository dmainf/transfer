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
        vector<int> a(n);
        rep(i, n) cin >> a[i];
        int mn_val=INF, mn_idx;
        rep(i, n) {
            if(abs(a[i]-2023)<mn_val) {
                mn_val=abs(a[i]-2023);
                mn_idx=i+1;
            }
        }
        cout << mn_idx << endl;
    }

    return 0;
}
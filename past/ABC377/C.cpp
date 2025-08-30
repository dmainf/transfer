#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
using ll=long long;
const int dx[]={+2,+1,-1,-2,-2,-1,+1,+2,0};
const int dy[]={+1,+2,+2,+1,-1,-2,-2,-1,0};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> st;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        rep(j, 9) {
            int nx=a+dx[j], ny=b+dy[j];
            if(nx<1 || nx>n || ny<1 || ny>n) continue;
            st.emplace(nx, ny);
        }
    }
    cout << (ll)n*n - st.size() << endl;

    return 0;
}

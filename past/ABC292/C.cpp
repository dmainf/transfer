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
    //n=4
    //3 1 1 1
    //1 3 1 1
    //1 1 3 1
    //1 1 1 3
    //1 2 1 2
    //1 2 2 1
    //2 1 1 2
    //2 1 2 1
    ll ans=0;
    for(int i=1; i<n; i++) {
        //X=A*B Y=C*D
        int X=i, Y=n-i;
        ll x=0, y=0;
        for(int j=1; j*j<=X; j++) {
            if(X%j==0) {
                x++;
                //増えても1パターン
                //X/j==j
                if(X/j!=j) x++;
            }
        }
        for(int j=1; j*j<=Y; j++) {
            if(Y%j==0) {
                y++;
                if(Y/j!=j) y++;
            }
        }
        ans+=x*y;
    }
    cout << ans << endl;

    return 0;
}
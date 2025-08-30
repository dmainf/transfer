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
    vector<string> votes(n);
    rep(i, n) cin >> votes[i];
    vector<int> candi(n, 0);
    rep(j, m) {
        int x=0, y=0;
        rep(i, n) {
            if(votes[i][j]=='0') x++;
            if(votes[i][j]=='1') y++;
        }
        if(x==0 || y==0) {
            rep(i, n) candi[i]++;
        } else if(x<y) {
            rep(i, n) if(votes[i][j]=='0') candi[i]++;
        } else {
            rep(i, n) if(votes[i][j]=='1') candi[i]++;
        }
    }
    int mx=*max_element(all(candi));
    rep(i, n) if(candi[i]==mx) {
        cout << i+1 << " ";
    }
    cout << endl;

    return 0;
}
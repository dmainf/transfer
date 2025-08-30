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
    string s;
    cin >> s;
    //AABBBA
    //ABABBA
    //ABABAB
    ll cntA=0, cntB=0;
    int apos=0, bpos=0;
    rep(i, 2*n) {
        if(s[i]=='A') {
            cntA+=abs(i-apos);
            apos+=2;
        }
    }
    rep(i, 2*n) {
        if(s[i]=='B') {
            cntB+=abs(i-bpos);
            bpos+=2;
        }
    }
    cout << min(cntA, cntB) << endl;

    return 0;
}
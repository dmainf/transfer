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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int plan=m, logo=0;
    int mplan=m, mlogo=0;
    rep(ni, n) {
        if(s[ni]=='0') {
            plan=mplan;
            logo=mlogo;
        } else if(s[ni]=='1') {
            if(0<plan) plan--;
            else if(0<logo) logo--;
            else mlogo++;
        } else if(s[ni]=='2') {
            if(logo==0) mlogo++;
            else logo--;
        }
    }
    cout << mlogo << endl;

    return 0;
}
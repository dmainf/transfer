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
    vector<tuple<int, int, char, ll, string>> t(n);
    rep(i, n) {
        int a, b;
        char c;
        ll d;
        string s;
        cin >> a >> b >> c >> d >> s;
        t[i]={a, b, c, d, s};
    }
    sort(all(t));
    rep(i, n) {
        auto [a,b,c,d,s]=t[i];
        cout 
        << a << " "
        << b << " "
        << c << " "
        << d << " "
        << s << endl;
    }

    return 0;
}
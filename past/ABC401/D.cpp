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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    rep(i, n) {
        if(s[i]=='o') {
            if(0<=i-1) s[i-1]='.';
            if(i+1<=n-1) s[i+1]='.';
        }
    }
    //how many remain 'o'
    int remain=k-count(all(s), 'o');
    //subsquence '?'
    vector<pi> p;
    {
        rep(i, n) if(s[i]=='?') {
            int l=i;
            while(i<n && s[i]=='?') i++;
            int r=i;
            p.push_back({l, r});
        }
    }
    //??
    //.o
    //o.
    //???
    //.o.
    //o.o
    int mx=0;
    for(auto [l, r]:p) mx+=(r-l+1)/2;
    if(remain==0) {
        for(auto [l, r]:p){
            for(int i=l; i<r; i++) s[i]='.';
        }
    }
    if(remain==mx) {
        for(auto [l, r]:p) {
            //if even ??
            //.o
            //o.
            //either ok
            //in conculusion,
            //??
            if((r-l)%2==0) continue;
            //if odd ???
            //o.o
            rep(i, r-l) s[l+i]=i%2==0 ? 'o':'.';
        }
    }
    cout << s << endl;

    return 0;
}
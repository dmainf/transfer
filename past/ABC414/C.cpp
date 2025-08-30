#include <bits/stdc++.h>
using namespace std;
#define rep(x,n) for(int x=0;x<(n);x++)
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
    ll  a, n;
    cin >> a >> n;
    string sn=to_string(n);
    vector<ll> kaibun; 
    for(int len=1; len<=sn.size(); len++) {
        int half=(len+1)/2;
        ll start=1, end=1;
        rep(i, half-1) start*=10;
        end=start*10;
        for(int x=start; x<end; x++) {
            string s=to_string(x);
            string t=s;
            reverse(all(t));
            string tmp=(len%2==0 ? s+t:s+t.substr(1));
            ll v=stoll(tmp);
            if(v>n) break;
            kaibun.push_back(v);
        }
    }
    vector<ll> ans;
    for(ll x:kaibun) {
        string s;
        ll y=x;
        while(0<y) {
            s+=to_string(y%a);
            y/=a;
        }
        string t=s;
        reverse(all(t));
        if(s==t) ans.push_back(x);
    }
    ll ansval=0;
    for(ll x:ans) ansval+=x;
    cout << ansval << endl;

    return 0;
}
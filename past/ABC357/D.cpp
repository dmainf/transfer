#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>; 
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
using mint = modint998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	ll n;
	cin >> n;
    //a=10^d
    mint a=1;
    ll _n=n;
	while(_n){
		a*=10;
		_n/=10;
	}
    mint s=(a.pow(n)-1)/(a-1);
    s*=n;
    cout << s.val() << endl;

    return 0;
}

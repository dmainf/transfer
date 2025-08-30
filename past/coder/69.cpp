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
    int q;
    cin >> q;
    const int MAX=100001;
    vector<bool> prime(MAX, true);
    prime[0]=false;
    prime[1]=false;
    for(int i=2; i*i<=MAX; i++) {
        //2の倍数は全部消えてるからj=2*jじゃなくj=i*iでいい
        if(prime[i]) for(int j=i*i; j<=MAX; j+=i) {
            prime[j]=false;
        }
    }
    vector<int> prefix(MAX, 0);
    for(int i=1; i<=MAX; i++) {
        prefix[i]=prefix[i-1];
        if(prime[i] && prime[(i+1)/2]) prefix[i]++;
    }
    rep(i, q) {
        int l, r;
        cin >> l >> r;
        cout << prefix[r]-prefix[l-1] << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    long long w=a+b;
    vector<long long> d(n);
    rep(i, n) {
        cin >> d[i];
        d[i]%=w;
    }
    rep(i, n) d.push_back(d[i]+w);
    sort(all(d));
    rep(i, d.size()-1) {
        if(d[i+1]-d[i]>b) {
            Yes;
            return 0;
        }
    }
    No;

    return 0;
}

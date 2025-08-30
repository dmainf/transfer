#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define nall(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(nall(s));
    int ans=0;
    do {
        bool flag=true;
        rep(i, n-k+1) {
            string t=s.substr(i, k);
            string rt=t; reverse(nall(rt));
            if(t==rt) flag=false;
        }
        if(flag) ans++;
    } while(next_permutation(nall(s)));
    cout << ans << endl;

    return 0;
}

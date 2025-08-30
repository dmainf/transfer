#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define nsort(a) sort(a.begin(), a.end())
#define rsort(a) sort(a.rbegin(), a.rend())
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> m;
    while(n>0) {
        m.push_back(n%2);
        n/=2;
    }
    int ans=0;
    rep(i, m.size()) {
        if(m[i]==0) ans++;
        else {
            cout << ans << endl;
            return 0;
        }
    }

    return 0;
}

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
    int n, t;
    cin >> n >> t;
    vector<int> raw(n, 0), cul(n, 0), cross(2, 0);
    rep(i, t) {
        int a; cin >> a;
        a--;
        raw[a/n]++;
        cul[a%n]++;
        if(a%(n+1)==0) cross[0]++;
        if(a%(n-1)==0  && a!=0 && a!=n*n-1) cross[1]++;
        if(raw[a/n]==n || cul[a%n]==n || cross[0]==n || cross[1]==n) {
            cout << i+1 << endl;
            return 0;;
        }
    }
    cout << -1 << endl;

    return 0;
}

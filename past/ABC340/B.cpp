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
    int q;
    cin >> q;
    vector<int> a;
    rep(qi, q) {
        int query;
        cin >> query;
        if(query==1) {
            int x;
            cin >> x;
            a.push_back(x);
        } else {
            int k;
            cin >> k;
            cout << a[a.size()-k] << endl;
        }
    }

    return 0;
}

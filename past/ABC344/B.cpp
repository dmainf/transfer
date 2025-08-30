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
    vector<int> a;
    int tmp;
    while(cin >> tmp && tmp != 0) {
        a.push_back(tmp);
    }
    a.push_back(0);
    reverse(a.begin(), a.end());
    rep(i, a.size()) cout << a[i] << endl;

    return 0;
}

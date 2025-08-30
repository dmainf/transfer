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
    int r;
    cin >> r;
    if(1-r>0) {
        cout << 1-r << endl;
        return 0;
    }
    if(100-r>0) {
        cout << 100-r << endl;
        return 0;
    }
    if(200-r>0) {
        cout << 200-r << endl;
        return 0;
    }
    if(300-r>0) {
        cout << 300-r << endl;
        return 0;
    }
}

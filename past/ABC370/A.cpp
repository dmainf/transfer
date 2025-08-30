#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int l, r;
    cin >> l >> r;
    if(l==1) {
        if(r==1) {
            cout << "Invalid" << endl;
        } else {
            cout << "Yes" << endl;
        }
    } else {
        if(r==1) {
            cout << "No" << endl;
        } else {
            cout << "Invalid" << endl;
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a, b;
    int ma=INT_MIN, mb=INT_MIN;
    rep(i, n) {
        cin >> a;
        ma=max(ma, a);
    }
    rep(i, n) {
        cin >> b;
        mb=max(mb, b);
    }
    cout << ma+mb << endl;

    return 0;
}
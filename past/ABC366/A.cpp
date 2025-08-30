#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t, a;
    cin >> n >> t >> a;
    if(t>(a+n-t-a) || a>(t+n-a-t)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}

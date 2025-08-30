#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
using ll=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<bool> taro(n, false);
    rep(i, m) {
        int a; char b;
        cin >> a >> b;
        a--;
        if(b=='M' && taro[a]==false) {
            taro[a]=true;
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
using ll=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> m;
    int n=0;
    vector<int> a;
    for(int i=0;;i++) {
        for(int j=0;;j++) {
            if(m<pow(3, j)) {
                a.push_back(j-1);
                m-=pow(3, j-1);
                break;
            }
        }
        if(m==0) {
            n=i+1;
            break;
        }
    }
    cout << n << endl;
    rep(i, n) cout << a[i] << " \n"[i==n-1];

    return 0;
}

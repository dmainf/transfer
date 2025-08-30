#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<long long> A(109);
    cin >> n;
    rep(i, n) cin >> A[i];

    if (n==2) {
        cout << "Yes\n";
        return 0;
    }
    rep(i, n-1) {
        if(i==0) continue;
        if(A[i]*A[i]!=A[i-1]*A[i+1]) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";

	return 0;
}
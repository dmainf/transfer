#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X;
    cin >> X;
    for(int i=2;;i++) {
        X/=i;
        if(X==1) {
            cout << i << endl;
            break;
        }
    }


	return 0;
}
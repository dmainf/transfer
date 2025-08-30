#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=1; i<=n; i++)
int main(){
    int x;
    cin >> x;
    int ans=0;
    rep(i, 9) {
        rep(j, 9) {
            if(i*j!=x) ans+=i*j;
        }
    }
    cout << ans << endl;
	return 0;
}

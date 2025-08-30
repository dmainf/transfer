#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long a[500009];
    cin >> n;
    rep(i, n) cin >> a[i];
    
    long long ans=0;
    int j=0;
    rep(i, n) {
        while (j<n && 2*a[i]>a[j]) j++;
        ans+= n-j;
    }
    cout << ans << endl;

	return 0;
}

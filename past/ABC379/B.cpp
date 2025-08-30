#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
using ll=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; string s;
    cin >> n >> k;
    cin >> s;
    int count=0;
    int ans=0;
    rep(i, n) {
        if(s[i]=='X') {
            count=0;
            continue;
        }
        count++;
        if(count==k) {
            ans++;
            count=0;
        }
    }
    cout << ans << endl;
    
    return 0;
}
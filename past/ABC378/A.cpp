#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
using ll=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a(4);
    rep(i, 4) cin >> a[i];
    int ans=count(a.begin(), a.end(), 1)/2+count(a.begin(), a.end(), 2)/2+count(a.begin(), a.end(), 3)/2+count(a.begin(), a.end(), 4)/2;
    cout << ans<< endl;
    return 0;
}
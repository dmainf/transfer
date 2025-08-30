#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> q(n);
    rep(i, n) cin >> q[i];
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    auto f=[&](int x) -> bool {
        rep(i, x+1) {
            int ai=i;
            int bi=x-i;
            bool check=true;
            rep(j, n) if(!(a[j]*(ll)ai+b[j]*(ll)bi<=(ll)q[j])) {
                check=false;
            }
            if(check) return true;
        }
        return false;
    };
    int low=0, high=2e6;
    while(low<=high) {
        int mid=(low+high)/2;
        if(f(mid)) low=mid+1;
        else high=mid-1;
    }
    cout << high << endl;

    return 0;
}
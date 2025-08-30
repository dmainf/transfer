#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int x, y;
    double ans=0.0;
    int pastx=0, pasty=0;
    rep(i, n) {
        cin >> x >> y;
        ans+= sqrt(pow(x-pastx, 2)+pow(y-pasty, 2));
        pastx=x; pasty=y;
    }
    ans+=sqrt(pow(pastx, 2)+pow(pasty, 2));
    printf("%.20f\n", ans);

    return 0;
}

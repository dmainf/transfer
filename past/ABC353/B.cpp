#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int tmp=k;
    int ans=0;
    rep(i, n) {
        int a;
        cin >> a;
        if(tmp>=a) tmp-=a;
        else {
            ans++;
            tmp=k-a;
        }
    }
    cout << ans+1 << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
int n, k;
vector<int> r(8);
void f(vector<int> a) {
    if(a.size()==n) {
        int tmp=0;
        rep(i, n) tmp+=a[i];
        if(tmp%k==0) rep(i, n) {
            cout << a[i] << " \n"[i==n-1];
        }
        return;
    }
    int now=a.size();
    for(int i=1; i<=r[now]; i++) {
        vector<int> na=a;
        na.push_back(i);
        f(na);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    rep(i, n) cin >> r[i];
    f(vector<int>(0));
    return 0;
}

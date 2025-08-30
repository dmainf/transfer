#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int h;
    ll t=0;
    rep(i, n) {
        cin >> h;
        t+=3*(h/5);
        h%=5;
        while(h>0) {
            t++;
            if(t%3!=0) h--;
            else h-=3;
        }
    }
    cout << t << endl;
    return 0;
}
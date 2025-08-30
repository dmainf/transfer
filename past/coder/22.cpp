#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double p;
    cin >> p;
    auto f=[&](double x) -> double {
        return p/pow(2.0, x/1.5)+x;
    };
    double left=0.0, right=p;
    double ans;
    while(right-left>=1e-8) {
        double c1=(left*2+right)/3;
        double c2=(left+2*right)/3;
        double d=right-left;
        if(f(c1)>f(c2)) {
            left=left+d/3;
            ans=right;
        } else {
            right=right-d/3;
            ans=left;
        }
    }
    cout  << fixed << setprecision(10) << f((left+right)/2) << endl;

    return 0;
}

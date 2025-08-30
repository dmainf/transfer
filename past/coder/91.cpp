#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>; 
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
const int MAX=1e6;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, x;
    cin >> a >> b >> x;
    if(x<=a*a*b/2) cout << fixed << setprecision(10) << atan(a*b*b/2.0/x)*180.0/M_PI << endl;
    else cout << fixed << setprecision(10) << atan(2.0*(a*a*b-x)/a/a/a)*180.0/M_PI << endl;

    return 0;
}

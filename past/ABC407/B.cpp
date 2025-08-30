#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl;
#define NO cout<<"No"<<endl;
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y;
    cin >> x >> y;
    int cnt=0;
    for(int i=1; i<=6; i++) for(int j=1; j<=6; j++) {
        if(x<=i+j || y<=abs(i-j)) cnt++;
    }
    cout << fixed << setprecision(20) << (double)cnt/36 << endl;

    return 0;
}